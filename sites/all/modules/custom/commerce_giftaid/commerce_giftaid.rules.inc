<?php

/**
 * @file
 * Rules integration for commerce_giftaid module.
 */

/**
 * Implements hook_rules_condition_info().
 */
function commerce_giftaid_rules_condition_info() {
  return array(
    'commerce_giftaid_order_contains_eligible_items' => array(
      'label' => t('Order contain items eligible for giftaid'),
      'parameter' => array(
        'order' => array(
          'type' => 'commerce_order',
          'label' => t('The commerce order to check'),
        ),
      ),
      'help' => t('This condition returns TRUE if the order contains line items linked to products which can have giftaid applied to them.'),
      'group' => t('Commerce GiftAid'),
    ),
  );
}
