<?php
/**
 * @file
 * rmets_cpd_accreditation_features.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function rmets_cpd_accreditation_features_commerce_product_default_types() {
  $items = array(
    'rmets_accreditation_application' => array(
      'type' => 'rmets_accreditation_application',
      'name' => 'RMetS Accreditation Application',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function rmets_cpd_accreditation_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rmets_cpd_accreditation_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rmets_cpd_accreditation_features_node_info() {
  $items = array(
    'cpd_accreditation_application' => array(
      'name' => t('CPD Accreditation Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
