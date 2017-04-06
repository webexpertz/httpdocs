<?php
/**
 * @file
 * rmets_cpd_reviews_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function rmets_cpd_reviews_features_user_default_roles() {
  $roles = array();

  // Exported role: CPD Reviewer.
  $roles['CPD Reviewer'] = array(
    'name' => 'CPD Reviewer',
    'weight' => 10,
  );

  // Exported role: CPD Senior Reviewer.
  $roles['CPD Senior Reviewer'] = array(
    'name' => 'CPD Senior Reviewer',
    'weight' => 12,
  );

  // Exported role: anonymous user.
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
    'weight' => 0,
  );

  // Exported role: authenticated user.
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
    'weight' => 2,
  );

  return $roles;
}
