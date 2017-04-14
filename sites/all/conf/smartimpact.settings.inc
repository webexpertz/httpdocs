<?php

/**
 * @file
 * Settings for the SmartImpact CRM integration.
 */

if (SETTINGS_ENVIRONMENT === 'prod') {
  $conf['rmets_crm_api_log_type'] = 2;
  $conf['rmets_crm_api_log_path'] = '../api-logs/';
  $conf['rmets_crm_api_endpoint'] = 'https://rmetsapi.uat1.smartmembership.net/smartconnector.smartconnector.svc/JSON/';
  $conf['rmets_crm_api_guid'] = '1';
}

/**

elseif (SETTINGS_ENVIRONMENT === 'local') {
  //$conf['rmets_crm_api_driver'] = 'Drupal\rmets_crm\Api\Driver\Mock';
  $conf['rmets_crm_enable_cache'] = !TRUE;
  // 1 = dpm, 2 = log to file.
  $conf['rmets_crm_api_log_type'] = 2;
  $conf['rmets_crm_api_log_path'] = '../api-logs/';
  //$conf['rmets_crm_api_endpoint'] = 'http://78.129.232.10:967/smartconnector.smartconnector.svc/JSON/';
  $conf['rmets_crm_api_endpoint'] = 'https://rmetsapi.uat1.smartmembership.net/smartconnector.smartconnector.svc/JSON/';
  //$conf['rmets_crm_api_endpoint'] = 'https://rmetsapi.smartmembership.net/smartconnector.smartconnector.svc/JSON/';
  $conf['rmets_crm_api_guid'] = '1';
}
elseif (SETTINGS_ENVIRONMENT === 'dev') {
  $conf['rmets_crm_enable_cache'] = FALSE;
  // 1 = dpm, 2 = log to file.
  $conf['rmets_crm_api_log_type'] = 2;
  $conf['rmets_crm_api_log_path'] = '../api-logs/';
  //$conf['rmets_crm_api_endpoint'] = 'http://78.129.232.10:967/smartconnector.smartconnector.svc/JSON/';
  $conf['rmets_crm_api_endpoint'] = 'https://rmetsapi.uat1.smartmembership.net/SmartConnector.SmartConnector.svc/JSON/';
  $conf['rmets_crm_api_guid'] = '1';
}
elseif (SETTINGS_ENVIRONMENT === 'test') {
  $conf['rmets_crm_enable_cache'] = FALSE;
  // 1 = dpm, 2 = log to file.
  $conf['rmets_crm_api_log_type'] = 2;
  $conf['rmets_crm_api_log_path'] = '../api-logs/';
//$conf['rmets_crm_api_endpoint'] = 'http://78.129.232.10:967/smartconnector.smartconnector.svc/JSON/';
  $conf['rmets_crm_api_endpoint'] = 'https://rmetsapi.uat1.smartmembership.net/SmartConnector.SmartConnector.svc/JSON/';
  $conf['rmets_crm_api_guid'] = '1';
}

if (!in_array(SETTINGS_ENVIRONMENT, array('prod', 'test'))) {
  $conf['rmets_crm_force_cmet_option'] = TRUE;
}

*/