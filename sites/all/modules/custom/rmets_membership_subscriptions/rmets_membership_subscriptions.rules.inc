<?php

/**
 * Implements hook_rules_condition_info().
 */
function rmets_membership_subscriptions_rules_condition_info() {
  return array(
    'rmets_membership_subscriptions_order_contains_rmets_membership' => array(
      'label' => t('Order contains CRM subscription product'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Shopping cart order'),
        ),
      ),
      'help' => t('This condition returns TRUE if the order has an CRM subscription product attached to it.'),
      'group' => t('RMetS Subscription Membership'),
    ),
  );
}