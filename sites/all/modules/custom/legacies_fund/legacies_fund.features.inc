<?php
/**
 * @file
 * legacies_fund.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function legacies_fund_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function legacies_fund_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function legacies_fund_node_info() {
  $items = array(
    'legacies_fund' => array(
      'name' => t('Legacies Fund'),
      'base' => 'node_content',
      'description' => t('Content type for Legacies Fund reports'),
      'has_title' => '1',
      'title_label' => t('Legacies Fund'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
