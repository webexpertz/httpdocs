<?php

/**
 * @file
 * Core settings for Drupal.
 */

// No web updates.
$update_free_access = FALSE;

// Be secure.
$drupal_hash_salt = '_HJ7BgLP4LeYawZ1b5a0XX2LxyRxKsT0F2mYdXaycbo';

// Fast 404.
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

$conf['site_name'] = 'Royal Meteorological Society';
if (SETTINGS_ENVIRONMENT !== 'prod') {
  $conf['site_name'] = '[' . SETTINGS_ENVIRONMENT . '] ' . $conf['site_name'];
}

// Lets use HTTPS always on production.
if (in_array(SETTINGS_ENVIRONMENT, array('prod', 'local'))) {
  $conf['https'] = TRUE;
  $base_url = 'https://' . SETTINGS_INSTANCE;
}
else {
  $conf['https'] = FALSE;
  $base_url = 'http://' . SETTINGS_INSTANCE;
}

// Image token fix.
$conf['image_allow_insecure_derivatives'] = TRUE;

// Public file system.
$conf['file_public_path'] = 'sites/default/files';

// Private file system
$conf['file_private_path'] = '../private-files';

// Cron check will fail if cron has not run for 2 hrs.
$conf['drushcroncheck_time_to_check'] = 7200;

// Never run poormanscron.
$conf['cron_safe_threshold'] = '0';

// Token tweaks.
$conf['token_tree_recursion_limit'] = '4';

// Site policy settings.
$conf['site_policy_user_1_pw_scramble'] = 2419200;
$conf['site_policy_user_1_active_time'] = 604800;

// Regional settings.
$conf['site_default_country'] = 'GB';
$conf['date_first_day'] = '1';
$conf['date_default_timezone'] = 'Europe/London';
$conf['configurable_timezones'] = '1';
