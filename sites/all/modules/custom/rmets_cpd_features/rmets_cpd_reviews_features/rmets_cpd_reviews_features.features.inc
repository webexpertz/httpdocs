<?php
/**
 * @file
 * rmets_cpd_reviews_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rmets_cpd_reviews_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rmets_cpd_reviews_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rmets_cpd_reviews_features_node_info() {
  $items = array(
    'cpd_report_review' => array(
      'name' => t('CPD Report'),
      'base' => 'node_content',
      'description' => t('The CPD report review is a summary of all or a subset of CPD records compiled for the purpose of applying for accreditation, demonstrating ongoing compliance or submitting evidence of CPD activities undertaken for either external or internal purposes.'),
      'has_title' => '1',
      'title_label' => t('Short report description'),
      'help' => t('CPD Reports created for personal use require completion of only the information on the Identification and CPD Records tabs and optionally the Work Experience tab. CPD Reports requested by the Society and to be submitted by those wishing to retain the accreditation RMet or CMet require completion of the information requested on every tab.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_workflow_default_workflows().
 */
function rmets_cpd_reviews_features_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: CDP Reviews
  $workflows['CDP Reviews'] = array(
    'name' => 'CDP Reviews',
    'tab_roles' => '',
    'options' => array(),
    'states' => array(
      1 => array(
        'weight' => -50,
        '' . "\0" . '*' . "\0" . 'sysid' => 1,
        '' . "\0" . '*' . "\0" . 'state' => '(creation)',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => '(creation)',
      ),
      2 => array(
        'weight' => -19,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Draft',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Draft',
      ),
      3 => array(
        'weight' => -18,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Awaiting payment',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Awaiting payment',
      ),
      4 => array(
        'weight' => -17,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Pending',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Pending',
      ),
      5 => array(
        'weight' => -16,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Assigning reviewers',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Assigning reviewers',
      ),
      6 => array(
        'weight' => -15,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Awaiting review',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Awaiting review',
      ),
      7 => array(
        'weight' => -14,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Review processing',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Review processing',
      ),
      8 => array(
        'weight' => -13,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Awaiting board review',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Awaiting board review',
      ),
      9 => array(
        'weight' => -12,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Awaiting board decision',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Awaiting board decision',
      ),
      10 => array(
        'weight' => -11,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Unacceptable',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Unacceptable',
      ),
      11 => array(
        'weight' => -10,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Acceptable',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Acceptable',
      ),
    ),
    'transitions' => array(
      0 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Pending',
        'roles' => 'workflow_features_author_name,member,membership secretary,administrator',
      ),
      1 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'workflow_features_author_name,membership secretary,administrator',
      ),
      2 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Draft',
        'roles' => 'workflow_features_author_name,member,membership secretary,administrator',
      ),
      3 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      4 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      5 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      6 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      7 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      8 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      9 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'workflow_features_author_name,member,membership secretary,administrator',
      ),
      10 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Pending',
        'roles' => 'workflow_features_author_name,member,membership secretary,administrator',
      ),
      11 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      12 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      13 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      14 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      15 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      16 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      17 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      18 => array(
        'state_name' => 'Draft',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'workflow_features_author_name,member,membership secretary,administrator',
      ),
      19 => array(
        'state_name' => 'Awaiting payment',
        'target_state_name' => 'Draft',
        'roles' => 'workflow_features_author_name,member,membership secretary,administrator',
      ),
      20 => array(
        'state_name' => 'Awaiting payment',
        'target_state_name' => 'Pending',
        'roles' => 'workflow_features_author_name,member,membership secretary,administrator',
      ),
      21 => array(
        'state_name' => 'Awaiting payment',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      22 => array(
        'state_name' => 'Awaiting payment',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      23 => array(
        'state_name' => 'Awaiting payment',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      24 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      25 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      26 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Draft',
        'roles' => 'workflow_features_author_name,membership secretary,administrator',
      ),
      27 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      28 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      29 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      30 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      31 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      32 => array(
        'state_name' => 'Pending',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'membership secretary,administrator',
      ),
      33 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      34 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Draft',
        'roles' => 'membership secretary,administrator',
      ),
      35 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Pending',
        'roles' => 'membership secretary,administrator',
      ),
      36 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      37 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      38 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      39 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      40 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      41 => array(
        'state_name' => 'Assigning reviewers',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'membership secretary,administrator',
      ),
      42 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      43 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Draft',
        'roles' => 'membership secretary,administrator',
      ),
      44 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Pending',
        'roles' => 'membership secretary,administrator',
      ),
      45 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      46 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      47 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      48 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      49 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      50 => array(
        'state_name' => 'Awaiting review',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'membership secretary,administrator',
      ),
      51 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      52 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Draft',
        'roles' => 'membership secretary,administrator',
      ),
      53 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Pending',
        'roles' => 'membership secretary,administrator',
      ),
      54 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      55 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      56 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      57 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      58 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      59 => array(
        'state_name' => 'Review processing',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'membership secretary,administrator',
      ),
      60 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      61 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Draft',
        'roles' => 'membership secretary,administrator',
      ),
      62 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Pending',
        'roles' => 'membership secretary,administrator',
      ),
      63 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      64 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      65 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      66 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      67 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      68 => array(
        'state_name' => 'Awaiting board review',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'membership secretary,administrator',
      ),
      69 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      70 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      71 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'membership secretary,administrator',
      ),
      72 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Draft',
        'roles' => 'membership secretary,administrator',
      ),
      73 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Pending',
        'roles' => 'membership secretary,administrator',
      ),
      74 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      75 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      76 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      77 => array(
        'state_name' => 'Awaiting board decision',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      78 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Pending',
        'roles' => 'membership secretary,administrator',
      ),
      79 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Draft',
        'roles' => 'membership secretary,administrator',
      ),
      80 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      81 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      82 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      83 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      84 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      85 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Acceptable',
        'roles' => 'membership secretary,administrator',
      ),
      86 => array(
        'state_name' => 'Unacceptable',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'membership secretary,administrator',
      ),
      87 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Draft',
        'roles' => 'membership secretary,administrator',
      ),
      88 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Pending',
        'roles' => 'membership secretary,administrator',
      ),
      89 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Assigning reviewers',
        'roles' => 'membership secretary,administrator',
      ),
      90 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Awaiting review',
        'roles' => 'membership secretary,administrator',
      ),
      91 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Review processing',
        'roles' => 'membership secretary,administrator',
      ),
      92 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Awaiting board review',
        'roles' => 'membership secretary,administrator',
      ),
      93 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Awaiting board decision',
        'roles' => 'membership secretary,administrator',
      ),
      94 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Unacceptable',
        'roles' => 'membership secretary,administrator',
      ),
      95 => array(
        'state_name' => 'Acceptable',
        'target_state_name' => 'Awaiting payment',
        'roles' => 'membership secretary,administrator',
      ),
    ),
  );

  return $workflows;
}
