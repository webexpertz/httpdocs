<?php
/**
 * @file
 * rmets_cpd_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rmets_cpd_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer cpd section'.
  $permissions['administer cpd section'] = array(
    'name' => 'administer cpd section',
    'roles' => array(
      'administrator' => 'administrator',
      'membership secretary' => 'membership secretary',
    ),
    'module' => 'rmets_cpd',
  );

  // Exported permission: 'administer save and edit'.
  $permissions['administer save and edit'] = array(
    'name' => 'administer save and edit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'save_edit',
  );

  // Exported permission: 'create cpd_objective content'.
  $permissions['create cpd_objective content'] = array(
    'name' => 'create cpd_objective content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create cpd_record content'.
  $permissions['create cpd_record content'] = array(
    'name' => 'create cpd_record content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_cpd_report_submission_date'.
  $permissions['create field_cpd_report_submission_date'] = array(
    'name' => 'create field_cpd_report_submission_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_last_cpd_rep_remind_date'.
  $permissions['create field_last_cpd_rep_remind_date'] = array(
    'name' => 'create field_last_cpd_rep_remind_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_next_cpd_submission_date'.
  $permissions['create field_next_cpd_submission_date'] = array(
    'name' => 'create field_next_cpd_submission_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'delete own cpd_objective content'.
  $permissions['delete own cpd_objective content'] = array(
    'name' => 'delete own cpd_objective content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_cpd_report_submission_date'.
  $permissions['edit field_cpd_report_submission_date'] = array(
    'name' => 'edit field_cpd_report_submission_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_last_cpd_rep_remind_date'.
  $permissions['edit field_last_cpd_rep_remind_date'] = array(
    'name' => 'edit field_last_cpd_rep_remind_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_next_cpd_submission_date'.
  $permissions['edit field_next_cpd_submission_date'] = array(
    'name' => 'edit field_next_cpd_submission_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own cpd_objective content'.
  $permissions['edit own cpd_objective content'] = array(
    'name' => 'edit own cpd_objective content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cpd_record content'.
  $permissions['edit own cpd_record content'] = array(
    'name' => 'edit own cpd_record content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_cpd_report_submission_date'.
  $permissions['edit own field_cpd_report_submission_date'] = array(
    'name' => 'edit own field_cpd_report_submission_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_last_cpd_rep_remind_date'.
  $permissions['edit own field_last_cpd_rep_remind_date'] = array(
    'name' => 'edit own field_last_cpd_rep_remind_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_next_cpd_submission_date'.
  $permissions['edit own field_next_cpd_submission_date'] = array(
    'name' => 'edit own field_next_cpd_submission_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'use save and edit'.
  $permissions['use save and edit'] = array(
    'name' => 'use save and edit',
    'roles' => array(
      'administrator' => 'administrator',
      'content administrator' => 'content administrator',
      'member' => 'member',
      'membership secretary' => 'membership secretary',
      'order fulfilment' => 'order fulfilment',
    ),
    'module' => 'save_edit',
  );

  // Exported permission: 'use text format member_html'.
  $permissions['use text format member_html'] = array(
    'name' => 'use text format member_html',
    'roles' => array(
      'CPD Reviewer' => 'CPD Reviewer',
      'administrator' => 'administrator',
      'content administrator' => 'content administrator',
      'member' => 'member',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view cpd reports'.
  $permissions['view cpd reports'] = array(
    'name' => 'view cpd reports',
    'roles' => array(
      'CPD Reviewer' => 'CPD Reviewer',
      'CPD Senior Reviewer' => 'CPD Senior Reviewer',
      'administrator' => 'administrator',
      'cpd tester' => 'cpd tester',
      'membership secretary' => 'membership secretary',
    ),
    'module' => 'rmets_cpd',
  );

  // Exported permission: 'view edit other users cpd records'.
  $permissions['view edit other users cpd records'] = array(
    'name' => 'view edit other users cpd records',
    'roles' => array(
      'CPD Senior Reviewer' => 'CPD Senior Reviewer',
      'membership secretary' => 'membership secretary',
    ),
    'module' => 'rmets_cpd_records',
  );

  // Exported permission: 'view edit own cpd records'.
  $permissions['view edit own cpd records'] = array(
    'name' => 'view edit own cpd records',
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'membership secretary' => 'membership secretary',
    ),
    'module' => 'rmets_cpd_records',
  );

  // Exported permission: 'view field_cpd_report_submission_date'.
  $permissions['view field_cpd_report_submission_date'] = array(
    'name' => 'view field_cpd_report_submission_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_last_cpd_rep_remind_date'.
  $permissions['view field_last_cpd_rep_remind_date'] = array(
    'name' => 'view field_last_cpd_rep_remind_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_next_cpd_submission_date'.
  $permissions['view field_next_cpd_submission_date'] = array(
    'name' => 'view field_next_cpd_submission_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view other users cpd records'.
  $permissions['view other users cpd records'] = array(
    'name' => 'view other users cpd records',
    'roles' => array(
      'CPD Reviewer' => 'CPD Reviewer',
      'CPD Senior Reviewer' => 'CPD Senior Reviewer',
    ),
    'module' => 'rmets_cpd_records',
  );

  // Exported permission: 'view own field_cpd_report_submission_date'.
  $permissions['view own field_cpd_report_submission_date'] = array(
    'name' => 'view own field_cpd_report_submission_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_last_cpd_rep_remind_date'.
  $permissions['view own field_last_cpd_rep_remind_date'] = array(
    'name' => 'view own field_last_cpd_rep_remind_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_next_cpd_submission_date'.
  $permissions['view own field_next_cpd_submission_date'] = array(
    'name' => 'view own field_next_cpd_submission_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
