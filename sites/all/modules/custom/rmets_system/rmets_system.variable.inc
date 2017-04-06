<?php

/**
 * @file
 * Variable default definitions
 */

/**
 * Implements hook_variable_group_info().
 */
function rmets_system_variable_group_info() {
  $groups['rmets'] = array(
    'title' => t('Royal Meteorological Society'),
    'description' => t('Details about RMetS and their subscriptions.'),
    'access' => 'administer site configuration',
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function rmets_system_variable_info($options) {
  $variable['livecustomer_advert_url'] = array(
    'title' => t('Live customer advert URL'),
    'description' => t('The URL to the livecustomer addcode'),
    'type' => 'url',
    'default' => 'http://update.livecustomer.net/s?i=5377',
    'group' => 'rmets',
  );

  $variable['livecustomer_advert_disclaimer'] = array(
    'title' => t('Live customer advert disclaimer'),
    'description' => t('Disclaimer to show above any adverts'),
    'type' => 'text',
    'default' => 'The society is not responsible for the content of external websites',
    'group' => 'rmets',
  );

  $variable['livecustomer_advert_timeout'] = array(
    'title' => t('Live customer advert timeout'),
    'description' => t('The number of seconds to wait for the advert server to respond.'),
    'type' => 'number',
    'default' => 3,
    'group' => 'rmets',
  );

  return $variable;
}
