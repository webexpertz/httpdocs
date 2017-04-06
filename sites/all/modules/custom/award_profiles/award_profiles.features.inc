<?php
/**
 * @file
 * award_profiles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function award_profiles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function award_profiles_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function award_profiles_node_info() {
  $items = array(
    'award' => array(
      'name' => t('Award'),
      'base' => 'node_content',
      'description' => t('An award is granted to an individual on a particular date.  That individual must exist inside Enterprise and have a valid membership number.'),
      'has_title' => '1',
      'title_label' => t('Award'),
      'help' => t('Generally you would not manually create an award instance like this - they are created automatically from a synchronisation process with Enterprise.'),
    ),
    'award_profile' => array(
      'name' => t('Award profile'),
      'base' => 'node_content',
      'description' => t('The profile of an individual.  This is usually used for members with an award or accreditation of some kind such as CMet, CSci or an award such as The Vaisala Award'),
      'has_title' => '1',
      'title_label' => t('Fullname'),
      'help' => t('Beware that some award winners do not want their details to appear online. By default profiles are created from details in Enterprise and the profile is set to unpublished.  To make their details publicly visible you must publish the node.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
