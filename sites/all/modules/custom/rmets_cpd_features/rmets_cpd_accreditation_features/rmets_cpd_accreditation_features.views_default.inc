<?php
/**
 * @file
 * rmets_cpd_accreditation_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rmets_cpd_accreditation_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cmet_declarations_late';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'CMet Declarations Late';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CMet Declarations Late';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view cpd reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_forenames' => 'field_forenames',
    'field_membership_number' => 'field_membership_number',
    'field_surname' => 'field_surname',
    'mail' => 'mail',
    'field_cpd_report_submission_date' => 'field_cpd_report_submission_date',
  );
  $handler->display->display_options['style_options']['default'] = 'field_membership_number';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_forenames' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_membership_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_surname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cpd_report_submission_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No results were found for this search.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  /* Field: Field: Membership number */
  $handler->display->display_options['fields']['field_membership_number']['id'] = 'field_membership_number';
  $handler->display->display_options['fields']['field_membership_number']['table'] = 'field_data_field_membership_number';
  $handler->display->display_options['fields']['field_membership_number']['field'] = 'field_membership_number';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: User: Next CPD Report Submission Date */
  $handler->display->display_options['fields']['field_cpd_report_submission_date']['id'] = 'field_cpd_report_submission_date';
  $handler->display->display_options['fields']['field_cpd_report_submission_date']['table'] = 'field_data_field_cpd_report_submission_date';
  $handler->display->display_options['fields']['field_cpd_report_submission_date']['field'] = 'field_cpd_report_submission_date';
  $handler->display->display_options['fields']['field_cpd_report_submission_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Accreditation Types (field_accreditation_types) */
  $handler->display->display_options['filters']['field_accreditation_types_tid']['id'] = 'field_accreditation_types_tid';
  $handler->display->display_options['filters']['field_accreditation_types_tid']['table'] = 'field_data_field_accreditation_types';
  $handler->display->display_options['filters']['field_accreditation_types_tid']['field'] = 'field_accreditation_types_tid';
  $handler->display->display_options['filters']['field_accreditation_types_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_accreditation_types_tid']['value'] = '';
  $handler->display->display_options['filters']['field_accreditation_types_tid']['vocabulary'] = 'accreditation_type';
  /* Filter criterion: User: Next CPD Report Submission Date (field_cpd_report_submission_date) */
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['id'] = 'field_cpd_report_submission_date_value';
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['table'] = 'field_data_field_cpd_report_submission_date';
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['field'] = 'field_cpd_report_submission_date_value';
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['expose']['operator_id'] = 'field_cpd_report_submission_date_value_op';
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['expose']['label'] = 'Declaration due date before...';
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['expose']['operator'] = 'field_cpd_report_submission_date_value_op';
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['expose']['identifier'] = 'field_cpd_report_submission_date_value';
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_cpd_report_submission_date_value']['default_date'] = 'now -2 weeks';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/cpd/cmet-declarations-late';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'CMet Declarations Late';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cmet_declarations_late'] = $view;

  $view = new view();
  $view->name = 'cpd_accreditation';
  $view->description = '';
  $view->tag = 'CPD';
  $view->base_table = 'node';
  $view->human_name = 'CPD Accreditation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accreditation Application';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'rmets_cpd_records_access_cpd';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'field_status' => 'field_status',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_status' => array(
      'sortable' => 1,
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'Intro text';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<p>[cpd_accreditation_application_page_intro_text]<p>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/cpd-accreditation-application?destination=user/!1/cpd/accreditation&field_user=!1" class="button-link">Apply for an accreditation</a><h2>Your accreditations</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No previous accreditation applications were found.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['label'] = 'Accreditation Owner (user)';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title (Click title below to view or print individual reports)';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date started';
  $handler->display->display_options['fields']['created']['date_format'] = 'long_date_no_time';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['type'] = 'rmets_cpd_node_status_formatter';
  $handler->display->display_options['fields']['field_status']['settings'] = array(
    'link_title' => 0,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Contextual filter: Content: User (field_user) */
  $handler->display->display_options['arguments']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['arguments']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['field_user_target_id']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['field_user_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_accreditation_application' => 'cpd_accreditation_application',
  );

  /* Display: RMetS Accreditations */
  $handler = $view->new_display('page', 'RMetS Accreditations', 'cpd_accreditation_application_page');
  $handler->display->display_options['path'] = 'user/%/cpd/accreditation';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Accreditation Applications';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cpd_accreditation'] = $view;

  $view = new view();
  $view->name = 'cpd_accreditation_admin';
  $view->description = '';
  $view->tag = 'CPD';
  $view->base_table = 'node';
  $view->human_name = 'CPD Accreditation - Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CPD Accreditation Application - Admin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'access_cpd_reviews_reviewer';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_full_name' => 'field_full_name',
    'created' => 'created',
    'field_type_of_accreditation' => 'field_type_of_accreditation',
    'field_areas_of_specialism' => 'field_areas_of_specialism',
    'field_status' => 'field_status',
    'edit_node' => 'edit_node',
    'edit_node_1' => 'edit_node_1',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'field_full_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_type_of_accreditation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_areas_of_specialism' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_status' => array(
      'sortable' => 1,
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
    'edit_node_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_target_id']['field'] = 'field_user_target_id';
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Application started';
  $handler->display->display_options['fields']['created']['date_format'] = 'long_date_no_time';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'View Application';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['relationship'] = 'field_user_target_id';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  $handler->display->display_options['fields']['edit_node_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node_1']['text'] = 'Edit User';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_accreditation_application' => 'cpd_accreditation_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Surname (field_surname) */
  $handler->display->display_options['filters']['field_surname_value']['id'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['table'] = 'field_data_field_surname';
  $handler->display->display_options['filters']['field_surname_value']['field'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_surname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_surname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_surname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_surname_value']['expose']['operator_id'] = 'field_surname_value_op';
  $handler->display->display_options['filters']['field_surname_value']['expose']['label'] = 'Surname';
  $handler->display->display_options['filters']['field_surname_value']['expose']['operator'] = 'field_surname_value_op';
  $handler->display->display_options['filters']['field_surname_value']['expose']['identifier'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Status (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['expose']['operator_id'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['label'] = 'Status (field_status)';
  $handler->display->display_options['filters']['field_status_value']['expose']['operator'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['identifier'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_status_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['field_status_value']['group_info']['identifier'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Draft',
      'operator' => '=',
      'value' => array(
        'value' => '2',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Awaiting Payment',
      'operator' => '=',
      'value' => array(
        'value' => '3',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'Pending',
      'operator' => '=',
      'value' => array(
        'value' => '4',
        'min' => '',
        'max' => '',
      ),
    ),
    4 => array(
      'title' => 'Assigning reviewers',
      'operator' => '=',
      'value' => array(
        'value' => '5',
        'min' => '',
        'max' => '',
      ),
    ),
    5 => array(
      'title' => 'Awaiting review',
      'operator' => '=',
      'value' => array(
        'value' => '6',
        'min' => '',
        'max' => '',
      ),
    ),
    6 => array(
      'title' => 'Review processing',
      'operator' => '=',
      'value' => array(
        'value' => '7',
        'min' => '',
        'max' => '',
      ),
    ),
    7 => array(
      'title' => 'Awaiting board review',
      'operator' => '=',
      'value' => array(
        'value' => '8',
        'min' => '',
        'max' => '',
      ),
    ),
    8 => array(
      'title' => 'Awaiting board decision',
      'operator' => '=',
      'value' => array(
        'value' => '9',
        'min' => '',
        'max' => '',
      ),
    ),
    9 => array(
      'title' => 'Unacceptable',
      'operator' => '=',
      'value' => array(
        'value' => '10',
        'min' => '',
        'max' => '',
      ),
    ),
    10 => array(
      'title' => 'Acceptable',
      'operator' => '=',
      'value' => array(
        'value' => '11',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: Type of accreditation applying for (OLD) (field_type_of_accreditation) */
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['id'] = 'field_type_of_accreditation_target_id';
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['table'] = 'field_data_field_type_of_accreditation';
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['field'] = 'field_type_of_accreditation_target_id';
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['expose']['operator_id'] = 'field_type_of_accreditation_target_id_op';
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['expose']['label'] = 'Type of accreditation';
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['expose']['operator'] = 'field_type_of_accreditation_target_id_op';
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['expose']['identifier'] = 'field_type_of_accreditation_target_id';
  $handler->display->display_options['filters']['field_type_of_accreditation_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  /* Filter criterion: Field: Employer name (field_employer_name) */
  $handler->display->display_options['filters']['field_employer_name_value']['id'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['table'] = 'field_data_field_employer_name';
  $handler->display->display_options['filters']['field_employer_name_value']['field'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_employer_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_employer_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['operator_id'] = 'field_employer_name_value_op';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['label'] = 'Employer name (field_employer_name)';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['operator'] = 'field_employer_name_value_op';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['identifier'] = 'field_employer_name_value';
  /* Filter criterion: Content: Area(s) of Specialism (field_areas_of_specialism) */
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['id'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['table'] = 'field_data_field_areas_of_specialism';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['field'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['value'] = '';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['operator_id'] = 'field_areas_of_specialism_tid_op';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['label'] = 'Area(s) of Specialism';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['operator'] = 'field_areas_of_specialism_tid_op';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['identifier'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['vocabulary'] = 'areas_of_meteorology';
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Application submitted';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );

  /* Display: Page - Admin View */
  $handler = $view->new_display('page', 'Page - Admin View', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Application started';
  $handler->display->display_options['fields']['created']['date_format'] = 'long_date_no_time';
  /* Field: Content: Type of accreditation applying for (OLD) */
  $handler->display->display_options['fields']['field_type_of_accreditation']['id'] = 'field_type_of_accreditation';
  $handler->display->display_options['fields']['field_type_of_accreditation']['table'] = 'field_data_field_type_of_accreditation';
  $handler->display->display_options['fields']['field_type_of_accreditation']['field'] = 'field_type_of_accreditation';
  $handler->display->display_options['fields']['field_type_of_accreditation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_type_of_accreditation']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_type_of_accreditation']['group_columns'] = array(
    'bundle' => 'bundle',
  );
  /* Field: Content: Type of report submitting */
  $handler->display->display_options['fields']['field_crm_accreditation_type']['id'] = 'field_crm_accreditation_type';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['table'] = 'field_data_field_crm_accreditation_type';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['field'] = 'field_crm_accreditation_type';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['label'] = 'Type of accreditation applying for';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['alter']['text'] = '[field_crm_accreditation_type] ([field_type_of_accreditation])';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['empty'] = '-';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['type'] = 'rmets_cpd_accreditation_application_type_formatter';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['settings'] = array(
    'link_title' => 0,
  );
  /* Field: Content: Area(s) of Specialism */
  $handler->display->display_options['fields']['field_areas_of_specialism']['id'] = 'field_areas_of_specialism';
  $handler->display->display_options['fields']['field_areas_of_specialism']['table'] = 'field_data_field_areas_of_specialism';
  $handler->display->display_options['fields']['field_areas_of_specialism']['field'] = 'field_areas_of_specialism';
  $handler->display->display_options['fields']['field_areas_of_specialism']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_areas_of_specialism']['delta_offset'] = '0';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'View Application';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  $handler->display->display_options['fields']['edit_node_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node_1']['text'] = 'Edit User';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_accreditation_application' => 'cpd_accreditation_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Surname (field_surname) */
  $handler->display->display_options['filters']['field_surname_value']['id'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['table'] = 'field_data_field_surname';
  $handler->display->display_options['filters']['field_surname_value']['field'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_surname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_surname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_surname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_surname_value']['expose']['operator_id'] = 'field_surname_value_op';
  $handler->display->display_options['filters']['field_surname_value']['expose']['label'] = 'Surname';
  $handler->display->display_options['filters']['field_surname_value']['expose']['operator'] = 'field_surname_value_op';
  $handler->display->display_options['filters']['field_surname_value']['expose']['identifier'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Status (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['expose']['operator_id'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['label'] = 'Status (field_status)';
  $handler->display->display_options['filters']['field_status_value']['expose']['operator'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['identifier'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_status_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['field_status_value']['group_info']['identifier'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Draft',
      'operator' => '=',
      'value' => array(
        'value' => '2',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Awaiting Payment',
      'operator' => '=',
      'value' => array(
        'value' => '3',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'Pending',
      'operator' => '=',
      'value' => array(
        'value' => '4',
        'min' => '',
        'max' => '',
      ),
    ),
    4 => array(
      'title' => 'Assigning reviewers',
      'operator' => '=',
      'value' => array(
        'value' => '5',
        'min' => '',
        'max' => '',
      ),
    ),
    5 => array(
      'title' => 'Awaiting review',
      'operator' => '=',
      'value' => array(
        'value' => '6',
        'min' => '',
        'max' => '',
      ),
    ),
    6 => array(
      'title' => 'Review processing',
      'operator' => '=',
      'value' => array(
        'value' => '7',
        'min' => '',
        'max' => '',
      ),
    ),
    7 => array(
      'title' => 'Awaiting board review',
      'operator' => '=',
      'value' => array(
        'value' => '8',
        'min' => '',
        'max' => '',
      ),
    ),
    8 => array(
      'title' => 'Awaiting board decision',
      'operator' => '=',
      'value' => array(
        'value' => '9',
        'min' => '',
        'max' => '',
      ),
    ),
    9 => array(
      'title' => 'Unacceptable',
      'operator' => '=',
      'value' => array(
        'value' => '10',
        'min' => '',
        'max' => '',
      ),
    ),
    10 => array(
      'title' => 'Acceptable',
      'operator' => '=',
      'value' => array(
        'value' => '11',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Field: Employer name (field_employer_name) */
  $handler->display->display_options['filters']['field_employer_name_value']['id'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['table'] = 'field_data_field_employer_name';
  $handler->display->display_options['filters']['field_employer_name_value']['field'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_employer_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['operator_id'] = 'field_employer_name_value_op';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['label'] = 'Employer name';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['operator'] = 'field_employer_name_value_op';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['identifier'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_employer_name_value']['group_info']['label'] = 'Employer name (field_employer_name)';
  $handler->display->display_options['filters']['field_employer_name_value']['group_info']['identifier'] = 'field_employer_name_value';
  $handler->display->display_options['filters']['field_employer_name_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_employer_name_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Area(s) of Specialism (field_areas_of_specialism) */
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['id'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['table'] = 'field_data_field_areas_of_specialism';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['field'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['value'] = '';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['operator_id'] = 'field_areas_of_specialism_tid_op';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['label'] = 'Area(s) of Specialism';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['operator'] = 'field_areas_of_specialism_tid_op';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['identifier'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['vocabulary'] = 'areas_of_meteorology';
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Application submitted';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  $handler->display->display_options['path'] = 'admin/reports/cpd/accreditation';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Accreditation Applications';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page - Reviewer View */
  $handler = $view->new_display('page', 'Page - Reviewer View', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CPD Accreditation Application - Review';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_target_id']['field'] = 'field_user_target_id';
  /* Relationship: Content: Reviews (field_reviews) */
  $handler->display->display_options['relationships']['field_reviews_value']['id'] = 'field_reviews_value';
  $handler->display->display_options['relationships']['field_reviews_value']['table'] = 'field_data_field_reviews';
  $handler->display->display_options['relationships']['field_reviews_value']['field'] = 'field_reviews_value';
  $handler->display->display_options['relationships']['field_reviews_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_reviews_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reviewer_target_id']['id'] = 'field_reviewer_target_id';
  $handler->display->display_options['relationships']['field_reviewer_target_id']['table'] = 'field_data_field_reviewer';
  $handler->display->display_options['relationships']['field_reviewer_target_id']['field'] = 'field_reviewer_target_id';
  $handler->display->display_options['relationships']['field_reviewer_target_id']['relationship'] = 'field_reviews_value';
  $handler->display->display_options['relationships']['field_reviewer_target_id']['label'] = 'Reviewer';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Application started';
  $handler->display->display_options['fields']['created']['date_format'] = 'long_date_no_time';
  /* Field: Field collection item: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['relationship'] = 'field_reviews_value';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<a href="/cpd/review/application/[nid]" target="_blank">View Application</a>';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View Application';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_reviewer_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_accreditation_application' => 'cpd_accreditation_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Surname (field_surname) */
  $handler->display->display_options['filters']['field_surname_value']['id'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['table'] = 'field_data_field_surname';
  $handler->display->display_options['filters']['field_surname_value']['field'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_surname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_surname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_surname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_surname_value']['expose']['operator_id'] = 'field_surname_value_op';
  $handler->display->display_options['filters']['field_surname_value']['expose']['label'] = 'Surname';
  $handler->display->display_options['filters']['field_surname_value']['expose']['operator'] = 'field_surname_value_op';
  $handler->display->display_options['filters']['field_surname_value']['expose']['identifier'] = 'field_surname_value';
  $handler->display->display_options['filters']['field_surname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Area(s) of Specialism (field_areas_of_specialism) */
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['id'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['table'] = 'field_data_field_areas_of_specialism';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['field'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['value'] = '';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['operator_id'] = 'field_areas_of_specialism_tid_op';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['label'] = 'Area(s) of Specialism';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['operator'] = 'field_areas_of_specialism_tid_op';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['identifier'] = 'field_areas_of_specialism_tid';
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_areas_of_specialism_tid']['vocabulary'] = 'areas_of_meteorology';
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Application submitted';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Status (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['value']['value'] = '6';
  $handler->display->display_options['path'] = 'user/%/cpd/review/accreditations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Applications for Review';
  $handler->display->display_options['menu']['weight'] = '11';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cpd_accreditation_admin'] = $view;

  $view = new view();
  $view->name = 'cpd_accreditation_application_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'CPD Accreditation Application Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['label'] = '';
  $handler->display->display_options['fields']['sku']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([sku])';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Sort criterion: Commerce Product: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'commerce_product';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Commerce Product: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'rmets_accreditation_application' => 'rmets_accreditation_application',
  );
  /* Filter criterion: Commerce Product: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Entity Reference Accreditation Application */
  $handler = $view->new_display('entityreference', 'Entity Reference Accreditation Application', 'entityreference_accreditation_application');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'product_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([sku])';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;

  /* Display: Entity Reference Accreditation */
  $handler = $view->new_display('entityreference', 'Entity Reference Accreditation', 'entityreference_accreditation');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'sku' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Product: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'rmets_accreditation' => 'rmets_accreditation',
  );
  /* Filter criterion: Commerce Product: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $export['cpd_accreditation_application_products'] = $view;

  return $export;
}
