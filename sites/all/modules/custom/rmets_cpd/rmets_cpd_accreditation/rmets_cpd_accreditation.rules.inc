<?php

/**
 * @file
 * RMetS CPD Accreditation Rules file.
 */

/**
 * Implements hook_rules_event_info().
 */
function rmets_cpd_accreditation_rules_event_info() {
  return array(
    'rmets_cpd_accreditation_user_review_due_reminder' => array(
      'label' => t('When a RMetS CPD user is due their accreditation reminder'),
      'group' => t('RMetS CPD Accreditation'),
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
 *
 * @see rmets_cpd_commerce_order_contains_accreditation_product().
 */
function rmets_cpd_accreditation_rules_condition_info() {
  return array(
    'rmets_cpd_commerce_order_contains_accreditation_product' => array(
      'label' => t('Order contains an accreditation product'),
      'group' => t('RMetS CPD Accreditation'),
      'arguments' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Accreditation Order'),
        ),
      )
    ),
  );
}

/**
 * Implement hook_rules_action_info()
 */
function rmets_cpd_accreditation_rules_action_info() {
  $actions = array(
    'rmets_cpd_accreditation_update_from_order' => array(
      'label' => t('Update the accreditation application to reference the order and change status'),
      'group' => t('RMetS CPD Accreditation'),
      'parameter' => array(
        'account' => array(
          'type' => 'commerce_order',
          'label' => t('Accreditation Order'),
        ),
      ),
    ),

    'rmets_cpd_accreditation_go_back_to_accreditation_in_order' => array(
      'label' => t('Go to an accreditation application referenced by an order which contains an application fee'),
      'group' => t('RMetS CPD Accreditation'),
      'parameter' => array(
        'account' => array(
          'type' => 'commerce_order',
          'label' => t('Accreditation Order'),
        ),
      ),
    ),

  );

  return $actions;
}

/**
 * Get am accreditation application line item from an order.
 *
 * @return LineItem|NULL
 *   Returns the line item or nothing if there isn;t one
 *   Note that on the odd situation there is more then
 *   one, only the first is returned.
 */
function rmets_cpd_accreditation_get_accreditation_application_from_order($order) {
  // Load the order.
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $line_items = $order_wrapper->commerce_line_items;

  // Get the accreditation product list.
  $accreditation_products = _rmets_cpd_accreditation_get_products();

  // Check through the order line items to see if they contain an accreditation product.
  foreach ($line_items as $line_item) {
    $item = commerce_line_item_load($line_item->line_item_id->value());
    if (array_key_exists($item->line_item_label, $accreditation_products)) {
      // Found an accreditation product in the order.
      return $item;
    }
  }
}

/**
 * Checks an order to see if it contains an accreditation product.
 *
 * @param stdClass $order Order
 *  The order object that needs to be checked.
 *
 * @return bool
 *   TRUE if accreditation product has been found | FALSE.
 */
function rmets_cpd_commerce_order_contains_accreditation_product($order) {
  $item = rmets_cpd_accreditation_get_accreditation_application_from_order($order);
  return !empty($item);
}

/**
 * Updates the accreditation node status and adds a link back to the order.
 *
 * @param $order
 */
function rmets_cpd_accreditation_update_from_order($order) {
  // Load the order.
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $line_items = $order_wrapper->commerce_line_items;

  // Get the accreditation product list.
  $accreditation_products = _rmets_cpd_accreditation_get_products();

  // Check through the order line items to see if they contain an accreditation product.
  foreach ($line_items as $line_item) {
    $item = commerce_line_item_load($line_item->line_item_id->value());
    $item_wrapper = entity_metadata_wrapper('commerce_line_item', $item);
    if (array_key_exists($item_wrapper->line_item_label->value(), $accreditation_products)) {
      $nid = $item_wrapper->field_rmets_accreditation_nid->value();

      // Update the status of the application from 'awaiting payment' to 'pending'.
      $node = node_load($nid);
      $state_awaiting_payment = _rmets_cpd_get_workflow_status_id_by_name('Awaiting payment');
      $state_pending = _rmets_cpd_get_workflow_status_id_by_name('Pending');

      $transition = new WorkflowTransition();
      $transition->setValues('node', $node, 'field_status', $state_awaiting_payment, $state_pending, $node->uid, REQUEST_TIME, t('Payment complete.'));
      workflow_execute_transition('node', $node, 'field_status', $transition, TRUE);
    }
  }
}

/**
 * Go to an accreditation page from an order.
 */
function rmets_cpd_accreditation_go_back_to_accreditation_in_order($order) {
  $item = rmets_cpd_accreditation_get_accreditation_application_from_order($order);
  if (!empty($item)) {
    $item_wrapper = entity_metadata_wrapper('commerce_line_item', $item);
    $nid = $item_wrapper->field_rmets_accreditation_nid->value();

    if (!empty($nid)) {
      drupal_set_message('Your application is now being processed');
      drupal_goto('node/' . $nid);
    }
  }
}
