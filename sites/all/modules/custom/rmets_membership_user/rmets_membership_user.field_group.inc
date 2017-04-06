<?php
/**
 * @file
 * rmets_membership_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rmets_membership_user_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_experience|user|user|form';
  $field_group->group_name = 'group_experience';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Education and Qualifications',
    'weight' => '21',
    'children' => array(
      0 => 'field_file_attachment',
      1 => 'field_qualifications',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Education and Qualifications',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-experience field-group-fieldset',
        'description' => '<p>Please list any relevant qualifications and professional training either from formal education at institutes of higher education or training centres, which includes degrees, diplomas and certificates. (Note: that you will be asked to provide copies of certificates if you apply for RMet or CMet. Attach scanned images of certificates using the ‘File attachment’ function below. The RMetS may request original certificates.)</p>

<p><b>Please note that if you are pasting from Word, you can retain your formatting by using the Paste from Word icon below, at the top of the editor. Simply click and paste and this will copy your formatting into the editor.</b></p>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_experience|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Education and Qualifications');

  return $field_groups;
}
