<?php
/**
 * @file
 * rmets_cpd_accreditation_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rmets_cpd_accreditation_features_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_administration|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_administration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Administration',
    'weight' => '15',
    'children' => array(
      0 => 'field_admin_file_attachment',
      1 => 'field_awarded_accreditation',
      2 => 'field_reviews',
      3 => 'field_status',
      4 => 'field_next_cpd_submission_date',
      5 => 'field_notes',
      6 => 'field_crm_accred_app_id',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Administration',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-administration field-group-htab',
        'description' => 'Administration description here...',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_administration|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_declaration|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_declaration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Declaration',
    'weight' => '13',
    'children' => array(
      0 => 'field_declare_truth_conduct',
      1 => 'field_contact_email',
      2 => 'field_declaration_email',
      3 => 'field_position',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Declaration',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-declaration field-group-htab',
        'description' => 'Declaration description here....',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_declaration|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_declaration|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_declaration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Declaration',
    'weight' => '44',
    'children' => array(
      0 => 'field_agree_published_online',
      1 => 'field_declare_truth_conduct',
      2 => 'field_contact_email',
      3 => 'field_declaration_email',
      4 => 'field_position',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-declaration field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_declaration|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_declaration|node|cpd_accreditation_application|print';
  $field_group->group_name = 'group_declaration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Declaration',
    'weight' => '8',
    'children' => array(
      0 => 'field_agree_published_online',
      1 => 'field_declare_truth_conduct',
      2 => 'field_position',
      3 => 'field_contact_email',
      4 => 'field_declaration_email',
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
  $field_groups['group_declaration|node|cpd_accreditation_application|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_education_prof_training|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_education_prof_training';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Education and Qualifications',
    'weight' => '6',
    'children' => array(
      0 => 'field_file_attachment',
      1 => 'field_qualifications',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Education and Qualifications',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-education-prof-training field-group-htab',
        'description' => 'Education and Professional Training description text here',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_education_prof_training|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_education_prof_training|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_education_prof_training';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Education and Professional Training',
    'weight' => '37',
    'children' => array(
      0 => 'field_file_attachment',
      1 => 'field_qualifications',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Education and Professional Training',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-education-prof-training field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_education_prof_training|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_education_prof_training|node|cpd_accreditation_application|print';
  $field_group->group_name = 'group_education_prof_training';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Education and Professional Training',
    'weight' => '2',
    'children' => array(
      0 => 'field_areas_of_specialism',
      1 => 'field_file_attachment',
      2 => 'field_qualifications',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-education-prof-training field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_education_prof_training|node|cpd_accreditation_application|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evidence_core_competencies|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_evidence_core_competencies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
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
      5 => 'field_evidence_comms_skills',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Evidence of Core Competencies',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-evidence-core-competencies field-group-htab',
        'description' => 'Evidence of Core Competencies descrioption .....
Consider the competencies required of a Registered Meteorologist and briefly state here what you consider to be the evidence, based upon your work experience in addition to the qualifications listed in section 1, that you can offer to demonstrate that you have achieved them. ',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_evidence_core_competencies|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evidence_core_competencies|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_evidence_core_competencies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Evidence of Core Competencies',
    'weight' => '42',
    'children' => array(
      0 => 'field_a1_a3',
      1 => 'field_b1_b4',
      2 => 'field_c1_c3',
      3 => 'field_d1_d4',
      4 => 'field_e1_e3',
      5 => 'field_evidence_comms_skills',
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
  $field_groups['group_evidence_core_competencies|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evidence_core_competencies|node|cpd_accreditation_application|print';
  $field_group->group_name = 'group_evidence_core_competencies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Evidence of Core Competencies',
    'weight' => '6',
    'children' => array(
      0 => 'field_a1_a3',
      1 => 'field_b1_b4',
      2 => 'field_c1_c3',
      3 => 'field_d1_d4',
      4 => 'field_e1_e3',
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
  $field_groups['group_evidence_core_competencies|node|cpd_accreditation_application|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identification|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_identification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '5',
    'children' => array(
      0 => 'field_contact_address',
      1 => 'field_email',
      2 => 'field_employer_name',
      3 => 'field_full_name',
      4 => 'field_job_title_position',
      5 => 'field_membership_number',
      6 => 'field_public_telephone',
      7 => 'field_type_of_accreditation',
      8 => 'field_user',
      9 => 'field_previous_name',
      10 => 'field_crm_accreditation_type',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Identification',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-identification field-group-htab',
        'description' => 'Identification description text here...',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_identification|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identification|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_identification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '36',
    'children' => array(
      0 => 'field_contact_address',
      1 => 'field_email',
      2 => 'field_employer_name',
      3 => 'field_full_name',
      4 => 'field_job_title_position',
      5 => 'field_membership_number',
      6 => 'field_public_telephone',
      7 => 'field_type_of_accreditation',
      8 => 'field_previous_name',
      9 => 'field_crm_accreditation_type',
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
  $field_groups['group_identification|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identification|node|cpd_accreditation_application|print';
  $field_group->group_name = 'group_identification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '1',
    'children' => array(
      0 => 'field_contact_address',
      1 => 'field_email',
      2 => 'field_employer_name',
      3 => 'field_full_name',
      4 => 'field_job_title_position',
      5 => 'field_membership_number',
      6 => 'field_public_telephone',
      7 => 'field_type_of_accreditation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-identification field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_identification|node|cpd_accreditation_application|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profession_review|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_profession_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Professional Review',
    'weight' => '41',
    'children' => array(
      0 => 'field_professional_review',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profession-review field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_profession_review|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profession_review|node|cpd_accreditation_application|form';
  $field_group->group_name = 'group_profession_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Professional Review',
    'weight' => '10',
    'children' => array(
      0 => 'field_professional_review',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Professional Review',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => 'Professional Review description....',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_profession_review|node|cpd_accreditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profession_review|node|cpd_accreditation_application|print';
  $field_group->group_name = 'group_profession_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Professional Review',
    'weight' => '5',
    'children' => array(
      0 => 'field_professional_review',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profession-review field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_profession_review|node|cpd_accreditation_application|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_records|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_records';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Records',
    'weight' => '39',
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
  $field_groups['group_records|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_records|node|cpd_accreditation_application|form';
  $field_group->group_name = 'group_records';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'CPD Records',
    'weight' => '8',
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
        'description' => 'Records description text here...',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_records|node|cpd_accreditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_records|node|cpd_accreditation_application|print';
  $field_group->group_name = 'group_records';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Records',
    'weight' => '3',
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
  $field_groups['group_records|node|cpd_accreditation_application|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_references|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'References',
    'weight' => '12',
    'children' => array(
      0 => 'field_references',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'References',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-references field-group-htab',
        'description' => 'References description .... Provide name, position, address and telephone number of two professional referees who may be contacted by the Society. Please seek the agreement of your referees before submitting their names. Your referees will be asked to state whether they support your declared specialisms. Note that your referees should not be your current immediate line manager(s).',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_references|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_references|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'References',
    'weight' => '43',
    'children' => array(
      0 => 'field_references',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-references field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_references|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_references|node|cpd_accreditation_application|print';
  $field_group->group_name = 'group_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'References',
    'weight' => '7',
    'children' => array(
      0 => 'field_references',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-references field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_references|node|cpd_accreditation_application|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relevant_work_experience|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_relevant_work_experience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Relevant Qualifying Work Experience',
    'weight' => '9',
    'children' => array(
      0 => 'field_qualifying_work_experience',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Relevant Qualifying Work Experience',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-relevant-work-experience field-group-htab',
        'description' => 'Relevant Qualifying Work Experience description text...
Please state the date from which your qualifying work experience should count. Time spent on training courses does not count towards qualifying experience. Time spent as an operational supernummary (trainee) or under close direct supervision counts as 50% of elapsed time. If you are returning to the full Register from a period as a “dormant” registrant, you need to show 1 full year of “Qualifying experience”.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_relevant_work_experience|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relevant_work_experience|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_relevant_work_experience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Relevant Qualifying Work Experience',
    'weight' => '40',
    'children' => array(
      0 => 'field_qualifying_work_experience',
      1 => 'work_experience',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-relevant-work-experience field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_relevant_work_experience|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relevant_work_experience|node|cpd_accreditation_application|print';
  $field_group->group_name = 'group_relevant_work_experience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relevant Qualifying Work Experience',
    'weight' => '4',
    'children' => array(
      0 => 'field_qualifying_work_experience',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-relevant-work-experience field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_relevant_work_experience|node|cpd_accreditation_application|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specialisms|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_specialisms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Specialisms',
    'weight' => '38',
    'children' => array(
      0 => 'field_areas_of_specialism',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-specialisms field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_specialisms|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specialisms|node|cpd_accreditation_application|form';
  $field_group->group_name = 'group_specialisms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Specialisms',
    'weight' => '7',
    'children' => array(
      0 => 'field_areas_of_specialism',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Specialisms',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-specialisms field-group-htab',
        'description' => 'Select from the list which best describe your areas of specialism. You have a maximum of three areas that you can select.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_specialisms|node|cpd_accreditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_submit|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_submit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Submit',
    'weight' => '14',
    'children' => array(
      0 => 'field_agree_published_online',
      1 => 'field_understand_submit_lock',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Submit',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-submit field-group-htab',
        'description' => 'Submit description here...',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_submit|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|cpd_acceditation_application|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '6',
    'children' => array(
      0 => 'group_administration',
      1 => 'group_declaration',
      2 => 'group_education_prof_training',
      3 => 'group_evidence_core_competencies',
      4 => 'group_identification',
      5 => 'group_profession_review',
      6 => 'group_records',
      7 => 'group_references',
      8 => 'group_relevant_work_experience',
      9 => 'group_specialisms',
      10 => 'group_submit',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabs|node|cpd_acceditation_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|cpd_accreditation_application|default';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_accreditation_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '2',
    'children' => array(
      0 => 'group_declaration',
      1 => 'group_education_prof_training',
      2 => 'group_evidence_core_competencies',
      3 => 'group_identification',
      4 => 'group_profession_review',
      5 => 'group_records',
      6 => 'group_references',
      7 => 'group_relevant_work_experience',
      8 => 'group_specialisms',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabs|node|cpd_accreditation_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work_experience|field_collection_item|field_qualifying_work_experience|default';
  $field_group->group_name = 'group_work_experience';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_qualifying_work_experience';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work Experience',
    'weight' => '0',
    'children' => array(
      0 => 'field_employer_address',
      1 => 'field_employer_name',
      2 => 'field_end_date',
      3 => 'field_job_title_position',
      4 => 'field_start_date',
      5 => 'field_job_title_duration',
      6 => 'field_nature_of_work',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Work Experience',
      'instance_settings' => array(
        'classes' => 'group-work-experience field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_work_experience|field_collection_item|field_qualifying_work_experience|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Administration');
  t('CPD Records');
  t('Declaration');
  t('Education and Professional Training');
  t('Education and Qualifications');
  t('Evidence of Core Competencies');
  t('Identification');
  t('Professional Review');
  t('Records');
  t('References');
  t('Relevant Qualifying Work Experience');
  t('Specialisms');
  t('Submit');
  t('Tabs');
  t('Work Experience');

  return $field_groups;
}
