<?php
/**
 * @file
 * rmets_cpd_reviews_features.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function rmets_cpd_reviews_features_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cpd_report_review|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cpd_report_review';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cpd_report_review|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function rmets_cpd_reviews_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cpd_report_review|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cpd_report_review';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_status',
        1 => 'group_tabs',
        2 => 'group_identification',
        3 => 'field_forenames',
        4 => 'field_last_name',
        5 => 'links',
        6 => 'group_records',
        7 => 'group_evidence_core_competencies',
        8 => 'field_previous_name',
        9 => 'field_email',
        10 => 'field_a1_a3',
        11 => 'group_work_experience',
        12 => 'group_declaration_tabs',
        13 => 'field_b1_b4',
        14 => 'field_period_review_from',
        15 => 'field_period_review_to',
        16 => 'field_c1_c3',
        17 => 'field_referee',
        18 => 'field_d1_d4',
        19 => 'field_declare_truth_conduct',
        20 => 'field_qualifying_work_experience',
        21 => 'field_e1_e3',
        22 => 'field_records',
      ),
    ),
    'fields' => array(
      'field_status' => 'ds_content',
      'group_tabs' => 'ds_content',
      'group_identification' => 'ds_content',
      'field_forenames' => 'ds_content',
      'field_last_name' => 'ds_content',
      'links' => 'ds_content',
      'group_records' => 'ds_content',
      'group_evidence_core_competencies' => 'ds_content',
      'field_previous_name' => 'ds_content',
      'field_email' => 'ds_content',
      'field_a1_a3' => 'ds_content',
      'group_work_experience' => 'ds_content',
      'group_declaration_tabs' => 'ds_content',
      'field_b1_b4' => 'ds_content',
      'field_period_review_from' => 'ds_content',
      'field_period_review_to' => 'ds_content',
      'field_c1_c3' => 'ds_content',
      'field_referee' => 'ds_content',
      'field_d1_d4' => 'ds_content',
      'field_declare_truth_conduct' => 'ds_content',
      'field_qualifying_work_experience' => 'ds_content',
      'field_e1_e3' => 'ds_content',
      'field_records' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|cpd_report_review|default'] = $ds_layout;

  return $export;
}
