<?php
/**
 * @file
 */

/**
 * Helper function for the about CPD page.
 */
function rmets_cpd_about() {
  $node = node_load(variable_get('rmets_cpd_about_nid', ''));
  if (!$node) {
    return t('There is no \'CPD page\' defined.');
  }
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $body = $node_wrapper->body->value();
  return $body['value'];
}

/**
 * Helper function for the mycpd link.
 */
function rmets_cpd_my_cpd() {
  global $user;

  // User not logged in.
  if (!user_is_logged_in()) {
    drupal_goto('user', array('query' => array('destination' => '/accsys')));
    drupal_exit();
  }

  // Logged in user, but is not a member user.
  // Temporary role checking for 'cpd tester' role.
  $user_is_member = array_search('member', $user->roles);
  //$user_is_member = array_search('cpd tester', $user->roles);
  if (!$user_is_member) {
    drupal_set_message('You need to be a "member" to be able to access "ACCSYS".', 'warning');
    drupal_goto('membership/joining-society');
    drupal_exit();
  }

  drupal_goto('user/' . $user->uid . '/cpd');
  drupal_exit();
}