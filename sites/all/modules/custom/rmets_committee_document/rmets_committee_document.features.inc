<?php
/**
 * @file
 * rmets_committee_document.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rmets_committee_document_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rmets_committee_document_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rmets_committee_document_node_info() {
  $items = array(
    'committee_document' => array(
      'name' => t('Committee Document'),
      'base' => 'node_content',
      'description' => t('A committee document from a committee meeting'),
      'has_title' => '1',
      'title_label' => t('Document title'),
      'help' => '',
    ),
    'committee_meeting' => array(
      'name' => t('Committee Meeting'),
      'base' => 'node_content',
      'description' => t('A committee meeting may contain a number of uploaded documents'),
      'has_title' => '1',
      'title_label' => t('Meeting name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
