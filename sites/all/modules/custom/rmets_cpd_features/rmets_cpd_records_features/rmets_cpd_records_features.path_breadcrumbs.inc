<?php
/**
 * @file
 * rmets_cpd_records_features.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function rmets_cpd_records_features_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'cpd_objectives';
  $path_breadcrumb->name = 'CPD Objectives';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:author:name',
      1 => 'My CPD',
      2 => 'CPD Objectives',
      3 => '%node:title',
    ),
    'paths' => array(
      0 => '%node:author:url',
      1 => 'user/%node:author:uid/cpd',
      2 => 'user/%node:author:uid/cpd/objectives',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'cpd_objective' => 'cpd_objective',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -84;
  $export['cpd_objectives'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'cpd_report';
  $path_breadcrumb->name = 'CPD Report';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:field-user:name',
      1 => 'My CPD',
      2 => 'CPD Reports',
      3 => '%node:title',
    ),
    'paths' => array(
      0 => '%node:field-user:url',
      1 => 'user/%node:field-user:uid/cpd',
      2 => 'user/%node:field-user:uid/cpd/reports',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'cpd_report_review' => 'cpd_report_review',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -85;
  $export['cpd_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_add_cpd_objective';
  $path_breadcrumb->name = 'User Add CPD Objectives';
  $path_breadcrumb->path = 'node/add/cpd-objective';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'Objectives',
      3 => 'Add Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/objectives',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -93;
  $export['user_add_cpd_objective'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_add_cpd_record';
  $path_breadcrumb->name = 'User Add CPD Record';
  $path_breadcrumb->path = 'node/add/cpd-record';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'CPD Records',
      3 => 'Add Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/records',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -95;
  $export['user_add_cpd_record'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_add_cpd_record_event';
  $path_breadcrumb->name = 'User Add CPD Record From Event';
  $path_breadcrumb->path = 'node/add/cpd-record/event/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'CPD Records',
      3 => 'Add Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/records',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 4,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -94;
  $export['user_add_cpd_record_event'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_cpd';
  $path_breadcrumb->name = 'User CPD';
  $path_breadcrumb->path = 'user/%user/cpd';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
    ),
    'paths' => array(
      0 => '%site:url/users/%user:name',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -100;
  $export['user_cpd'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_cpd_objectives';
  $path_breadcrumb->name = 'User CPD Objectives';
  $path_breadcrumb->path = 'user/%user/cpd/objectives';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'Objectives',
    ),
    'paths' => array(
      0 => '%site:url/users/%user:name',
      1 => '%site:url/users/%user:uid',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -98;
  $export['user_cpd_objectives'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_cpd_records';
  $path_breadcrumb->name = 'User CPD Records';
  $path_breadcrumb->path = 'user/%user/cpd/records';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'CPD Records',
    ),
    'paths' => array(
      0 => '%site:url/users/%user:name',
      1 => '%site:url/users/%user:uid',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -99;
  $export['user_cpd_records'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_edit_cpd_objective';
  $path_breadcrumb->name = 'User Edit CPD Objective';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'Objectives',
      3 => 'Edit Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/objectives',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'node_edit',
        'settings' => array(
          'identifier' => 'Node edit form: node ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'cpd_objective' => 'cpd_objective',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -89;
  $export['user_edit_cpd_objective'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_edit_cpd_record';
  $path_breadcrumb->name = 'User Edit CPD Record';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'CPD Records',
      3 => 'Edit Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/records',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'node_edit',
        'settings' => array(
          'identifier' => 'Node edit form: node ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'cpd_record' => 'cpd_record',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $path_breadcrumb->weight = -90;
  $export['user_edit_cpd_record'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_review_cpd_record';
  $path_breadcrumb->name = 'User Review CPD Record';
  $path_breadcrumb->path = 'cpd/review/record/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'CPD Record Review',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 3,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'cpd_record' => 'cpd_record',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -82;
  $export['user_review_cpd_record'] = $path_breadcrumb;

  return $export;
}
