<?php
/**
 * @file
 * award_profiles.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function award_profiles_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|award_profile|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'award_profile';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'award_winners_award_list' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_accreditation_address' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'h3',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
      ),
    ),
    'field_countries' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'h3',
        'lb-cl' => 'field-label',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
      ),
    ),
    'field_current_employment' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'h3',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
      ),
    ),
    'field_employment_history' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'h3',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
      ),
    ),
    'field_expertise' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'h3',
        'lb-cl' => 'field-label',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
      ),
    ),
    'field_forenames' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Name',
        'lb-el' => 'h3',
        'fis' => TRUE,
        'fis-el' => 'span',
        'fis-cl' => '',
      ),
    ),
    'field_languages' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'h3',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
      ),
    ),
    'field_person_picture' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'image-wrapper rounded right',
      ),
    ),
    'field_public_email' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'h3',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
      ),
    ),
    'field_public_telephone' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Telephone',
        'lb-el' => 'h3',
      ),
    ),
    'field_suffix' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
    'field_surname' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
  );
  $export['node|award_profile|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function award_profiles_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'award_winners_award_list';
  $ds_field->label = 'Award winners awards';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|awardees_list-block_1',
    'block_render' => '3',
  );
  $export['award_winners_award_list'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function award_profiles_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|award_profile|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'award_profile';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_person_picture',
        1 => 'field_forenames',
        2 => 'field_surname',
        3 => 'field_suffix',
        4 => 'field_public_email',
        5 => 'field_public_telephone',
        6 => 'field_accreditation_address',
        7 => 'field_current_employment',
        8 => 'field_employment_history',
        9 => 'field_expertise',
        10 => 'field_languages',
        11 => 'field_countries',
        12 => 'award_winners_award_list',
        13 => 'field_additional_information',
      ),
    ),
    'fields' => array(
      'field_person_picture' => 'ds_content',
      'field_forenames' => 'ds_content',
      'field_surname' => 'ds_content',
      'field_suffix' => 'ds_content',
      'field_public_email' => 'ds_content',
      'field_public_telephone' => 'ds_content',
      'field_accreditation_address' => 'ds_content',
      'field_current_employment' => 'ds_content',
      'field_employment_history' => 'ds_content',
      'field_expertise' => 'ds_content',
      'field_languages' => 'ds_content',
      'field_countries' => 'ds_content',
      'award_winners_award_list' => 'ds_content',
      'field_additional_information' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|award_profile|default'] = $ds_layout;

  return $export;
}
