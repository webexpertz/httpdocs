<?php
/**
 * @file
 * rmets_committee_document.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rmets_committee_document_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'committee_meeting_papers';
  $view->description = 'A list of papers uploaded to a committee meeting';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Committee meeting papers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Committee meeting papers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_document_archived',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_document_file' => 'field_document_file',
    'edit_node' => 'edit_node',
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No documents have been uploaded for this committee meeting';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Document file */
  $handler->display->display_options['fields']['field_document_file']['id'] = 'field_document_file';
  $handler->display->display_options['fields']['field_document_file']['table'] = 'field_data_field_document_file';
  $handler->display->display_options['fields']['field_document_file']['field'] = 'field_document_file';
  $handler->display->display_options['fields']['field_document_file']['label'] = '';
  $handler->display->display_options['fields']['field_document_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_file']['click_sort_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '[edit]';
  /* Field: Content: Archived */
  $handler->display->display_options['fields']['field_document_archived']['id'] = 'field_document_archived';
  $handler->display->display_options['fields']['field_document_archived']['table'] = 'field_data_field_document_archived';
  $handler->display->display_options['fields']['field_document_archived']['field'] = 'field_document_archived';
  $handler->display->display_options['fields']['field_document_archived']['label'] = '';
  $handler->display->display_options['fields']['field_document_archived']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_document_archived']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Archived (field_document_archived) */
  $handler->display->display_options['sorts']['field_document_archived_value']['id'] = 'field_document_archived_value';
  $handler->display->display_options['sorts']['field_document_archived_value']['table'] = 'field_data_field_document_archived';
  $handler->display->display_options['sorts']['field_document_archived_value']['field'] = 'field_document_archived_value';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = '1';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Meeting reference (field_meeting_reference) */
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['id'] = 'field_meeting_reference_target_id';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['table'] = 'field_data_field_meeting_reference';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['field'] = 'field_meeting_reference_target_id';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['validate_options']['types'] = array(
    'committee_meeting' => 'committee_meeting',
  );
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['field_meeting_reference_target_id']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'committee_document' => 'committee_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;

  /* Display: Committee meeting papers block */
  $handler = $view->new_display('block', 'Committee meeting papers block', 'block');
  $handler->display->display_options['display_description'] = 'A list of committee papers. This block should be embedded on the meeting page';
  $export['committee_meeting_papers'] = $view;

  $view = new view();
  $view->name = 'committee_meetings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Committee Meetings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Committee Meetings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There are no meetings for this committee. If you are a member of the committee you can create a new meeting using the link above.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date of meeting (field_meeting_date) */
  $handler->display->display_options['sorts']['field_meeting_date_value']['id'] = 'field_meeting_date_value';
  $handler->display->display_options['sorts']['field_meeting_date_value']['table'] = 'field_data_field_meeting_date';
  $handler->display->display_options['sorts']['field_meeting_date_value']['field'] = 'field_meeting_date_value';
  $handler->display->display_options['sorts']['field_meeting_date_value']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1 Meetings';
  $handler->display->display_options['arguments']['tid']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['breadcrumb'] = '%2';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'committees' => 'committees',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'committee_meeting' => 'committee_meeting',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Committee Meetings */
  $handler = $view->new_display('page', 'Committee Meetings', 'page');
  $handler->display->display_options['display_description'] = 'A list of committee meetings filtered by committee';
  $handler->display->display_options['path'] = 'committee-papers/%';
  $export['committee_meetings'] = $view;

  $view = new view();
  $view->name = 'committees';
  $view->description = 'List of committees';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Committee Papers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Committee Papers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'committee-papers/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'committees' => 'committees',
  );

  /* Display: committee_paper_terms */
  $handler = $view->new_display('page', 'committee_paper_terms', 'page');
  $handler->display->display_options['display_description'] = 'Page listing committees linked to their minutes';
  $handler->display->display_options['path'] = 'committee-papers';
  $export['committees'] = $view;

  return $export;
}
