<?php
/**
 * @file
 * rmets_cpd_records_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rmets_cpd_records_features_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_objectives|node|cpd_record|full';
  $field_group->group_name = 'group_objectives';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpd_record';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Objectives',
    'weight' => '5',
    'children' => array(
      0 => 'field_objective_references',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Objectives',
      'instance_settings' => array(
        'classes' => 'group-objectives field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_objectives|node|cpd_record|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Objectives');

  return $field_groups;
}
