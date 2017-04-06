<?php

/**
 * @file
 * Variable default definitions
 */

/**
 * Implements hook_variable_group_info().
 */
function rmets_cpd_records_variable_group_info() {
  $groups['rmets_cpd_records'] = array(
    'title' => t('RMetS CPD Records'),
    'description' => t('Administer descriptions for the CPD Records form.'),
    'access' => 'administer site configuration',
  );
  $groups['rmets_cpd_objectives'] = array(
    'title' => t('RMetS CPD Objectives'),
    'description' => t('Administer descriptions for the CPD Objectives form.'),
    'access' => 'administer site configuration',
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function rmets_cpd_records_variable_info($options) {
  $variable['rmets_cpd_record_page_list_intro'] = array(
    'title' => t('CPD Records Intro Text'),
    'description' => t('Intro text for the listing of users CPD Records'),
    'type' => 'text',
    'default' => '',
    'group' => 'rmets_cpd_records',
  );

  $variable['rmets_cpd_objective_page_list_intro'] = array(
    'title' => t('CPD Objective Intro Text'),
    'description' => t('Intro text for the listing of users CPD Objective'),
    'type' => 'text',
    'default' => '',
    'group' => 'rmets_cpd_objectives',
  );

  return $variable;
}
