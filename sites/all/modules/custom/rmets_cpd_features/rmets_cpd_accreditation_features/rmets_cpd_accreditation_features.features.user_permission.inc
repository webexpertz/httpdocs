<?php
/**
 * @file
 * rmets_cpd_accreditation_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rmets_cpd_accreditation_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cpd_accreditation_application content'.
  $permissions['create cpd_accreditation_application content'] = array(
    'name' => 'create cpd_accreditation_application content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_crm_accred_app_id'.
  $permissions['create field_crm_accred_app_id'] = array(
    'name' => 'create field_crm_accred_app_id',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_last_cpd_reminder_date'.
  $permissions['create field_last_cpd_reminder_date'] = array(
    'name' => 'create field_last_cpd_reminder_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_type_of_accreditation'.
  $permissions['create field_type_of_accreditation'] = array(
    'name' => 'create field_type_of_accreditation',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_crm_accred_app_id'.
  $permissions['edit field_crm_accred_app_id'] = array(
    'name' => 'edit field_crm_accred_app_id',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_last_cpd_reminder_date'.
  $permissions['edit field_last_cpd_reminder_date'] = array(
    'name' => 'edit field_last_cpd_reminder_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_type_of_accreditation'.
  $permissions['edit field_type_of_accreditation'] = array(
    'name' => 'edit field_type_of_accreditation',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own cpd_accreditation_application content'.
  $permissions['edit own cpd_accreditation_application content'] = array(
    'name' => 'edit own cpd_accreditation_application content',
    'roles' => array(
      'member' => 'member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_crm_accred_app_id'.
  $permissions['edit own field_crm_accred_app_id'] = array(
    'name' => 'edit own field_crm_accred_app_id',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_last_cpd_reminder_date'.
  $permissions['edit own field_last_cpd_reminder_date'] = array(
    'name' => 'edit own field_last_cpd_reminder_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_type_of_accreditation'.
  $permissions['edit own field_type_of_accreditation'] = array(
    'name' => 'edit own field_type_of_accreditation',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'review other users cpd accreditation applications'.
  $permissions['review other users cpd accreditation applications'] = array(
    'name' => 'review other users cpd accreditation applications',
    'roles' => array(
      'CPD Reviewer' => 'CPD Reviewer',
      'CPD Senior Reviewer' => 'CPD Senior Reviewer',
      'administrator' => 'administrator',
      'membership secretary' => 'membership secretary',
    ),
    'module' => 'rmets_cpd_accreditation',
  );

  // Exported permission: 'view any commerce_product entity of bundle rmets_accreditation_application'.
  $permissions['view any commerce_product entity of bundle rmets_accreditation_application'] = array(
    'name' => 'view any commerce_product entity of bundle rmets_accreditation_application',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view edit other users cpd accreditation applications'.
  $permissions['view edit other users cpd accreditation applications'] = array(
    'name' => 'view edit other users cpd accreditation applications',
    'roles' => array(
      'CPD Reviewer' => 'CPD Reviewer',
      'CPD Senior Reviewer' => 'CPD Senior Reviewer',
      'administrator' => 'administrator',
      'membership secretary' => 'membership secretary',
    ),
    'module' => 'rmets_cpd_accreditation',
  );

  // Exported permission: 'view edit own cpd accreditation applications'.
  $permissions['view edit own cpd accreditation applications'] = array(
    'name' => 'view edit own cpd accreditation applications',
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
    ),
    'module' => 'rmets_cpd_accreditation',
  );

  // Exported permission: 'view field_crm_accred_app_id'.
  $permissions['view field_crm_accred_app_id'] = array(
    'name' => 'view field_crm_accred_app_id',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_last_cpd_reminder_date'.
  $permissions['view field_last_cpd_reminder_date'] = array(
    'name' => 'view field_last_cpd_reminder_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_type_of_accreditation'.
  $permissions['view field_type_of_accreditation'] = array(
    'name' => 'view field_type_of_accreditation',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_crm_accred_app_id'.
  $permissions['view own field_crm_accred_app_id'] = array(
    'name' => 'view own field_crm_accred_app_id',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_last_cpd_reminder_date'.
  $permissions['view own field_last_cpd_reminder_date'] = array(
    'name' => 'view own field_last_cpd_reminder_date',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_type_of_accreditation'.
  $permissions['view own field_type_of_accreditation'] = array(
    'name' => 'view own field_type_of_accreditation',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  return $permissions;
}
