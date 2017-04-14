<?php

/**
 * @file
 * Settings for the reroute email module.
 */

if (SETTINGS_ENVIRONMENT === 'prod') {
  $conf['reroute_email_enable'] = FALSE;
  $conf['reroute_email_enable_message'] = FALSE;
}
else {
  $conf['reroute_email_address'] = "peterb@deeson.co.uk";
  $conf['reroute_email_enable'] = TRUE;
  $conf['reroute_email_enable_message'] = TRUE;
}
