<?php
/**
 * @file
 */

function rmets_cpd_settings($form, &$form_state) {
  $form['rmets_cpd_about_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('CPD About Node Id'),
    //'#description' => t('Leave blank to disable.'),
    '#default_value' => variable_get('rmets_cpd_about_nid', ''),
    '#size' => 10,
  );

  return system_settings_form($form);
}