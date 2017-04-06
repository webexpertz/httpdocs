<?php

/**
 * @file
 * Drush command to check on cron and make sure it has been run.
 */

/**
 * Implements of hook_drush_command().
 */
function croncheck_drush_command() {
  $items = array();

  $items['checkcron'] = array(
    'description' => "Check on time since cron run and send alert if needed.",
    'aliases' => array('checkc'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Implements of hook_drush_help().
 */
function croncheck_drush_help($section) {
  switch ($section) {
    case 'drush:checkcron':
      return dt("This command will check to see the last time cron ran and send an alert if needed.");

    case 'meta:checkcron:title':
      return dt("checkcron commands");

    case 'meta:checkcron:summary':
      return dt("Keeping cron running helps to keep the site running smoothly.");
  }
}

/**
 * Main drush command callback. This is where the action takes place.
 */
function drush_croncheck_checkcron() {
  // Get the last time cron was run via the cron_last variable.
  $last_cron = variable_get('cron_last', '');
  // Make the default time to check one hour (3600s). Use the
  // drushcroncheck_time_to_check variable to change this.
  $time_to_check = variable_get('drushcroncheck_time_to_check', 3600);
  // Get the difference in seconds between now and the last time cron ran.
  $difference = time() - $last_cron;

  // Has it been longer than our time to check since cron ran?
  if ($difference >= $time_to_check) {
    // Format the date so it is more readable than timestamp seconds.
    $cleandate = date('l F d Y - G:i:s A', $last_cron);
    // Format a message to be used via the command line OR the email.
    $message = t('We have a problem, !cleandate is the last time cron ran! Time since last cron is: !difference', array('!cleandate' => $cleandate, '!difference' => drush_timesince($difference)));
    // Uncomment this line if you want to have the display in the command line.
    drush_print($message);

    // Configure and send the email.
    $email = variable_get('drushcroncheck_email', user_load(1)->mail);
    $site_name = variable_get('site_name', 'sitename.com');
    drush_mail_send_email($email, dt('!site_name: Cron has failed or hung', array('!site_name' => $site_name)), $message);
  }
  else {
    // Add whatever is needed for successful cron runs, this is unneeded now.
    drush_print('All good');
  }
}


/**
 * Send an e-mail to a specified e-mail address.
 * @see http://drupal.org/files/mail.drush_.inc__0.txt
 */
function drush_mail_send_email($to_email, $subject, $body) {
  // Define $from and headers.
  if (!$from = drush_get_option('from')) {
    $from = variable_get('site_mail', ini_get('sendmail_from'));
  }
  $headers = array();
  $headers['From'] = $headers['Sender'] = $headers['Return-Path'] = $headers['Errors-To'] = $from;
  $headers['X-Priority'] = 1;
  $headers['X-MSMail-Priority'] = 'High';
  $headers['Importance'] = 'High';

  if (!valid_email_address($to_email)) {
    if (function_exists('user_load_by_name')) {
      $account = user_load_by_name($to_email);
    }
    else {
      $account = user_load(array('name' => $to_email));
    }
    if (empty($account)) {
      return drush_set_error('DRUSH_BAD_EMAIL_OR_USERNAME', dt('Bad e-mail address or username.'));
    }
    else {
      $to_email = $account->mail;
    }
  }

  // D7 implementation of drupal_mail
  if (function_exists('drupal_mail_system')) {
    // Prepare the message.
    $message = drupal_mail('drush', 'key', $to_email, NULL, array(), $from, FALSE);

    $message['subject'] = $subject;
    $message['body'] = array();
    $message['body'][] = $body;
    $message['headers'] = $headers;

    // Retrieve the responsible implementation for this message.
    $system = drupal_mail_system('drush', 'key');

    // Format the message body.
    $message = $system->format($message);

    // Send e-mail.
    $message['result'] = $system->mail($message);
    $result = $message['result'];
  }
  else {

    // D6 implementation of drupal_mail_send
    $message = array(
      'to' => $to_email,
      'subject' => $subject,
      'body' => $body,
      'headers' => $headers,
    );
    $result = drupal_mail_send($message);
  }

  // Return result.
  if ($result) {
    drush_log(dt('E-mail message sent to <!to>', array('!to' => $to_email)), 'ok');
  }
  else {
    drush_set_error('DRUSH_MAIL_ERROR', dt('An error occurred while sending the e-mail message.'));
  }
}

/**
 * Helper function to transfor seconds into a usable time since string.
 */
function drush_timesince($seconds) {

  if ($seconds > 3600) {
    $days = $seconds / 86400;
    $day_explode = explode(".", $days);
    $day = $day_explode[0];
  }
  else {
    $day = 0;
  }

  if ($seconds > 3600) {
    $hours = '.' . @$day_explode[1] . '';
    $hour = $hours * 24;
    $hourr = explode(".", $hour);
    $hourrs = $hourr[0];
  }
  else {
    $hours = $seconds / 3600;
    $hourr = explode(".", $hours);
    $hourrs = $hourr[0];
  }

  $minute = '.' . @$hourr[1] . '';
  $minutes = $minute * 60;
  $minute = explode(".", $minutes);
  $minuter = $minute[0];

  $seconds = '.' . @$minute[1] . '';
  $second = $seconds * 60;
  $second = round($second);

  return (@$day . ' Days ' . @$hourrs . ' Hours ' . @$minuter . ' minutes, ' . @$second . ' seconds');
}
