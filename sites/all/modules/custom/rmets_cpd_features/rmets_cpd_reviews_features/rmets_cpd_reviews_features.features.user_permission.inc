<?php
/**
 * @file
 * rmets_cpd_reviews_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rmets_cpd_reviews_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cpd_report_review content'.
  $permissions['create cpd_report_review content'] = array(
    'name' => 'create cpd_report_review content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cpd_report_review content'.
  $permissions['edit own cpd_report_review content'] = array(
    'name' => 'edit own cpd_report_review content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'review other users cpd reviews'.
  $permissions['review other users cpd reviews'] = array(
    'name' => 'review other users cpd reviews',
    'roles' => array(
      'CPD Reviewer' => 'CPD Reviewer',
      'CPD Senior Reviewer' => 'CPD Senior Reviewer',
      'administrator' => 'administrator',
    ),
    'module' => 'rmets_cpd_reviews',
  );

  // Exported permission: 'view edit other users cpd reviews'.
  $permissions['view edit other users cpd reviews'] = array(
    'name' => 'view edit other users cpd reviews',
    'roles' => array(
      'CPD Senior Reviewer' => 'CPD Senior Reviewer',
      'administrator' => 'administrator',
      'membership secretary' => 'membership secretary',
    ),
    'module' => 'rmets_cpd_reviews',
  );

  // Exported permission: 'view own cpd reviews'.
  $permissions['view own cpd reviews'] = array(
    'name' => 'view own cpd reviews',
    'roles' => array(
      'CPD Senior Reviewer' => 'CPD Senior Reviewer',
      'administrator' => 'administrator',
      'member' => 'member',
    ),
    'module' => 'rmets_cpd_reviews',
  );

  return $permissions;
}
