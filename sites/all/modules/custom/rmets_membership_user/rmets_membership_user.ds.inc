<?php
/**
 * @file
 * rmets_membership_user.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function rmets_membership_user_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'education';
  $ds_field->label = 'Education';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$out = \'\';
  if (!isset($entity->field_user[\'und\'][0][\'target_id\'])) {
    return;
  }
    $account = user_load($entity->field_user[\'und\'][0][\'target_id\']);
    $field = field_view_field(\'user\', $account, \'field_qualifications\');
    $out .= render($field);
    $field = field_view_field(\'user\', $account, \'field_areas_of_specialism\');
    $out .= render($field);
    $field = field_view_field(\'user\', $account, \'field_file_attachment\');
    $out .= render($field);

return $out;
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['education'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'work_experience';
  $ds_field->label = 'Work Experience';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
if (isset($entity->field_user[\'und\'][0][\'target_id\'])) {
    $account = user_load($entity->field_user[\'und\'][0][\'target_id\']);
    $field = field_view_field(\'user\', $account, \'field_qualifying_work_experience\');
    // Remove the add link
    $field[\'#suffix\'] = \'\';
    if (count($field[\'#items\']) < 1) {
      $field_output = \'<strong>\' . t(\'You have no work experience defined within your profile.\') . \'</strong>\';
    }
    else {
      // Remove the edit/ delete links.
      foreach ($field[\'#items\'] as $key => $value) {
        $field[$key][\'links\'] = array();
      }
      $field_output = render($field);
    }
    return $field_output;
}
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['work_experience'] = $ds_field;

  return $export;
}
