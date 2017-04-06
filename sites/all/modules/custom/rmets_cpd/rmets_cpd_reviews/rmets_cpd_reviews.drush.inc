<?php
/**
 * @file
 * Drush integration for rmets_cpd_reviews.
 */

/**
 * Implements hook_drush_command().
 */
function rmets_cpd_reviews_drush_command() {
  $items = array();

  $items['rmets-cpd-reviews-test-send-reminder'] = array(
    'description' => 'Test the sending of CPD Review email reminder.',
    'options' => array(
      'userid' => 'The user id to test the sending of the email reminder. If this is not set then it will attempt to process all users.'
    ),
    'aliases' => array('rmets-cpdrr'),
  );

  return $items;
}

/**
 * Test for sending CPD review email reminders.
 *
 * Set the userid to send test against a specific user, otherwise it will send
 * to all.
 */
function drush_rmets_cpd_reviews_test_send_reminder() {
  $user_id = drush_get_option('userid', NULL);

  if (!$user_id) {
    print "Send all user emails.\n";
    _rmets_cpd_reviews_user_email_reminder();
    return;
  }

  print "Loading user id: $user_id\n";
  // Get a user.
  $user = user_load($user_id);
  $user_wrapper = entity_metadata_wrapper('user', $user);

  print "invoke reminder rule for: " . $user->name . " @ " . date('d/m/Y H:i:s') . "\n";
  print "user last sent date: {$user_wrapper->field_last_cpd_rep_remind_date->value()} (" . date('d/m/Y H:i:s', $user_wrapper->field_last_cpd_rep_remind_date->value()) . ")\n";

  // Send the user to the rule for sending emails.
  rules_invoke_event('rmets_cpd_reviews_user_review_due_reminder', $user);

  // Reload the user to get the updated data.
  $user = user_load($user_id);
  $user_wrapper = entity_metadata_wrapper('user', $user);
  print "user last sent date: {$user_wrapper->field_last_cpd_rep_remind_date->value()} (" . date('d/m/Y H:i:s', $user_wrapper->field_last_cpd_rep_remind_date->value()) . ")\n";
}