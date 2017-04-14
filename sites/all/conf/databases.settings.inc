<?php

/**
 * @file
 * Database settings.
 */

if (SETTINGS_INSTANCE === 'test.rmets.org') {
  $databases = array (
    'default' =>
      array (
        'default' =>
          array (
            'database' => 'rmets_drupal_7',
            'username' => 'rmets_drupal',
            'password' => 'flameI23@6665',
            'host' => 'localhost',
            'port' => '',
            'driver' => 'mysql',
            'prefix' => '',
          ),
      ),
  );
}

/**
elseif (SETTINGS_INSTANCE === 'rmets-stage.deeson.net') {
  $databases = array (
    'default' =>
      array (
        'default' =>
          array (
            'database' => 'rmetssta_drupal_7',
            'username' => 'rmetssta_drupal',
            'password' => 'FS4aDWwEXW9qwPnD',
            'host' => 'localhost',
            'port' => '',
            'driver' => 'mysql',
            'prefix' => '',
          ),
      ),
  );
}
elseif (SETTINGS_INSTANCE === 'rmets-dev.deeson.net') {
  $databases = array(
    'default' =>
      array(
        'default' =>
          array(
            'database' => 'rmetsdev_drupal',
            'username' => 'rmetsdev_drupal',
            'password' => 'farlsERP58UT',
            'host' => 'localhost',
            'port' => '',
            'driver' => 'mysql',
            'prefix' => '',
          ),
      ),
  );
}

*/