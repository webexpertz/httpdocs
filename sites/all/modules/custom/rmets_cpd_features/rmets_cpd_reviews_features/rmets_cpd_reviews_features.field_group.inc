<?php
/**
 * @file
 * rmets_cpd_reviews_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rmets_cpd_reviews_features_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_administration|node|cpd_report_review|form';
  $field_group->group_name = 'group_administration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Administration',
    'weight' => '14',
    'children' => array(
      0 => 'field_reviews',
      1 => 'field_status',
      2 => 'field_next_cpd_submission_date',
      3 => 'field_notes',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Administration',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-administration field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_administration|node|cpd_report_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_declaration_tabs|node|cpd_report_review|default';
  $field_group->group_name = 'group_declaration_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Declaration',
    'weight' => '5',
    'children' => array(
      0 => 'field_declare_truth_conduct',
      1 => 'field_referee',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-declaration-tabs field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_declaration_tabs|node|cpd_report_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_declaration|node|cpd_report_review|form';
  $field_group->group_name = 'group_declaration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Declaration',
    'weight' => '12',
    'children' => array(
      0 => 'field_declare_truth_conduct',
      1 => 'field_referee',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Declaration',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-declaration field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_declaration|node|cpd_report_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_declaration|node|cpd_report_review|print';
  $field_group->group_name = 'group_declaration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Declaration',
    'weight' => '5',
    'children' => array(
      0 => 'field_declare_truth_conduct',
      1 => 'field_referee',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-declaration field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_declaration|node|cpd_report_review|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evidence_core_competencies|node|cpd_report_review|default';
  $field_group->group_name = 'group_evidence_core_competencies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Evidence of Core Competencies',
    'weight' => '3',
    'children' => array(
      0 => 'field_a1_a3',
      1 => 'field_b1_b4',
      2 => 'field_c1_c3',
      3 => 'field_d1_d4',
      4 => 'field_e1_e3',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-evidence-core-competencies field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_evidence_core_competencies|node|cpd_report_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evidence_core_competencies|node|cpd_report_review|form';
  $field_group->group_name = 'group_evidence_core_competencies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Evidence of Core Competencies',
    'weight' => '11',
    'children' => array(
      0 => 'field_a1_a3',
      1 => 'field_b1_b4',
      2 => 'field_c1_c3',
      3 => 'field_d1_d4',
      4 => 'field_e1_e3',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Evidence of Core Competencies',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-evidence-core-competencies field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_evidence_core_competencies|node|cpd_report_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evidence_core_competencies|node|cpd_report_review|print';
  $field_group->group_name = 'group_evidence_core_competencies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Evidence of Core Competencies',
    'weight' => '3',
    'children' => array(
      0 => 'field_a1_a3',
      1 => 'field_b1_b4',
      2 => 'field_c1_c3',
      3 => 'field_d1_d4',
      4 => 'field_e1_e3',
      5 => 'field_professional_review',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-evidence-core-competencies field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_evidence_core_competencies|node|cpd_report_review|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identification|node|cpd_report_review|default';
  $field_group->group_name = 'group_identification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '1',
    'children' => array(
      0 => 'field_email',
      1 => 'field_forenames',
      2 => 'field_last_name',
      3 => 'field_period_review_from',
      4 => 'field_period_review_to',
      5 => 'field_previous_name',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-identification field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_identification|node|cpd_report_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identification|node|cpd_report_review|form';
  $field_group->group_name = 'group_identification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '8',
    'children' => array(
      0 => 'field_email',
      1 => 'field_forenames',
      2 => 'field_last_name',
      3 => 'field_period_review_from',
      4 => 'field_period_review_to',
      5 => 'field_user',
      6 => 'field_previous_name',
      7 => 'field_crm_accreditation_type',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Identification',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-identification field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_identification|node|cpd_report_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identification|node|cpd_report_review|print';
  $field_group->group_name = 'group_identification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '1',
    'children' => array(
      0 => 'field_email',
      1 => 'field_forenames',
      2 => 'field_last_name',
      3 => 'field_period_review_from',
      4 => 'field_period_review_to',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Identification',
      'instance_settings' => array(
        'classes' => 'group-identification field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_identification|node|cpd_report_review|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_records|node|cpd_report_review|default';
  $field_group->group_name = 'group_records';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Records',
    'weight' => '2',
    'children' => array(
      0 => 'field_records',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-records field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_records|node|cpd_report_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_records|node|cpd_report_review|form';
  $field_group->group_name = 'group_records';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'CPD Records',
    'weight' => '9',
    'children' => array(
      0 => 'field_records',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'CPD Records',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-records field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_records|node|cpd_report_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_records|node|cpd_report_review|print';
  $field_group->group_name = 'group_records';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Records',
    'weight' => '2',
    'children' => array(
      0 => 'field_records',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-records field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_records|node|cpd_report_review|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reference|field_collection_item|field_references|default';
  $field_group->group_name = 'group_reference';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_references';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reference',
    'weight' => '0',
    'children' => array(
      0 => 'field_address',
      1 => 'field_email',
      2 => 'field_full_name',
      3 => 'field_position',
      4 => 'field_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Reference',
      'instance_settings' => array(
        'classes' => 'group-reference field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_reference|field_collection_item|field_references|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_submit|node|cpd_report_review|form';
  $field_group->group_name = 'group_submit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Submit',
    'weight' => '13',
    'children' => array(
      0 => 'field_understand_submit_lock',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Submit',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-submit field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_submit|node|cpd_report_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|cpd_report_review|default';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_declaration_tabs',
      1 => 'group_evidence_core_competencies',
      2 => 'group_identification',
      3 => 'group_records',
      4 => 'group_work_experience',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabs|node|cpd_report_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|cpd_report_review|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '6',
    'children' => array(
      0 => 'group_administration',
      1 => 'group_declaration',
      2 => 'group_evidence_core_competencies',
      3 => 'group_identification',
      4 => 'group_records',
      5 => 'group_submit',
      6 => 'group_work_experience',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabs|node|cpd_report_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work_experience|node|cpd_report_review|default';
  $field_group->group_name = 'group_work_experience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Work Experience',
    'weight' => '4',
    'children' => array(
      0 => 'field_qualifying_work_experience',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-work-experience field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_work_experience|node|cpd_report_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work_experience|node|cpd_report_review|form';
  $field_group->group_name = 'group_work_experience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Work Experience',
    'weight' => '10',
    'children' => array(
      0 => 'field_qualifying_work_experience',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Work Experience',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-work-experience field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_work_experience|node|cpd_report_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work_experience|node|cpd_report_review|print';
  $field_group->group_name = 'group_work_experience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_report_review';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work Experience',
    'weight' => '4',
    'children' => array(
      0 => 'field_qualifying_work_experience',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-work-experience field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_work_experience|node|cpd_report_review|print'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Administration');
  t('CPD Records');
  t('Declaration');
  t('Evidence of Core Competencies');
  t('Identification');
  t('Records');
  t('Reference');
  t('Submit');
  t('Tabs');
  t('Work Experience');

  return $field_groups;
}
