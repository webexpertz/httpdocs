<?php

/**
 * @file
 * Settings for the warden module.
 */

if (SETTINGS_ENVIRONMENT === 'prod') {
  $conf['warden_server_host_path'] = 'https://warden.deeson.net';
  $conf['warden_allow_requests'] = TRUE;
  $conf['warden_public_allow_ips'] = '127.0.0.1,2001:4800:7811:513:59b9:beb2:ff04:b7a1,52.50.239.9';
}
