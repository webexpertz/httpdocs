<?php
/**
 * @file
 * rmets_cpd_reviews_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rmets_cpd_reviews_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cpd_reviewers';
  $view->description = '';
  $view->tag = 'CPD';
  $view->base_table = 'users';
  $view->human_name = 'CPD Reviewers';
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
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    10 => '10',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['cpd_reviewers'] = $view;

  $view = new view();
  $view->name = 'cpd_reviews';
  $view->description = '';
  $view->tag = 'CPD';
  $view->base_table = 'node';
  $view->human_name = 'CPD Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CPD Reports';
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
  $handler->display->display_options['header']['area_1']['content'] = '<p>[cpd_report_page_intro_text]</p>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Add button';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/cpd-report-review?destination=user/!1/cpd/reports&field_user=!1" class="button-link">Create new CPD Report</a><h2>Your reports</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No CPD reports found.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
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
  $handler->display->display_options['fields']['created']['label'] = 'Date Started';
  $handler->display->display_options['fields']['created']['date_format'] = 'long_date_no_time';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['type'] = 'rmets_cpd_node_status_formatter';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'cpd_report_review' => 'cpd_report_review',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'cpd_report_page');
  $handler->display->display_options['path'] = 'user/%/cpd/reports';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'CPD Reports';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cpd_reviews'] = $view;

  $view = new view();
  $view->name = 'cpd_reviews_admin';
  $view->description = '';
  $view->tag = 'CPD';
  $view->base_table = 'node';
  $view->human_name = 'CPD Reports - Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CPD Reports - Admin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
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
    'title' => 'title',
    'field_forenames' => 'field_forenames',
    'field_last_name' => 'field_last_name',
    'mail' => 'mail',
    'created' => 'created',
    'field_status' => 'field_status',
    'edit_node' => 'edit_node',
    'edit_node_1' => 'edit_node_1',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
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
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
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
    'cpd_report_review' => 'cpd_report_review',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Forenames (field_forenames) */
  $handler->display->display_options['filters']['field_forenames_value']['id'] = 'field_forenames_value';
  $handler->display->display_options['filters']['field_forenames_value']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['filters']['field_forenames_value']['field'] = 'field_forenames_value';
  $handler->display->display_options['filters']['field_forenames_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_forenames_value']['group'] = 1;
  $handler->display->display_options['filters']['field_forenames_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_forenames_value']['expose']['operator_id'] = 'field_forenames_value_op';
  $handler->display->display_options['filters']['field_forenames_value']['expose']['label'] = 'Forename';
  $handler->display->display_options['filters']['field_forenames_value']['expose']['operator'] = 'field_forenames_value_op';
  $handler->display->display_options['filters']['field_forenames_value']['expose']['identifier'] = 'field_forenames_value';
  $handler->display->display_options['filters']['field_forenames_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
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
      'title' => 'Pending',
      'operator' => '=',
      'value' => array(
        'value' => '4',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'Assigning reviewers',
      'operator' => '=',
      'value' => array(
        'value' => '5',
        'min' => '',
        'max' => '',
      ),
    ),
    4 => array(
      'title' => 'Awaiting review',
      'operator' => '=',
      'value' => array(
        'value' => '6',
        'min' => '',
        'max' => '',
      ),
    ),
    5 => array(
      'title' => 'Review processing',
      'operator' => '=',
      'value' => array(
        'value' => '7',
        'min' => '',
        'max' => '',
      ),
    ),
    6 => array(
      'title' => 'Awaiting board review',
      'operator' => '=',
      'value' => array(
        'value' => '8',
        'min' => '',
        'max' => '',
      ),
    ),
    7 => array(
      'title' => 'Awaiting board decision',
      'operator' => '=',
      'value' => array(
        'value' => '9',
        'min' => '',
        'max' => '',
      ),
    ),
    8 => array(
      'title' => 'Unacceptable',
      'operator' => '=',
      'value' => array(
        'value' => '10',
        'min' => '',
        'max' => '',
      ),
    ),
    9 => array(
      'title' => 'Acceptable',
      'operator' => '=',
      'value' => array(
        'value' => '11',
        'min' => '',
        'max' => '',
      ),
    ),
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
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['label'] = 'Forename';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date Started';
  $handler->display->display_options['fields']['created']['date_format'] = 'long_date_no_time';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Type of accreditation applying for */
  $handler->display->display_options['fields']['field_crm_accreditation_type']['id'] = 'field_crm_accreditation_type';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['table'] = 'field_data_field_crm_accreditation_type';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['field'] = 'field_crm_accreditation_type';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['label'] = 'Type of report submitting';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['type'] = 'rmets_cpd_accreditation_application_type_formatter';
  $handler->display->display_options['fields']['field_crm_accreditation_type']['settings'] = array(
    'link_title' => 0,
  );
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
  $handler->display->display_options['fields']['edit_node']['text'] = 'View Report';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  $handler->display->display_options['fields']['edit_node_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node_1']['text'] = 'Edit User';
  $handler->display->display_options['path'] = 'admin/reports/cpd/reports';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'CPD Reports';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page - Reviewer View */
  $handler = $view->new_display('page', 'Page - Reviewer View', 'page_1');
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
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<a href="/cpd/review/report/[nid]" target="_blank">View CPD Report</a>';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View Report';
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
    'cpd_report_review' => 'cpd_report_review',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Forenames (field_forenames) */
  $handler->display->display_options['filters']['field_forenames_value']['id'] = 'field_forenames_value';
  $handler->display->display_options['filters']['field_forenames_value']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['filters']['field_forenames_value']['field'] = 'field_forenames_value';
  $handler->display->display_options['filters']['field_forenames_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_forenames_value']['group'] = 1;
  $handler->display->display_options['filters']['field_forenames_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_forenames_value']['expose']['operator_id'] = 'field_forenames_value_op';
  $handler->display->display_options['filters']['field_forenames_value']['expose']['label'] = 'Forename';
  $handler->display->display_options['filters']['field_forenames_value']['expose']['operator'] = 'field_forenames_value_op';
  $handler->display->display_options['filters']['field_forenames_value']['expose']['identifier'] = 'field_forenames_value';
  $handler->display->display_options['filters']['field_forenames_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Last Name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_status_value']['expose']['operator_id'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['label'] = 'Status (field_status)';
  $handler->display->display_options['filters']['field_status_value']['expose']['operator'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['identifier'] = 'field_status_value';
  $handler->display->display_options['path'] = 'user/%/cpd/review/reports';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'CPD Reports for Review';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cpd_reviews_admin'] = $view;

  $view = new view();
  $view->name = 'cpd_reviews_records_reference_widget_';
  $view->description = '';
  $view->tag = 'CPD';
  $view->base_table = 'node';
  $view->human_name = 'CPD Records Reference Widget';
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
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'You can use the filters at the top to find the CPD Records that you require.<br />
To select which CPD Records you want to be included with this submission, click the relevant checkboxes individually (or scroll down and click on \'Select All Displayed CPD Records\') this will automatically add CPD Records. To remove CPD Records deselect. Once you finished click the \'Close\' button to return to the form.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>There are no CPD Records found matching your search criteria.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = 'Add to form';
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['submit_on_selection'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'CPD Record Title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'user/!1/cpd/records/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Areas of Competency */
  $handler->display->display_options['fields']['field_areas_of_competency']['id'] = 'field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['table'] = 'field_data_field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['field'] = 'field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_record' => 'cpd_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Areas of Meteorology (field_areas_of_meterology) */
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['id'] = 'field_areas_of_meterology_tid';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['table'] = 'field_data_field_areas_of_meterology';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['field'] = 'field_areas_of_meterology_tid';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['operator_id'] = 'field_areas_of_meterology_tid_op';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['label'] = 'Areas of Meterology';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['operator'] = 'field_areas_of_meterology_tid_op';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['identifier'] = 'field_areas_of_meterology_tid';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['vocabulary'] = 'areas_of_meteorology';
  /* Filter criterion: Content: Areas of Competency (field_areas_of_competency) */
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['id'] = 'field_areas_of_competency_tid';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['table'] = 'field_data_field_areas_of_competency';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['field'] = 'field_areas_of_competency_tid';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['expose']['operator_id'] = 'field_areas_of_competency_tid_op';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['expose']['label'] = 'Areas of Competency';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['expose']['operator'] = 'field_areas_of_competency_tid_op';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['expose']['identifier'] = 'field_areas_of_competency_tid';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['vocabulary'] = 'areas_of_competency';
  /* Filter criterion: Content: Date completed (field_date_completed) */
  $handler->display->display_options['filters']['field_date_completed_value']['id'] = 'field_date_completed_value';
  $handler->display->display_options['filters']['field_date_completed_value']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['filters']['field_date_completed_value']['field'] = 'field_date_completed_value';
  $handler->display->display_options['filters']['field_date_completed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_completed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_completed_value']['expose']['operator_id'] = 'field_date_completed_value_op';
  $handler->display->display_options['filters']['field_date_completed_value']['expose']['label'] = 'Date completed';
  $handler->display->display_options['filters']['field_date_completed_value']['expose']['operator'] = 'field_date_completed_value_op';
  $handler->display->display_options['filters']['field_date_completed_value']['expose']['identifier'] = 'field_date_completed_value';
  $handler->display->display_options['filters']['field_date_completed_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_date_completed_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_date_completed_value']['year_range'] = '-100:+5';

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['hide_left'] = 0;
  $export['cpd_reviews_records_reference_widget_'] = $view;

  return $export;
}
