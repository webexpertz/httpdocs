<?php

/**
 * @file
 * Drush import scripts.
 */

/**
 * Implements hook_drush_command().
 */
function import_drush_command() {

  $imports = array_keys(_import_get_info());

  if (empty($imports)) {
    // No import functions so this command is redundant.
    return;
  }

  $item = array(
    'description' => 'Import content into the current site. Content import options are: ' . implode(', ', $imports),
    'examples' => array(
      'drush import opt' => 'Imports all content of type opt (replace opt with a real option)',
      'drush import opt --overwrite' => 'Imports all content of type opt, when duplicates are found based on title it overwrites it',
      'drush import opt --simulate' => 'Only simulates the import of the content of type opt',
      'drush import opt --ignoreexisting' => 'Imports all data found and doesnt check if they already exist based on title. Only use this the first time',
    ),
    'arguments' => array(
      'opt' => 'An content import type. The options are: ' . implode(', ', $imports),
    ),
    'options' => array(
      'overwrite' => 'Overwrite existing nodes. Defaut behaviour is to leave existing nodes alone',
      'ignoreexisting' => 'Create new nodes for everything found, this stops the check for existing nodes and shoud be set the first time this is run only',
      'limit' => 'Only import or update this many nodes then stop. This does not count skipped nodes.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
  );

  return array('import' => $item);
}

/**
 * Get all the imports declared by all the hook_drush_import_info hooks.
 */
function _import_get_info() {
  $info = array();
  foreach (drush_commandfile_list() as $commandfile => $path) {
    if (drush_command_hook($commandfile, 'drush_import_info')) {
      $function = $commandfile . '_drush_import_info';
      $results = $function();
      foreach ($results as $id => $result) {
        $info[$id] = $result;
      }
    }
  }
  return $info;
}

/**
 * Implements hook_COMMAND().
 */
function drush_import($option) {
  $info = _import_get_info();
  if (!array_key_exists($option, $info)) {
    drush_set_error($option . ' is not a valid import choice. Valid choices are: ', implode(', ', array_keys($info)));
    return;
  }
  _generic_node_importer($option, $info[$option]['key']);
}

/**
 * A generic callback function for the migration of nodes.
 * This looks after the user prompts, messages, simulation and
 * audit logs.
 * To use this you must define a callback function called _name_get_data()
 * which returns an array of raw record objects. Each of these will
 * later become a node.
 * The second callback function you must define is called
 * _name_save_node($record, $existing_node) where you turn a record into
 * a node object and save it. The existing_node parameter here is if
 * this record has previously been migrated it will be provided.
 * In your callback functions replace the word 'name' with your namespace.
 *
 * @param string $name
 *   The name of the import (namespace). This is what you also use in the
 *   names of your callback functions above.
 * @param string $key
 *   The unique field on the record objects returned by _name_get_data()
 *   which uniquely identifies each record.
 */
function _generic_node_importer($name, $key) {
  if (drush_get_option('simulate', FALSE) || drush_get_option('s', FALSE)) {
    drush_print('In simulate mode. Anything written to the db will be rolledback.');
  }

  if (!drush_confirm('Are you sure you want to proceed with the import?')) {
    return;
  }

  $results_callback = "{$name}_get_data";
  $save_node_callback = "{$name}_save_node";

  if (!is_callable($results_callback)) {
    drush_set_error('Could not find the get data function ' . $results_callback);
    return;
  }

  if (!is_callable($save_node_callback)) {
    drush_set_error('Could not find the save node function ' . $save_node_callback);
    return;
  }

  drush_print('IMPORT BEGINS ...');

  // The audit saves the relationship between old to new nodeids.
  $audit = variable_get($name . '_import-audit', array());

  try {
    $results = $results_callback();
  }
  catch (Exception $e) {
    drush_set_error('Unable to get data for ' . $name . ' as ' . $e->getMessage());
    return;
  }

  $count = 0;
  $limit = drush_get_option('limit', FALSE);

  try {

    // Use transactions so we can rollback on errors.
    $txn = db_transaction();

    foreach ($results as $record) {
      // See if the node is already there, we will
      // overwrite it only if --overwrite is set.
      $node = NULL;
      $action = 'insert';
      if (is_null(drush_get_option('ignoreexisting', NULL)) && array_key_exists($record->$key, $audit)) {
        $nid = $audit[$record->$key];
        if (is_null(drush_get_option('overwrite', NULL))) {
          drush_print("skipping update of record with $key of {$record->$key} as this is node nid {$nid}");
          continue;
        }
        $node = node_load($nid);
        $action  = 'update';
      }

      // Turn the $node array into an object for saving with node_save
      $node = $save_node_callback($record, $node);

      if ($node) {
        $count++;
        drush_print($action . ' node ' . $node->nid . ': ' . $node->title);
        $audit[$record->$key] = $node->nid;
        variable_set($name . '_import-audit', $audit);
      }

      if ($limit !== FALSE && $count >= $limit) {
        // Limit has been reached, stop now.
        break;
      }
    }
  }
  catch (Exception $e) {
    // Something went wrong somewhere, so roll back now.
    $txn->rollback();
    // Log the exception to watchdog.
    watchdog_exception('type', $e);
    return;
  }

  if (drush_get_option('simulate', FALSE) || drush_get_option('s', FALSE)) {
    // Simulate mode - revert all changes.
    $txn->rollback();
  }

  // $txn goes out of scope here.  Unless the transaction was rolled back, it
  // gets automatically committed here.
  drush_print('Imported ' . $count . ' nodes');
  drush_print('... IMPORT ENDS');
}

/**
 * Copy a file into Drupal via URL.
 *
 * @param string $url
 *   The URL to the file.
 * @param string $uri
 *   The Druapl URI of the file.
 *   e.g. public://images/folder/file.jpg
 *
 * @return object
 *   Drupal file object or FALSE on fail
 */
function _curl_copy_remote($url, $uri) {
  // Create a new CURL resource.
  $ch = curl_init();

  // Set URL and other appropriate options.
  curl_setopt($ch, CURLOPT_URL, $url);
  curl_setopt($ch, CURLOPT_HEADER, FALSE);
  curl_setopt($ch, CURLOPT_BINARYTRANSFER, TRUE);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);

  set_time_limit(300);
  curl_setopt($ch, CURLOPT_TIMEOUT, 300);

  // Grab file from URL.
  $data = curl_exec($ch);

  $result = file_save_data($data, $uri, FILE_EXISTS_REPLACE);
  if ($result === FALSE) {
    drush_print('file_save_data failed on ' . $uri);
  }

  curl_close($ch);

  return $result;
}
