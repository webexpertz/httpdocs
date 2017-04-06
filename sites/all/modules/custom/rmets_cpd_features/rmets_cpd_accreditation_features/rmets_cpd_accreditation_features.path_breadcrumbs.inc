<?php
/**
 * @file
 * rmets_cpd_accreditation_features.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function rmets_cpd_accreditation_features_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'cpd_application_view';
  $path_breadcrumb->name = 'CPD Application view';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:field-user:name',
      1 => 'My CPD',
      2 => 'Accreditation Applications',
      3 => '%node:title',
    ),
    'paths' => array(
      0 => '%node:field-user:url',
      1 => 'user/%node:field-user:uid/cpd',
      2 => 'user/%node:field-user:uid/cpd/accreditation',
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
              'cpd_accreditation_application' => 'cpd_accreditation_application',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -86;
  $export['cpd_application_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_add_cpd_accreditation_application';
  $path_breadcrumb->name = 'User Add CPD Accreditation Application';
  $path_breadcrumb->path = 'node/add/cpd-accreditation-application';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'Accreditation Applications',
      3 => 'Add Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/accreditation',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -91;
  $export['user_add_cpd_accreditation_application'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_cpd_accreditation';
  $path_breadcrumb->name = 'User CPD Accreditation';
  $path_breadcrumb->path = 'user/%user/cpd/accreditation';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'Accreditation Applications',
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
  $path_breadcrumb->weight = -97;
  $export['user_cpd_accreditation'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_edit_cpd_accreditation_application';
  $path_breadcrumb->name = 'User Edit CPD Accreditation Application';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-user:name',
      1 => 'My CPD',
      2 => 'Accreditation Applications',
      3 => 'Edit Record',
    ),
    'paths' => array(
      0 => '%site:url/users/%site:current-user:name',
      1 => '%site:url/user/%site:current-user:uid/cpd',
      2 => '%site:url/user/%site:current-user:uid/cpd/accreditation',
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
              'cpd_accreditation_application' => 'cpd_accreditation_application',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -87;
  $export['user_edit_cpd_accreditation_application'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_review_cpd_application';
  $path_breadcrumb->name = 'User Review CPD Application';
  $path_breadcrumb->path = 'cpd/review/application/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Accreditation Application Review',
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
              'cpd_accreditation_application' => 'cpd_accreditation_application',
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
  $export['user_review_cpd_application'] = $path_breadcrumb;

  return $export;
}
