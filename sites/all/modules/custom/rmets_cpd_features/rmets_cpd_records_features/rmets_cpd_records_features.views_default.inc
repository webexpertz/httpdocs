<?php
/**
 * @file
 * rmets_cpd_records_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rmets_cpd_records_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_users_cpd';
  $view->description = '';
  $view->tag = 'cpd';
  $view->base_table = 'node';
  $view->human_name = 'CPD Records - Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CPD Records';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view cpd reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_areas_of_meterology' => 'field_areas_of_meterology',
    'field_cpd_type' => 'field_cpd_type',
    'field_date_completed' => 'field_date_completed',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date_completed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_areas_of_meterology' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cpd_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_completed' => array(
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
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links">
  <li><a href="/node/add/cpd-objective?destination=user/%1/cpd/objective">Add content</a></li>
</ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_forenames']['label'] = 'Forename';
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: CPD Type */
  $handler->display->display_options['fields']['field_cpd_type']['id'] = 'field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['table'] = 'field_data_field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['field'] = 'field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Areas of Meteorology */
  $handler->display->display_options['fields']['field_areas_of_meterology']['id'] = 'field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['table'] = 'field_data_field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['field'] = 'field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['label'] = 'Area(s) of Meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_areas_of_meterology']['delta_offset'] = '0';
  /* Field: Content: Date completed */
  $handler->display->display_options['fields']['field_date_completed']['id'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['field'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['label'] = 'Date Completed';
  $handler->display->display_options['fields']['field_date_completed']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date completed (field_date_completed) */
  $handler->display->display_options['sorts']['field_date_completed_value']['id'] = 'field_date_completed_value';
  $handler->display->display_options['sorts']['field_date_completed_value']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['sorts']['field_date_completed_value']['field'] = 'field_date_completed_value';
  $handler->display->display_options['sorts']['field_date_completed_value']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_record' => 'cpd_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'CPD Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
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
  /* Filter criterion: Content: CPD Type (field_cpd_type) */
  $handler->display->display_options['filters']['field_cpd_type_tid']['id'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['table'] = 'field_data_field_cpd_type';
  $handler->display->display_options['filters']['field_cpd_type_tid']['field'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_cpd_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['operator_id'] = 'field_cpd_type_tid_op';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['label'] = 'CPD Type';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['operator'] = 'field_cpd_type_tid_op';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['identifier'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_cpd_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_cpd_type_tid']['vocabulary'] = 'cpd_type';
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
  );
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['vocabulary'] = 'areas_of_meteorology';
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
  );
  $handler->display->display_options['filters']['field_date_completed_value']['granularity'] = 'year';

  /* Display: Members CPD */
  $handler = $view->new_display('page', 'Members CPD', 'admin_members_cpd');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'admin/reports/cpd';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Members CPD';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'User CPD';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: CPD Record Page */
  $handler = $view->new_display('page', 'CPD Record Page', 'cpd_record_page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'admin/reports/cpd/records';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'CPD Records';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'User CPD';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: CPD Objective Page */
  $handler = $view->new_display('page', 'CPD Objective Page', 'cpd_objective');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Objective';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_areas_of_meterology' => 'field_areas_of_meterology',
    'field_cpd_type' => 'field_cpd_type',
    'field_date_completed' => 'field_date_completed',
    'field_planned_completion_date' => 'field_planned_completion_date',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_planned_completion_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_areas_of_meterology' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cpd_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_planned_completion_date' => array(
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
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Forenames */
  $handler->display->display_options['fields']['field_forenames']['id'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['table'] = 'field_data_field_forenames';
  $handler->display->display_options['fields']['field_forenames']['field'] = 'field_forenames';
  $handler->display->display_options['fields']['field_forenames']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_forenames']['label'] = 'Forename';
  /* Field: Field: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Planned completion date */
  $handler->display->display_options['fields']['field_planned_completion_date']['id'] = 'field_planned_completion_date';
  $handler->display->display_options['fields']['field_planned_completion_date']['table'] = 'field_data_field_planned_completion_date';
  $handler->display->display_options['fields']['field_planned_completion_date']['field'] = 'field_planned_completion_date';
  $handler->display->display_options['fields']['field_planned_completion_date']['settings'] = array(
    'format_type' => 'long_date_no_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date completed */
  $handler->display->display_options['fields']['field_date_completed']['id'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['field'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['label'] = 'Date Completed';
  $handler->display->display_options['fields']['field_date_completed']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_objective' => 'cpd_objective',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'CPD Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Planned completion date (field_planned_completion_date) */
  $handler->display->display_options['filters']['field_planned_completion_date_value']['id'] = 'field_planned_completion_date_value';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['table'] = 'field_data_field_planned_completion_date';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['field'] = 'field_planned_completion_date_value';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_planned_completion_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['operator_id'] = 'field_planned_completion_date_value_op';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['label'] = 'Planned completion date';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['operator'] = 'field_planned_completion_date_value_op';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['identifier'] = 'field_planned_completion_date_value';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_planned_completion_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['year_range'] = '-0:+3';
  /* Filter criterion: Content: Date completed (field_date_completed) */
  $handler->display->display_options['filters']['field_date_completed_value']['id'] = 'field_date_completed_value';
  $handler->display->display_options['filters']['field_date_completed_value']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['filters']['field_date_completed_value']['field'] = 'field_date_completed_value';
  $handler->display->display_options['filters']['field_date_completed_value']['operator'] = 'not empty';
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
  );
  $handler->display->display_options['filters']['field_date_completed_value']['form_type'] = 'date_text';
  $handler->display->display_options['path'] = 'admin/reports/cpd/objectives';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Objectives';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['admin_users_cpd'] = $view;

  $view = new view();
  $view->name = 'cpd_record';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CPD Record';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CPD Records';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'rmets_cpd_records_access_cpd';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_areas_of_meterology' => 'field_areas_of_meterology',
    'field_cpd_type' => 'field_cpd_type',
    'field_date_completed' => 'field_date_completed',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date_completed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_areas_of_meterology' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cpd_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_completed' => array(
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
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links">
  <li><a href="/node/add/cpd-objective?destination=user/%1/cpd/objective">Add content</a></li>
</ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No CPD records found.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title (Click title below to view or print individual records)';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: CPD Type */
  $handler->display->display_options['fields']['field_cpd_type']['id'] = 'field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['table'] = 'field_data_field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['field'] = 'field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Areas of Meteorology */
  $handler->display->display_options['fields']['field_areas_of_meterology']['id'] = 'field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['table'] = 'field_data_field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['field'] = 'field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['label'] = 'Area(s) of Meteorology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_areas_of_meterology']['delta_offset'] = '0';
  /* Field: Content: Areas of Competency */
  $handler->display->display_options['fields']['field_areas_of_competency']['id'] = 'field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['table'] = 'field_data_field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['field'] = 'field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['label'] = 'Area(s) of Competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_areas_of_competency']['delta_offset'] = '0';
  /* Field: Content: Date completed */
  $handler->display->display_options['fields']['field_date_completed']['id'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['field'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['label'] = 'Date Completed';
  $handler->display->display_options['fields']['field_date_completed']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_record' => 'cpd_record',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: CPD Type (field_cpd_type) */
  $handler->display->display_options['filters']['field_cpd_type_tid']['id'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['table'] = 'field_data_field_cpd_type';
  $handler->display->display_options['filters']['field_cpd_type_tid']['field'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_cpd_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['operator_id'] = 'field_cpd_type_tid_op';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['label'] = 'CPD Type';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['operator'] = 'field_cpd_type_tid_op';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['identifier'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_cpd_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_cpd_type_tid']['vocabulary'] = 'cpd_type';
  /* Filter criterion: Content: Areas of Meteorology (field_areas_of_meterology) */
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['id'] = 'field_areas_of_meterology_tid';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['table'] = 'field_data_field_areas_of_meterology';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['field'] = 'field_areas_of_meterology_tid';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['operator_id'] = 'field_areas_of_meterology_tid_op';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['label'] = 'Areas of Meteorology';
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
  );
  $handler->display->display_options['filters']['field_date_completed_value']['granularity'] = 'year';
  /* Filter criterion: Content: Objective reference (field_objective_references) */
  $handler->display->display_options['filters']['field_objective_references_target_id']['id'] = 'field_objective_references_target_id';
  $handler->display->display_options['filters']['field_objective_references_target_id']['table'] = 'field_data_field_objective_references';
  $handler->display->display_options['filters']['field_objective_references_target_id']['field'] = 'field_objective_references_target_id';
  $handler->display->display_options['filters']['field_objective_references_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_objective_references_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_objective_references_target_id']['expose']['operator_id'] = 'field_objective_references_target_id_op';
  $handler->display->display_options['filters']['field_objective_references_target_id']['expose']['label'] = 'Objective references';
  $handler->display->display_options['filters']['field_objective_references_target_id']['expose']['operator'] = 'field_objective_references_target_id_op';
  $handler->display->display_options['filters']['field_objective_references_target_id']['expose']['identifier'] = 'field_objective_references_target_id';
  $handler->display->display_options['filters']['field_objective_references_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_objective_references_target_id']['group_info']['label'] = 'Objective references (field_objective_references)';
  $handler->display->display_options['filters']['field_objective_references_target_id']['group_info']['identifier'] = 'field_objective_references_target_id';
  $handler->display->display_options['filters']['field_objective_references_target_id']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_objective_references_target_id']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: CPD Record Page */
  $handler = $view->new_display('page', 'CPD Record Page', 'cpd_record_page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'Intro text';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<p>[cpd_record_page_intro_text]</p>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/cpd-record?destination=user/!1/cpd/records&uid=!1" class="button-link">Add a New Record</a><h2>Your records</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['path'] = 'user/%/cpd/records';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'CPD Records';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: CPD Objective Page */
  $handler = $view->new_display('page', 'CPD Objective Page', 'cpd_objective_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CPD Objective';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_planned_completion_date' => 'field_planned_completion_date',
    'field_date_completed' => 'field_date_completed',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_planned_completion_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_planned_completion_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'Intro text';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<p>[cpd_objective_page_intro_text]</p>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  $handler->display->display_options['header']['area_1']['tokenize'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/cpd-objective?destination=user/!1/cpd/objectives&uid=!1" class="button-link">Create a New Objective</a><h2>Your objectives</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No CPD objectives were found.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title (Click title below to view or print individual records)';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Planned completion date */
  $handler->display->display_options['fields']['field_planned_completion_date']['id'] = 'field_planned_completion_date';
  $handler->display->display_options['fields']['field_planned_completion_date']['table'] = 'field_data_field_planned_completion_date';
  $handler->display->display_options['fields']['field_planned_completion_date']['field'] = 'field_planned_completion_date';
  $handler->display->display_options['fields']['field_planned_completion_date']['settings'] = array(
    'format_type' => 'long_date_no_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date completed */
  $handler->display->display_options['fields']['field_date_completed']['id'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['field'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['label'] = 'Date Completed';
  $handler->display->display_options['fields']['field_date_completed']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_objective' => 'cpd_objective',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'CPD Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Planned completion date (field_planned_completion_date) */
  $handler->display->display_options['filters']['field_planned_completion_date_value']['id'] = 'field_planned_completion_date_value';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['table'] = 'field_data_field_planned_completion_date';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['field'] = 'field_planned_completion_date_value';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_planned_completion_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['operator_id'] = 'field_planned_completion_date_value_op';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['label'] = 'Planned completion date';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['operator'] = 'field_planned_completion_date_value_op';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['identifier'] = 'field_planned_completion_date_value';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_planned_completion_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_planned_completion_date_value']['year_range'] = '-0:+3';
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
  );
  $handler->display->display_options['filters']['field_date_completed_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_completed_value']['year_range'] = '-0:+3';
  $handler->display->display_options['path'] = 'user/%/cpd/objectives';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Objectives';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $export['cpd_record'] = $view;

  $view = new view();
  $view->name = 'cpd_records_embedded';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CPD Records (embedded)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CPD Records';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '60';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20, 40, 60, 80, 100, 150, 200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_cpd_type' => 'field_cpd_type',
    'field_areas_of_meterology' => 'field_areas_of_meterology',
    'field_date_completed' => 'field_date_completed',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date_completed';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cpd_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_areas_of_meterology' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No CPD records found</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_records_target_id']['id'] = 'field_records_target_id';
  $handler->display->display_options['relationships']['field_records_target_id']['table'] = 'field_data_field_records';
  $handler->display->display_options['relationships']['field_records_target_id']['field'] = 'field_records_target_id';
  $handler->display->display_options['relationships']['field_records_target_id']['label'] = 'CPD Record (node)';
  $handler->display->display_options['relationships']['field_records_target_id']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a title="Open CPD in a new window" href="/cpd/review/record/[nid]" target="_blank">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: CPD Type */
  $handler->display->display_options['fields']['field_cpd_type']['id'] = 'field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['table'] = 'field_data_field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['field'] = 'field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['field_cpd_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Areas of Meteorology */
  $handler->display->display_options['fields']['field_areas_of_meterology']['id'] = 'field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['table'] = 'field_data_field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['field'] = 'field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['field_areas_of_meterology']['label'] = 'Area(s) of Meteorology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_areas_of_meterology']['delta_offset'] = '0';
  /* Field: Content: Areas of Competency */
  $handler->display->display_options['fields']['field_areas_of_competency']['id'] = 'field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['table'] = 'field_data_field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['field'] = 'field_areas_of_competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['field_areas_of_competency']['label'] = 'Area(s) of Competency';
  $handler->display->display_options['fields']['field_areas_of_competency']['delta_offset'] = '0';
  /* Field: Content: Date completed */
  $handler->display->display_options['fields']['field_date_completed']['id'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['field'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['field_date_completed']['label'] = 'Date Completed';
  $handler->display->display_options['fields']['field_date_completed']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Date completed (field_date_completed) */
  $handler->display->display_options['sorts']['field_date_completed_value']['id'] = 'field_date_completed_value';
  $handler->display->display_options['sorts']['field_date_completed_value']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['sorts']['field_date_completed_value']['field'] = 'field_date_completed_value';
  $handler->display->display_options['sorts']['field_date_completed_value']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['sorts']['field_date_completed_value']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_records_target_id';
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
    11 => 0,
  );
  /* Filter criterion: Content: CPD Type (field_cpd_type) */
  $handler->display->display_options['filters']['field_cpd_type_tid']['id'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['table'] = 'field_data_field_cpd_type';
  $handler->display->display_options['filters']['field_cpd_type_tid']['field'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['filters']['field_cpd_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_cpd_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['operator_id'] = 'field_cpd_type_tid_op';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['label'] = 'CPD Type';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['operator'] = 'field_cpd_type_tid_op';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['identifier'] = 'field_cpd_type_tid';
  $handler->display->display_options['filters']['field_cpd_type_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_cpd_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_cpd_type_tid']['vocabulary'] = 'cpd_type';
  /* Filter criterion: Content: Areas of Meteorology (field_areas_of_meterology) */
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['id'] = 'field_areas_of_meterology_tid';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['table'] = 'field_data_field_areas_of_meterology';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['field'] = 'field_areas_of_meterology_tid';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['operator_id'] = 'field_areas_of_meterology_tid_op';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['expose']['label'] = 'Areas of Meteorology';
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
    11 => 0,
  );
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_areas_of_meterology_tid']['vocabulary'] = 'areas_of_meteorology';
  /* Filter criterion: Content: Areas of Competency (field_areas_of_competency) */
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['id'] = 'field_areas_of_competency_tid';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['table'] = 'field_data_field_areas_of_competency';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['field'] = 'field_areas_of_competency_tid';
  $handler->display->display_options['filters']['field_areas_of_competency_tid']['relationship'] = 'field_records_target_id';
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

  /* Display: Embedded Records */
  $handler = $view->new_display('block', 'Embedded Records', 'embedded');

  /* Display: Embedded Records (Print) */
  $handler = $view->new_display('block', 'Embedded Records (Print)', 'embedded_print');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_cpd_type' => 'field_cpd_type',
    'field_areas_of_meterology' => 'field_areas_of_meterology',
    'field_date_completed' => 'field_date_completed',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date_completed';
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
    'field_cpd_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_areas_of_meterology' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_completed' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a title="Open CPD in a new window" href="/node/[nid]" target="_blank">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: CPD Type */
  $handler->display->display_options['fields']['field_cpd_type']['id'] = 'field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['table'] = 'field_data_field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['field'] = 'field_cpd_type';
  $handler->display->display_options['fields']['field_cpd_type']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['field_cpd_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Areas of Meteorology */
  $handler->display->display_options['fields']['field_areas_of_meterology']['id'] = 'field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['table'] = 'field_data_field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['field'] = 'field_areas_of_meterology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['field_areas_of_meterology']['label'] = 'Area(s) of Meteorology';
  $handler->display->display_options['fields']['field_areas_of_meterology']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_areas_of_meterology']['delta_offset'] = '0';
  /* Field: Content: Date completed */
  $handler->display->display_options['fields']['field_date_completed']['id'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['table'] = 'field_data_field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['field'] = 'field_date_completed';
  $handler->display->display_options['fields']['field_date_completed']['relationship'] = 'field_records_target_id';
  $handler->display->display_options['fields']['field_date_completed']['label'] = 'Date Completed';
  $handler->display->display_options['fields']['field_date_completed']['settings'] = array(
    'format_type' => 'month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $export['cpd_records_embedded'] = $view;

  $view = new view();
  $view->name = 'cpd_user_objectives';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CPD User Objectives';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view edit own cpd records';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'rmets_cpd_records_user_objectives';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpd_objective' => 'cpd_objective',
  );

  /* Display: CPD Objectives Entity Reference */
  $handler = $view->new_display('entityreference', 'CPD Objectives Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['cpd_user_objectives'] = $view;

  return $export;
}
