<?php
/**
 * @file
 * rmets_system.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function rmets_system_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 9,
  );

  // Exported role: committee editor.
  $roles['committee editor'] = array(
    'name' => 'committee editor',
    'weight' => 4,
  );

  // Exported role: content administrator.
  $roles['content administrator'] = array(
    'name' => 'content administrator',
    'weight' => 8,
  );

  // Exported role: member.
  $roles['member'] = array(
    'name' => 'member',
    'weight' => 3,
  );

  // Exported role: membership secretary.
  $roles['membership secretary'] = array(
    'name' => 'membership secretary',
    'weight' => 6,
  );

  // Exported role: order fulfilment.
  $roles['order fulfilment'] = array(
    'name' => 'order fulfilment',
    'weight' => 5,
  );

  // Exported role: responsible_person.
  $roles['responsible_person'] = array(
    'name' => 'responsible_person',
    'weight' => 7,
  );

  return $roles;
}
