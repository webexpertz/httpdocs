<?php
/**
 * @file
 * rmets_cpd_features.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function rmets_cpd_features_filter_default_formats() {
  $formats = array();

  // Exported format: Member HTML.
  $formats['member_html'] = array(
    'format' => 'member_html',
    'name' => 'Member HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
