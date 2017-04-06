<?php
/**
 * @file
 * rmets_cpd_accreditation_features.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function rmets_cpd_accreditation_features_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cpd_accreditation_application|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cpd_accreditation_application';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'cpd_accreditation_pay_online' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
    ),
    'work_experience' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cpd_accreditation_application|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function rmets_cpd_accreditation_features_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cpd_accreditation_pay_online';
  $ds_field->label = 'CPD Accreditation Pay Online';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['cpd_accreditation_pay_online'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function rmets_cpd_accreditation_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cpd_accreditation_application|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cpd_accreditation_application';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'cpd_accreditation_pay_online',
        1 => 'field_qualifying_work_experience',
        2 => 'field_type_of_accreditation',
        3 => 'field_status',
        4 => 'field_areas_of_specialism',
        5 => 'group_tabs',
        6 => 'field_membership_number',
        7 => 'work_experience',
        8 => 'field_a1_a3',
        9 => 'field_full_name',
        10 => 'field_previous_name',
        11 => 'links',
        12 => 'field_qualifications',
        13 => 'field_b1_b4',
        14 => 'field_job_title_position',
        15 => 'field_file_attachment',
        16 => 'field_employer_name',
        17 => 'field_c1_c3',
        18 => 'field_evidence_comms_skills',
        19 => 'field_contact_address',
        20 => 'field_public_telephone',
        21 => 'field_d1_d4',
        22 => 'field_e1_e3',
        23 => 'field_email',
        24 => 'field_references',
        25 => 'field_position',
        26 => 'field_contact_email',
        27 => 'field_declaration_email',
        28 => 'field_records',
        29 => 'field_agree_published_online',
        30 => 'field_declare_truth_conduct',
        31 => 'field_professional_review',
        32 => 'group_identification',
        33 => 'group_education_prof_training',
        34 => 'group_specialisms',
        35 => 'group_records',
        36 => 'group_relevant_work_experience',
        37 => 'group_profession_review',
        38 => 'group_evidence_core_competencies',
        39 => 'group_references',
        40 => 'group_declaration',
      ),
    ),
    'fields' => array(
      'cpd_accreditation_pay_online' => 'ds_content',
      'field_qualifying_work_experience' => 'ds_content',
      'field_type_of_accreditation' => 'ds_content',
      'field_status' => 'ds_content',
      'field_areas_of_specialism' => 'ds_content',
      'group_tabs' => 'ds_content',
      'field_membership_number' => 'ds_content',
      'work_experience' => 'ds_content',
      'field_a1_a3' => 'ds_content',
      'field_full_name' => 'ds_content',
      'field_previous_name' => 'ds_content',
      'links' => 'ds_content',
      'field_qualifications' => 'ds_content',
      'field_b1_b4' => 'ds_content',
      'field_job_title_position' => 'ds_content',
      'field_file_attachment' => 'ds_content',
      'field_employer_name' => 'ds_content',
      'field_c1_c3' => 'ds_content',
      'field_evidence_comms_skills' => 'ds_content',
      'field_contact_address' => 'ds_content',
      'field_public_telephone' => 'ds_content',
      'field_d1_d4' => 'ds_content',
      'field_e1_e3' => 'ds_content',
      'field_email' => 'ds_content',
      'field_references' => 'ds_content',
      'field_position' => 'ds_content',
      'field_contact_email' => 'ds_content',
      'field_declaration_email' => 'ds_content',
      'field_records' => 'ds_content',
      'field_agree_published_online' => 'ds_content',
      'field_declare_truth_conduct' => 'ds_content',
      'field_professional_review' => 'ds_content',
      'group_identification' => 'ds_content',
      'group_education_prof_training' => 'ds_content',
      'group_specialisms' => 'ds_content',
      'group_records' => 'ds_content',
      'group_relevant_work_experience' => 'ds_content',
      'group_profession_review' => 'ds_content',
      'group_evidence_core_competencies' => 'ds_content',
      'group_references' => 'ds_content',
      'group_declaration' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|cpd_accreditation_application|default'] = $ds_layout;

  return $export;
}
