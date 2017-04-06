<?php
/**
 * @file
 * award_profiles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function award_profiles_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'award_lists';
  $view->description = 'Register of Chartered Meteorologists of the Society';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Award lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_prefix' => 'field_prefix',
    'field_forenames' => 'field_forenames',
    'field_surname' => 'field_surname',
    'field_suffix' => 'field_suffix',
    'edit_node' => 'field_suffix',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_prefix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_forenames' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_suffix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&nbsp;&nbsp;&nbsp;',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Award type (field_award_type) */
  $handler->display->display_options['relationships']['field_award_type_tid']['id'] = 'field_award_type_tid';
  $handler->display->display_options['relationships']['field_award_type_tid']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['relationships']['field_award_type_tid']['field'] = 'field_award_type_tid';
  $handler->display->display_options['relationships']['field_award_type_tid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_member_profile_target_id']['id'] = 'field_member_profile_target_id';
  $handler->display->display_options['relationships']['field_member_profile_target_id']['table'] = 'field_data_field_member_profile';
  $handler->display->display_options['relationships']['field_member_profile_target_id']['field'] = 'field_member_profile_target_id';
  $handler->display->display_options['relationships']['field_member_profile_target_id']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Fullname */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Fullname';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_surname']['alter']['path'] = 'our-activities/cmet-register/[nid]';
  $handler->display->display_options['fields']['field_surname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['alter']['path_case'] = 'lower';
  /* Field: Content: Suffix */
  $handler->display->display_options['fields']['field_suffix']['id'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['table'] = 'field_data_field_suffix';
  $handler->display->display_options['fields']['field_suffix']['field'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_member_profile_target_id';
  /* Field: Content: Award date */
  $handler->display->display_options['fields']['field_award_date']['id'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['fields']['field_award_date']['field'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['label'] = 'Accreditation date';
  $handler->display->display_options['fields']['field_award_date']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Field: Surname (field_surname) */
  $handler->display->display_options['sorts']['field_surname_value']['id'] = 'field_surname_value';
  $handler->display->display_options['sorts']['field_surname_value']['table'] = 'field_data_field_surname';
  $handler->display->display_options['sorts']['field_surname_value']['field'] = 'field_surname_value';
  $handler->display->display_options['sorts']['field_surname_value']['relationship'] = 'field_member_profile_target_id';
  /* Contextual filter: Content: Award type (field_award_type) */
  $handler->display->display_options['arguments']['field_award_type_tid']['id'] = 'field_award_type_tid';
  $handler->display->display_options['arguments']['field_award_type_tid']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['arguments']['field_award_type_tid']['field'] = 'field_award_type_tid';
  $handler->display->display_options['arguments']['field_award_type_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_award_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_award_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_award_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_award_type_tid']['summary_options']['items_per_page'] = '25';

  /* Display: Simple award listing table */
  $handler = $view->new_display('block', 'Simple award listing table', 'simple_table_list');
  $handler->display->display_options['display_description'] = 'List of fellows of the society as a block';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<div class="text-centered">Displaying @start - @end of @total</div>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Fullname */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Fullname';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_surname']['alter']['path'] = 'our-activities/cmet-register/[nid]';
  $handler->display->display_options['fields']['field_surname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['alter']['path_case'] = 'lower';
  /* Field: Content: Suffix */
  $handler->display->display_options['fields']['field_suffix']['id'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['table'] = 'field_data_field_suffix';
  $handler->display->display_options['fields']['field_suffix']['field'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_member_profile_target_id';

  /* Display: Image inset (honorary fellows) */
  $handler = $view->new_display('block', 'Image inset (honorary fellows)', 'award_image_insert_list');
  $handler->display->display_options['display_description'] = 'A block with a profile image';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'view-award-image-inset-listing item-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Profile picture */
  $handler->display->display_options['fields']['field_person_picture']['id'] = 'field_person_picture';
  $handler->display->display_options['fields']['field_person_picture']['table'] = 'field_data_field_person_picture';
  $handler->display->display_options['fields']['field_person_picture']['field'] = 'field_person_picture';
  $handler->display->display_options['fields']['field_person_picture']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_person_picture']['label'] = '';
  $handler->display->display_options['fields']['field_person_picture']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_person_picture']['element_class'] = 'image-wrapper rounded left';
  $handler->display->display_options['fields']['field_person_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_person_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_person_picture']['settings'] = array(
    'image_style' => 'profile_picture',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_prefix']['element_label_colon'] = FALSE;
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_forenames']['label'] = '';
  $handler->display->display_options['fields']['field_forenames']['element_label_colon'] = FALSE;
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_surname']['label'] = '';
  $handler->display->display_options['fields']['field_surname']['alter']['path'] = 'our-activities/cmet-register/[nid]';
  $handler->display->display_options['fields']['field_surname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_surname']['element_label_colon'] = FALSE;
  /* Field: Content: Suffix */
  $handler->display->display_options['fields']['field_suffix']['id'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['table'] = 'field_data_field_suffix';
  $handler->display->display_options['fields']['field_suffix']['field'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_suffix']['element_label_colon'] = FALSE;
  /* Field: Content: Award date */
  $handler->display->display_options['fields']['field_award_date']['id'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['fields']['field_award_date']['field'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['label'] = 'Elected as an honorary fellow in ';
  $handler->display->display_options['fields']['field_award_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_date']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;

  /* Display: Accreditation register table */
  $handler = $view->new_display('block', 'Accreditation register table', 'accreditations_table');
  $handler->display->display_options['display_description'] = 'A full table of details for an accreditation register with filters';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_prefix' => 'field_prefix',
    'field_forenames' => 'field_forenames',
    'field_surname' => 'field_surname',
    'field_suffix' => 'field_suffix',
    'field_award_date' => 'field_award_date',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_prefix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_forenames' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_suffix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&nbsp;&nbsp;&nbsp;',
      'empty_column' => 0,
    ),
    'field_award_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '&nbsp;&nbsp;&nbsp;',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Fullname */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Fullname';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_surname']['alter']['path'] = 'our-activities/cmet-register/[nid]';
  $handler->display->display_options['fields']['field_surname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['alter']['path_case'] = 'lower';
  /* Field: Content: Suffix */
  $handler->display->display_options['fields']['field_suffix']['id'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['table'] = 'field_data_field_suffix';
  $handler->display->display_options['fields']['field_suffix']['field'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Content: Award date */
  $handler->display->display_options['fields']['field_award_date']['id'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['fields']['field_award_date']['field'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['label'] = 'Accreditation date';
  $handler->display->display_options['fields']['field_award_date']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['view_node']['label'] = 'Public profile';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Expertise (field_expertise) */
  $handler->display->display_options['filters']['field_expertise_value']['id'] = 'field_expertise_value';
  $handler->display->display_options['filters']['field_expertise_value']['table'] = 'field_data_field_expertise';
  $handler->display->display_options['filters']['field_expertise_value']['field'] = 'field_expertise_value';
  $handler->display->display_options['filters']['field_expertise_value']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['filters']['field_expertise_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_expertise_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_expertise_value']['expose']['operator_id'] = 'field_expertise_value_op';
  $handler->display->display_options['filters']['field_expertise_value']['expose']['label'] = 'Expertise';
  $handler->display->display_options['filters']['field_expertise_value']['expose']['operator'] = 'field_expertise_value_op';
  $handler->display->display_options['filters']['field_expertise_value']['expose']['identifier'] = 'field_expertise_value';
  /* Filter criterion: Content: Current Employment (field_current_employment) */
  $handler->display->display_options['filters']['field_current_employment_value']['id'] = 'field_current_employment_value';
  $handler->display->display_options['filters']['field_current_employment_value']['table'] = 'field_data_field_current_employment';
  $handler->display->display_options['filters']['field_current_employment_value']['field'] = 'field_current_employment_value';
  $handler->display->display_options['filters']['field_current_employment_value']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['filters']['field_current_employment_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_current_employment_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_current_employment_value']['expose']['operator_id'] = 'field_current_employment_value_op';
  $handler->display->display_options['filters']['field_current_employment_value']['expose']['label'] = 'Employment';
  $handler->display->display_options['filters']['field_current_employment_value']['expose']['operator'] = 'field_current_employment_value_op';
  $handler->display->display_options['filters']['field_current_employment_value']['expose']['identifier'] = 'field_current_employment_value';
  /* Filter criterion: Content: Languages (field_languages) */
  $handler->display->display_options['filters']['field_languages_value']['id'] = 'field_languages_value';
  $handler->display->display_options['filters']['field_languages_value']['table'] = 'field_data_field_languages';
  $handler->display->display_options['filters']['field_languages_value']['field'] = 'field_languages_value';
  $handler->display->display_options['filters']['field_languages_value']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['filters']['field_languages_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_languages_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_languages_value']['expose']['operator_id'] = 'field_languages_value_op';
  $handler->display->display_options['filters']['field_languages_value']['expose']['label'] = 'Languages';
  $handler->display->display_options['filters']['field_languages_value']['expose']['operator'] = 'field_languages_value_op';
  $handler->display->display_options['filters']['field_languages_value']['expose']['identifier'] = 'field_languages_value';

  /* Display: Award winners table */
  $handler = $view->new_display('block', 'Award winners table', 'block_1');
  $handler->display->display_options['display_description'] = 'A full table of details for award winners';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_prefix' => 'field_prefix',
    'field_forenames' => 'field_forenames',
    'field_surname' => 'field_surname',
    'field_suffix' => 'field_suffix',
    'field_award_date' => 'field_award_date',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_prefix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_forenames' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_suffix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&nbsp;&nbsp;&nbsp;',
      'empty_column' => 0,
    ),
    'field_award_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '&nbsp;&nbsp;&nbsp;',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Fullname */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Fullname';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_surname']['alter']['path'] = 'our-activities/cmet-register/[nid]';
  $handler->display->display_options['fields']['field_surname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['alter']['path_case'] = 'lower';
  /* Field: Content: Suffix */
  $handler->display->display_options['fields']['field_suffix']['id'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['table'] = 'field_data_field_suffix';
  $handler->display->display_options['fields']['field_suffix']['field'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Content: Award date */
  $handler->display->display_options['fields']['field_award_date']['id'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['fields']['field_award_date']['field'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['label'] = 'Award year';
  $handler->display->display_options['fields']['field_award_date']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_award_type_tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['view_node']['label'] = 'Public profile';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Award date (field_award_date) */
  $handler->display->display_options['sorts']['field_award_date_value']['id'] = 'field_award_date_value';
  $handler->display->display_options['sorts']['field_award_date_value']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['sorts']['field_award_date_value']['field'] = 'field_award_date_value';
  $handler->display->display_options['sorts']['field_award_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Awards administration */
  $handler = $view->new_display('page', 'Awards administration', 'page_1');
  $handler->display->display_options['display_description'] = 'Admin page for awards';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title' => 'title',
    'field_prefix' => 'field_prefix',
    'field_forenames' => 'field_forenames',
    'field_surname' => 'field_surname',
    'field_suffix' => 'field_suffix',
    'field_award_date' => 'field_award_date',
    'field_award_type' => 'field_award_type',
    'status' => 'status',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_award_date';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_prefix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_forenames' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_suffix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'The accreditations, awards and Fellows are stored in CRM and synchronised overnight. <a href="/admin/reports/status/crm_sync_awards">Synchronise now</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 1,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 1,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Fullname */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Fullname';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['relationship'] = 'field_member_profile_target_id';
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['field_surname']['alter']['path'] = 'our-activities/cmet-register/[nid]';
  $handler->display->display_options['fields']['field_surname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['alter']['path_case'] = 'lower';
  /* Field: Content: Suffix */
  $handler->display->display_options['fields']['field_suffix']['id'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['table'] = 'field_data_field_suffix';
  $handler->display->display_options['fields']['field_suffix']['field'] = 'field_suffix';
  $handler->display->display_options['fields']['field_suffix']['relationship'] = 'field_member_profile_target_id';
  /* Field: Content: Award date */
  $handler->display->display_options['fields']['field_award_date']['id'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['fields']['field_award_date']['field'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['label'] = 'Accreditation date';
  $handler->display->display_options['fields']['field_award_date']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Award type */
  $handler->display->display_options['fields']['field_award_type']['id'] = 'field_award_type';
  $handler->display->display_options['fields']['field_award_type']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['fields']['field_award_type']['field'] = 'field_award_type';
  $handler->display->display_options['fields']['field_award_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Surname (field_surname) */
  $handler->display->display_options['sorts']['field_surname_value']['id'] = 'field_surname_value';
  $handler->display->display_options['sorts']['field_surname_value']['table'] = 'field_data_field_surname';
  $handler->display->display_options['sorts']['field_surname_value']['field'] = 'field_surname_value';
  $handler->display->display_options['sorts']['field_surname_value']['relationship'] = 'field_member_profile_target_id';
  /* Sort criterion: Content: Award date (field_award_date) */
  $handler->display->display_options['sorts']['field_award_date_value']['id'] = 'field_award_date_value';
  $handler->display->display_options['sorts']['field_award_date_value']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['sorts']['field_award_date_value']['field'] = 'field_award_date_value';
  $handler->display->display_options['sorts']['field_award_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_tid']['id'] = 'field_award_type_tid';
  $handler->display->display_options['filters']['field_award_type_tid']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_tid']['field'] = 'field_award_type_tid';
  $handler->display->display_options['filters']['field_award_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_award_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_type_tid']['expose']['operator_id'] = 'field_award_type_tid_op';
  $handler->display->display_options['filters']['field_award_type_tid']['expose']['label'] = 'Award type';
  $handler->display->display_options['filters']['field_award_type_tid']['expose']['operator'] = 'field_award_type_tid_op';
  $handler->display->display_options['filters']['field_award_type_tid']['expose']['identifier'] = 'field_award_type_tid';
  $handler->display->display_options['filters']['field_award_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_award_type_tid']['vocabulary'] = 'accreditations_awards';
  /* Filter criterion: Field: Surname (field_surname) */
  $handler->display->display_options['filters']['field_surname_value']['id'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['table'] = 'field_data_field_surname';
  $handler->display->display_options['filters']['field_surname_value']['field'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['filters']['field_surname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_surname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_surname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_surname_value']['expose']['operator_id'] = 'field_surname_value_op';
  $handler->display->display_options['filters']['field_surname_value']['expose']['label'] = 'Surname';
  $handler->display->display_options['filters']['field_surname_value']['expose']['operator'] = 'field_surname_value_op';
  $handler->display->display_options['filters']['field_surname_value']['expose']['identifier'] = 'field_surname_value';
  /* Filter criterion: Field: Membership number (field_membership_number) */
  $handler->display->display_options['filters']['field_membership_number_value']['id'] = 'field_membership_number_value';
  $handler->display->display_options['filters']['field_membership_number_value']['table'] = 'field_data_field_membership_number';
  $handler->display->display_options['filters']['field_membership_number_value']['field'] = 'field_membership_number_value';
  $handler->display->display_options['filters']['field_membership_number_value']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['filters']['field_membership_number_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_membership_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_membership_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_membership_number_value']['expose']['operator_id'] = 'field_membership_number_value_op';
  $handler->display->display_options['filters']['field_membership_number_value']['expose']['label'] = 'Membership number';
  $handler->display->display_options['filters']['field_membership_number_value']['expose']['operator'] = 'field_membership_number_value_op';
  $handler->display->display_options['filters']['field_membership_number_value']['expose']['identifier'] = 'field_membership_number_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['path'] = 'admin/content/awards';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Awards';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['award_lists'] = $view;

  $view = new view();
  $view->name = 'awardees_list';
  $view->description = 'A list of awards a person has';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Awardees list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_member_profile_target_id']['id'] = 'field_member_profile_target_id';
  $handler->display->display_options['relationships']['field_member_profile_target_id']['table'] = 'field_data_field_member_profile';
  $handler->display->display_options['relationships']['field_member_profile_target_id']['field'] = 'field_member_profile_target_id';
  $handler->display->display_options['relationships']['field_member_profile_target_id']['required'] = TRUE;
  /* Relationship: Content: Award type (field_award_type) */
  $handler->display->display_options['relationships']['field_award_type_tid']['id'] = 'field_award_type_tid';
  $handler->display->display_options['relationships']['field_award_type_tid']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['relationships']['field_award_type_tid']['field'] = 'field_award_type_tid';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_award_type_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]:';
  $handler->display->display_options['fields']['name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Content: Award date */
  $handler->display->display_options['fields']['field_award_date']['id'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['fields']['field_award_date']['field'] = 'field_award_date';
  $handler->display->display_options['fields']['field_award_date']['label'] = '';
  $handler->display->display_options['fields']['field_award_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_award_date']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Award date (field_award_date) */
  $handler->display->display_options['sorts']['field_award_date_value']['id'] = 'field_award_date_value';
  $handler->display->display_options['sorts']['field_award_date_value']['table'] = 'field_data_field_award_date';
  $handler->display->display_options['sorts']['field_award_date_value']['field'] = 'field_award_date_value';
  $handler->display->display_options['sorts']['field_award_date_value']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_member_profile_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Award winners award list */
  $handler = $view->new_display('block', 'Award winners award list', 'block_1');
  $handler->display->display_options['display_description'] = 'A list of an award winners awards';
  $export['awardees_list'] = $view;

  return $export;
}
