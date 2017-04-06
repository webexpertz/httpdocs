<?php
/**
 * @file
 */

/**
 * Default argument plugin to provide a PHP code block.
 *
 * @ingroup views_argument_default_plugins
 */
class views_plugin_argument_user_cpd_objectives extends views_plugin_argument_default {

  /**
   * Only let users with PHP block visibility permissions set/modify this
   * default plugin.
   */
  function access() {
    return TRUE;
    //return user_access('administer views');
  }

  function get_argument() {
    // Check that the query string parameter for uid was set on the requesting
    // page & set the return this value.
    if (isset($_SERVER['HTTP_REFERER'])) {
      $path_parts = parse_url($_SERVER['HTTP_REFERER']);
      parse_str($path_parts['query'], $query);
      if (isset($query['uid'])) {
        return filter_xss($query['uid']);
      }
    }

    // Otherwise use the logged in uid.
    global $user;
    return $user->uid;
  }
}