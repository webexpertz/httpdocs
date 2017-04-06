<?php

/**
 * @file
 * System level drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function rmets_system_drush_command() {
  $items = array();

  $items['rtest'] = array(
    'description' => 'A test function',
    'aliases' => array('rt'),
    'examples' => array(
      'drush rt' => 'Run the mystery test function. Dont do this unless you know what you are doing.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
  );
  return $items;
}

function drush_rmets_system_rtest() {
  drush_print_r(rmets_system_get_membership_number());
}
