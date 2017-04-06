<?php
/**
 * @file
 * rmets_membership_purchase.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function rmets_membership_purchase_commerce_product_default_types() {
  $items = array(
    'rmets_membership_smartimpact' => array(
      'type' => 'rmets_membership_smartimpact',
      'name' => 'RMetS Membership SmartImpact',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}
