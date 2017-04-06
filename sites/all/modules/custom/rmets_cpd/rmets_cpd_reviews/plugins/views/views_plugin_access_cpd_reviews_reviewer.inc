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
class views_plugin_access_cpd_reviews_reviewer extends views_plugin_access {

  function access($account) {
    return _rmets_cpd_reviews_access_review_reviewer_view();
  }

  function get_access_callback() {
    return array('_rmets_cpd_reviews_access_review_reviewer_view');
  }

  function summary_title() {
    return check_plain(t('CPD Reviews Reviewer Access'));
  }

}
