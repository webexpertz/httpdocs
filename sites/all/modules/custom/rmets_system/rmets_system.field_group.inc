<?php
/**
 * @file
 * rmets_system.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rmets_system_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buttons|node|event|default';
  $field_group->group_name = 'group_buttons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buttons',
    'weight' => '7',
    'children' => array(
      0 => 'field_allow_abstract_submissions',
      1 => 'event_registration',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Buttons',
      'instance_settings' => array(
        'classes' => 'group-buttons field-group-div clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_event_full_group_buttons',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_buttons|node|event|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Buttons');

  return $field_groups;
}
