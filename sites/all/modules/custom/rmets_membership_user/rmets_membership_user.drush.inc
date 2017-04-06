<?php

use Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper;

/**
 * Implements hook_drush_command().
 */
function rmets_membership_user_drush_command() {
  $commands = array();

  $commands['rmets-membership-user-import-declaration-dates'] = array(
    //'hidden' => TRUE,
    //'aliases' => array('myshortalias1', 'myshortalias2'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    //'bootstrap_errors' => array(),
    //'topics' => array(),
    'description' => dt('Some helpful description.'),
    'required-arguments' => TRUE,
    'arguments' => array(
      //'my_machine_name' => dt('My description'),
    ),
    //'strict-option-handling' => TRUE,
    'allow-additional-options' => FALSE,
    'examples' => array(
      'drush rmets_membership_user_import_declaration_dates' => dt('Description of what this command will do.'),
    ),
    //'path' => 'Directory name',
    //'commandfile' => 'Filename',
    //'topic' => TRUE,
    //'command-hook' => '',
    'callback' => 'drush_rmets_membership_user_import_declaration_dates',
    //'callback arguments' => array(),
    //'primary function' => TRUE,
    //'invoke hooks' => FALSE,
    //'handle-remote-commands' => TRUE,
    //'scope' => 'site', // site|system|project
    //'core' => array('6|6+', '7|7+', '8|8+'),
    //'drupal dependencies' => array(),
    //'drush dependencies' => array(),
    //'engines' => array(
    //  'outputformat' => array(
    //    'default' => 'table',
    //    'formatted-filter' => '@todo',
    //    'pipe-format' => 'list',
    //    'pipe-filter' => '@todo',
    //    'output-data-type' => 'format-table',
    //    'field-labels' => array(),
    //  ),
    //),
  );

  //hook_drush_command_item

  return $commands;
}

/**
 * Implements drush_COMMAND().
 */
function drush_rmets_membership_user_import_declaration_dates() {
  $file = fopen('/tmp/membership_numbers.txt', 'r');
  while ($data = fgetcsv($file, 1000, ',')) {
    $user_wrapper = UserWrapper::getObjectByMembershipNumber($data[0]);
    if ($user_wrapper && $user_wrapper->getIdentifier()) {
      print $data[0] . ' ' . $user_wrapper->getIdentifier() . "\n";
      continue;
    }
    else {
      $user_wrapper = UserWrapper::getObjectByEmail($data[1]);
      if ($user_wrapper && $user_wrapper->getIdentifier()) {
        print $data[0] . ' ' . $user_wrapper->getIdentifier() . " -- Email\n";
        continue;
      }
    }
    print $data[0] . ' ' . $data[1] . "~~~\n";
  }
  fclose($file);
}

