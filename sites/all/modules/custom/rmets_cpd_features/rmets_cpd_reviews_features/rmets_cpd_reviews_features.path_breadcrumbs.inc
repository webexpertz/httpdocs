<?php
/**
 * @file
 * rmets_cpd_reviews_features.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function rmets_cpd_reviews_features_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'cpd_record_view';
  $path_breadcrumb->name = 'CPD Record';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:author:name',
      1 => 'My CPD',
      2 => 'CPD Records',
      3 => '%node:title',
    ),
    'paths' => array(
      0 => '%node:author:url',
      1 => 'user/%node:author:uid/cpd',
      2 => 'user/%node:author:uid/cpd/records',
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
  $path_breadcrumb->weight = -83;
  $export['cpd_record_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_add_cpd_report';
  $path_breadcrumb->name = 'User Add CPD Report';
  $path_breadcrumb->path = 'node/add/cpd-report-review';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'CPD Report',
      3 => 'Add Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/reviews',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -92;
  $export['user_add_cpd_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_cpd_reviews';
  $path_breadcrumb->name = 'User CPD Reports';
  $path_breadcrumb->path = 'user/%user/cpd/reports';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'CPD Reports',
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
  $path_breadcrumb->weight = -96;
  $export['user_cpd_reviews'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_edit_cpd_reviews';
  $path_breadcrumb->name = 'User Edit CPD Reports';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'CPD Reports',
      3 => 'Edit Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/reports',
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
  $path_breadcrumb->weight = -88;
  $export['user_edit_cpd_reviews'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_review_cpd_report';
  $path_breadcrumb->name = 'User Review CPD Report';
  $path_breadcrumb->path = 'cpd/review/report/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'CPD Report Review',
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
  $path_breadcrumb->weight = -82;
  $export['user_review_cpd_report'] = $path_breadcrumb;

  return $export;
}
