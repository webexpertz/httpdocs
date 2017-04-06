<?php

/**
 * @file
 * Definition of views_plugin_access_cpd.
 */

/**
 * Access plugin that provides CPD access control.
 *
 * @ingroup views_access_plugins
 */
class views_plugin_access_cpd extends views_plugin_access {

  function access($account) {
    return rmets_cpd_access($account);
  }

  function get_access_callback() {
    return array('rmets_cpd_access', array(1));
  }

  function summary_title() {
    return check_plain(t('CPD Access'));
  }
}
