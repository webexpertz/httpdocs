<?php

/**
 * @file
 * Maillog module settings.
 */

if (SETTINGS_ENVIRONMENT !== 'prod') {
  $conf['mail_system'] = array(
    'default-system' => 'MaillogMailSystem',
    'maillog' => 'MaillogMailSystem',
  );
  $conf['maillog_send'] = FALSE; // Do not send the email.
  $conf['maillog_log'] = TRUE; // Do log the email.
  $conf['maillog_devel'] = TRUE; // Do render an email on send in devel.
}