<?php
/**
 * @file
 * rmets_cpd_records_features.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function rmets_cpd_records_features_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cpd_objective|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cpd_objective';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cpd_objective|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cpd_record|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cpd_record';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cpd_record|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function rmets_cpd_records_features_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_add_cpd_record_link';
  $ds_field->label = 'Event Add CPD Record Link';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['event_add_cpd_record_link'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function rmets_cpd_records_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cpd_objective|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cpd_objective';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_web_references_link',
        2 => 'field_planned_completion_date',
        3 => 'field_date_completed',
        4 => 'field_file_attachment',
        5 => 'links',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_web_references_link' => 'ds_content',
      'field_planned_completion_date' => 'ds_content',
      'field_date_completed' => 'ds_content',
      'field_file_attachment' => 'ds_content',
      'links' => 'ds_content',
    ),
    'classes' => array(),
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|cpd_objective|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cpd_record|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cpd_record';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_cpd_type',
        2 => 'field_areas_of_meterology',
        3 => 'field_areas_of_competency',
        4 => 'field_date_completed',
        5 => 'field_objective_references',
        6 => 'group_objectives',
        7 => 'field_web_references_link',
        8 => 'field_file_attachment',
        9 => 'links',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_cpd_type' => 'ds_content',
      'field_areas_of_meterology' => 'ds_content',
      'field_areas_of_competency' => 'ds_content',
      'field_date_completed' => 'ds_content',
      'field_objective_references' => 'ds_content',
      'group_objectives' => 'ds_content',
      'field_web_references_link' => 'ds_content',
      'field_file_attachment' => 'ds_content',
      'links' => 'ds_content',
    ),
    'classes' => array(),
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|cpd_record|full'] = $ds_layout;

  return $export;
}
