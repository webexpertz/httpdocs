<?php
/**
 * @file
 * Drush integration for rmets_cpd_accreditation.
 */

/**
 * Implements hook_drush_command().
 */
function rmets_cpd_accreditation_drush_command() {
  $items = array();

  $items['rmets-cpd-accreditation-order-test'] = array(
    'description' => 'Test the order.',
    'options' => array(
      'orderid' => 'The order id to test.'
    ),
  );
  $items['rmets-cpd-accreditation-test-send-reminder'] = array(
    'description' => 'Test the sending of CPD Application email reminder.',
    'options' => array(
      'userid' => 'The user id to test the sending of the email reminder. If this is not set then it will attempt to process all users.'
    ),
    'aliases' => array('rmets-cpdapp'),
  );

  return $items;
}

/**
 * Test the checkout process
 */
function drush_rmets_cpd_accreditation_order_test() {
  $order_id = drush_get_option('orderid', NULL);

  if (!$order_id) {
    print "You must supply an order id.\n";
    return;
  }

  print "Loading order id: $order_id\n";
  $order = commerce_order_load($order_id);
  rules_invoke_event('commerce_checkout_complete', $order);
}

/**
 * Test for sending CPD accreditation email reminders.
 *
 * Set the userid to send test against a specific user, otherwise it will send
 * to all.
 */
function drush_rmets_cpd_accreditation_test_send_reminder() {
  $user_id = drush_get_option('userid', NULL);

  if (!$user_id) {
    print "Send all user emails.\n";
    _rmets_cpd_accreditation_user_email_reminder();
    return;
  }

  print "Loading user id: $user_id\n";
  // Get a user.
  $user = user_load($user_id);
  $user_wrapper = entity_metadata_wrapper('user', $user);

  print "invoke reminder rule for: " . $user->name . " @ " . date('d/m/Y H:i:s') . "\n";
  print "user last sent date: {$user_wrapper->field_last_cpd_reminder_date->value()} (" . date('d/m/Y H:i:s', $user_wrapper->field_last_cpd_reminder_date->value()) . ")\n";

  // Send the user to the rule for sending emails.
  rules_invoke_event('rmets_cpd_accreditation_user_review_due_reminder', $user);

  // Reload the user to get the updated data.
  $user = user_load($user_id);
  $user_wrapper = entity_metadata_wrapper('user', $user);
  print "user last sent date: {$user_wrapper->field_last_cpd_reminder_date->value()} (" . date('d/m/Y H:i:s', $user_wrapper->field_last_cpd_reminder_date->value()) . ")\n";
}