<?php

/**
 * @file
 * Aliases for different environments.
 */

$aliases['vdd'] = array(
  'parent' => '@parent',
  'env' => 'vdd',
  'uri' => 'rmets.dev',
  'root' => '/var/www/vhosts/rmets.dev/docroot',
);

if (!file_exists('/var/www/vhosts/rmets.dev/docroot')) {
  $aliases['vdd']['remote-host'] = 'dev.local';
  $aliases['vdd']['remote-user'] = 'ubuntu';
}

$aliases['prodserver'] = array();

if (!file_exists('/home/rmets/public_html')) {
  $aliases['prodserver']['remote-host'] = 'rmets.org';
}

$aliases['dev'] = array(
  'parent' => '@parent,@prodserver',
  'root' => '/home/rmetsdev/public_html',
  'uri' => 'rmets-dev.deeson.net',
);

$aliases['test'] = array(
  'parent' => '@parent,@prodserver',
  'root' => '/home/rmetssta/public_html',
  'uri' => 'rmets-stage.deeson.net',
);

$aliases['prod'] = array(
  'parent' => '@parent,@prodserver',
  'root' => '/home/rmets/public_html',
  'uri' => 'www.rmets.org',
);
