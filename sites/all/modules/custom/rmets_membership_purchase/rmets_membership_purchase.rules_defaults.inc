<?php
/**
 * @file
 * rmets_membership_purchase.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rmets_membership_purchase_default_rules_configuration() {
  $items = array();
  $items['rules_rmets_smart_impact'] = entity_import('rules_config', '{ "rules_rmets_smart_impact" : {
      "LABEL" : "RMets Smart Impact",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "7",
      "TAGS" : [ "rmets", "rmets_membership", "smartimpact" ],
      "REQUIRES" : [ "rmets_membership_purchase", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "DO" : [
        { "rmets_membership_purchase_pass_to_smartimpact" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  return $items;
}
