<?php

/**
 * @file
 * Drush configuration
 */

ini_set('memory_limit', '256M');

$command_specific['pm-update'] = array('lock' => 'webform_rules');
$command_specific['dl'] = array('destination' => 'sites/all/modules/contrib');
$command_specific['fu'] = array('version-increment' => TRUE);

