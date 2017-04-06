<?php
/**
 * @file
 * RMetS CPD Review Rules file.
 */

/**
 * Implements hook_rules_event_info().
 */
function rmets_cpd_reviews_rules_event_info() {
  return array(
    'rmets_cpd_reviews_user_review_due_reminder' => array(
      'label' => t('When a RMetS CPD user is due their review reminder'),
      'group' => t('RMetS CPD Reviews'),
      'variables' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('The user due for reminder.'),
        ),
      )
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function rmets_cpd_reviews_rules_condition_info() {
  return array(
    'rules_condition_workflow_state' => array(
      'label' => t('RMetS - Workflow state'),
      'parameter' => array(
        'workflow_state_id' => array(
          'label' => t('Workflow field'),
          'type' => '*',
        ),
        'workflow_label' => array(
          'label' => t('Status'),
          'type' => 'text',
        ),
      ),
      'group' => t('Workflow'),
    ),
  );
}

/**
 * Callback for Rules condition.
 *
 * @param $workflow_field
 * @param $workflow_status
 * @param $settings
 *
 * @see rmets_cpd_reviews_rules_condition_info().
 *
 * @return bool
 */
function rules_condition_workflow_state($workflow_state_id, $expected_label) {
  $actual_label = workflow_get_sid_label($workflow_state_id);
  return ($actual_label === $expected_label);
}
