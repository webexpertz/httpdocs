<?php

/**
 * @file
 * Variable default definitions
 */

/**
 * Implements hook_variable_group_info().
 */
function rmets_cpd_reviews_variable_group_info() {
  $groups['rmets_cpd_reports'] = array(
    'title' => t('RMetS CPD Report'),
    'description' => t('Administer descriptions for the CPD Report form.'),
    'access' => 'administer site configuration',
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function rmets_cpd_reviews_variable_info($options) {
  $variable['rmets_cpd_report_page_list_intro'] = array(
    'title' => t('CPD Report Intro Text'),
    'description' => t('Intro text for the listing of users CPD Reports'),
    'type' => 'text',
    'default' => '',
    'group' => 'rmets_cpd_reports',
  );

  // Generate the content type group description variables.
  $field_groups = field_group_info_groups('node', 'cpd_report_review');
  $tab_groups = array();
  foreach ($field_groups['form'] as $group) {
    // Don't include the parent group.
    if ($group->parent_name == '') {
      continue;
    }
    $tab_groups[$group->weight] = $group;
  }
  ksort($tab_groups);

  foreach ($tab_groups as $group) {
    $key = md5('rmets_cpd_report_review_' . $group->group_name);
    $variable['rmets_' . $key] = array(
      'title' => t($group->label . ' tab description.'),
      'description' => t('Tab description for: ' . $group->label),
      'type' => 'text',
      'default' => '',
      'group' => 'rmets_cpd_reports',
    );
  }

  return $variable;
}
