<?php
/**
 * @file
 * rmets_cpd_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function rmets_cpd_features_user_default_roles() {
  $roles = array();

  // Exported role: cpd tester.
  $roles['cpd tester'] = array(
    'name' => 'cpd tester',
    'weight' => 11,
  );

  return $roles;
}
