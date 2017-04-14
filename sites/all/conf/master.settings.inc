<?php

/**
 * @file
 * Configuration for the master module.
 */

$conf['master_current_scope'] = 'base';
$conf['master_version'] = 2;
$conf['master_allow_base_scope'] = TRUE;

$conf['master_modules'] = array(
  'base' => array(
    'acquia_search',
    'admin_menu_toolbar',
    'award_profiles',
    'better_formats',
    'block_class',
    'calendar',
    'color',
    'commerce_customer_ui',
    'commerce_giftaid',
    'commerce_paypoint_gateway_hosted',
    'commerce_shipping_ui',
    'commerce_stock',
    'commerce_webform',
    'context',
    'date_popup',
    'dblog',
    'ds_extras',
    'entitycache',
    'globalredirect',
    'googleanalytics',
    'help',
    'honeypot',
    'imagecache_canvasactions',
    'imce_mkdir',
    'insert_block',
    'job_scheduler',
    'jquery_update',
    'legacies_fund',
    'locale',
    'location_node',
    'location_taxonomize_location',
    'location_taxonomy',
    'login_destination',
    'logintoboggan',
    'maillog',
    'masquerade',
    'media_youtube',
    'menu_block',
    'module_filter',
    'navigation404',
    'page_title',
    'path_breadcrumbs',
    'rdf',
    'redirect',
    'reroute_email',
    'responsible_person',
    'schedule_review',
    'syslog',
    'token_tweaks',
    'variable_admin',
    'views_bulk_operations',
    'warden',
    'webform_limited_select',
    'webform_rules',
    'workflow_admin_ui',
    'wsif',
    'xmlsitemap_menu',
    'xmlsitemap_node',

    /** Custom modules */

    'rmets_access',
    'rmets_cpd_accreditation_features',
    'rmets_cpd_features',
    'rmets_cpd_reviews_features',
    'rmets_crm',
    'rmets_events',
    'rmets_membership_purchase',
    'rmets_membership_subscriptions',
    'rmets_membership_user',
    'rmets_menu',
  )
);

if (SETTINGS_ENVIRONMENT === 'local') {
  $conf['master_modules']['base'][] = 'devel';
  $conf['master_modules']['base'][] = 'diff';
  $conf['master_modules']['base'][] = 'field_ui';
  $conf['master_modules']['base'][] = 'views_ui';
  $conf['master_modules']['base'][] = 'update';
  $conf['master_modules']['base'][] = 'styleguide';
  $conf['master_modules']['base'][] = 'coder';
  $conf['master_modules']['base'][] = 'coder_review';
  $conf['master_modules']['base'][] = 'context_ui';
  $conf['master_modules']['base'][] = 'path_breadcrumbs_ui';
  $conf['master_modules']['base'][] = 'stage_file_proxy';
}

if (SETTINGS_ENVIRONMENT === 'dev') {
  $conf['master_modules']['base'][] = 'field_ui';
  $conf['master_modules']['base'][] = 'views_ui';
  $conf['master_modules']['base'][] = 'styleguide';
  $conf['master_modules']['base'][] = 'path_breadcrumbs_ui';
  $conf['master_modules']['base'][] = 'stage_file_proxy';
}

if (SETTINGS_ENVIRONMENT === 'test') {
  $conf['master_modules']['base'][] = 'styleguide';
  $conf['master_modules']['base'][] = 'stage_file_proxy';
}

if (SETTINGS_ENVIRONMENT === 'prod') {
  $conf['master_modules']['base'][] = 'acquia_spi';
  $conf['master_modules']['base'][] = 'warden';
}
