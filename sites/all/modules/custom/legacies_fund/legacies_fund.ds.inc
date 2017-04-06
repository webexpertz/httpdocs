<?php
/**
 * @file
 * legacies_fund.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function legacies_fund_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|legacies_fund|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'legacies_fund';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_first_name' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Recipient',
        'lb-el' => 'h3',
        'lb-cl' => 'field-inline-element',
        'fis' => TRUE,
        'fis-el' => 'h3',
        'fis-cl' => 'spaced-text label-inline',
      ),
    ),
    'field_last_name' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'h3',
        'ow-cl' => 'label-inline spaced-text',
      ),
    ),
    'field_legacy_fund_date' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'h3',
        'ow-cl' => '',
      ),
    ),
  );
  $export['node|legacies_fund|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function legacies_fund_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|legacies_fund|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'legacies_fund';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_legacy_fund_date',
        1 => 'field_first_name',
        2 => 'field_last_name',
        3 => 'field_image',
        4 => 'body',
      ),
    ),
    'fields' => array(
      'field_legacy_fund_date' => 'ds_content',
      'field_first_name' => 'ds_content',
      'field_last_name' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|legacies_fund|default'] = $ds_layout;

  return $export;
}
