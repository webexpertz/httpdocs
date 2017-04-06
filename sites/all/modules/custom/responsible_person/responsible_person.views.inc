<?php

/**
 * @file
 * Views integration file for Scheduler module.
 */

function responsible_person_views_data() {
  $tables['responsible_person']['table']['group'] = t('Responsible person');

  // how is the responsible_person table linked to the nodes
  $tables['responsible_person']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );

  // description of the fields (table columns)
  $tables['responsible_person']['uid'] = array(
    'title' => t('Responsible person'),
    'help' => t('Who is responsible for the content'),
    'relationship' => array(
      'title' => t('Responsible person'),
      'help' => t('Relate content to the user who is responsible'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('responsible'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
      'label' => t('Responsible person'),
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


  return $tables;
}

