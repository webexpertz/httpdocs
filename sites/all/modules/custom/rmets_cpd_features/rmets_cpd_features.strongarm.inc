<?php
/**
 * @file
 * rmets_cpd_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function rmets_cpd_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'chosen_admin_pages';
  $strongarm->value = 0;
  $export['chosen_admin_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'chosen_use_theme';
  $strongarm->value = 1;
  $export['chosen_use_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'path_breadcrumbs_internal_render_themes';
  $strongarm->value = array(
    'rmets' => 'rmets',
  );
  $export['path_breadcrumbs_internal_render_themes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_button_value';
  $strongarm->value = 'Save';
  $export['save_edit_button_value'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_button_weight';
  $strongarm->value = '4';
  $export['save_edit_button_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_default_save_button_value';
  $strongarm->value = 'Save and close';
  $export['save_edit_default_save_button_value'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_default_save_button_weight';
  $strongarm->value = '5';
  $export['save_edit_default_save_button_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_hide_default_delete';
  $strongarm->value = 0;
  $export['save_edit_hide_default_delete'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_hide_default_preview';
  $strongarm->value = 0;
  $export['save_edit_hide_default_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_hide_default_save';
  $strongarm->value = 0;
  $export['save_edit_hide_default_save'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_node_types';
  $strongarm->value = array(
    'cpd_accreditation_application' => 'cpd_accreditation_application',
    'cpd_report_review' => 'cpd_report_review',
    'article' => 0,
    'award' => 0,
    'award_profile' => 0,
    'page' => 0,
    'cpd_objective' => 0,
    'cpd_record' => 0,
    'carousel_item' => 0,
    'committee_document' => 0,
    'committee_meeting' => 0,
    'corporate_member' => 0,
    'event' => 0,
    'event_abstract' => 0,
    'event_session' => 0,
    'event_subsession' => 0,
    'image_gallery' => 0,
    'landing_page' => 0,
    'legacies_fund' => 0,
    'local_area_groups' => 0,
    'news' => 0,
    'product_display' => 0,
    'special_interest_groups' => 0,
    'webform' => 0,
    'webform_product' => 0,
  );
  $export['save_edit_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_publish_button_value';
  $strongarm->value = 'Publish';
  $export['save_edit_publish_button_value'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_publish_button_weight';
  $strongarm->value = '7';
  $export['save_edit_publish_button_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_unpublish';
  $strongarm->value = 0;
  $export['save_edit_unpublish'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_edit_unpublish_new_only';
  $strongarm->value = 0;
  $export['save_edit_unpublish_new_only'] = $strongarm;

  return $export;
}
