<?php
/**
 * @file
 * rmets_membership_subscriptions.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rmets_membership_subscriptions_default_rules_configuration() {
  $items = array();
  $items['rules_processed_membership_subscription_order'] = entity_import('rules_config', '{ "rules_processed_membership_subscription_order" : {
      "LABEL" : "Processed membership subscription order",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "TAGS" : [ "rmets_membership_subscriptions" ],
      "REQUIRES" : [
        "rmets_membership_subscriptions",
        "commerce_order",
        "rules",
        "commerce_checkout"
      ],
      "ON" : [ "commerce_checkout_complete" ],
      "IF" : [
        { "rmets_membership_subscriptions_order_contains_rmets_membership" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "completed" } },
        { "commerce_order_update_state" : { "commerce_order" : [ "commerce_order" ], "order_state" : "completed" } },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "8" : "8" } },
            "subject" : "Online subscription purchased [commerce-order:order-id]",
            "message" : "A user has paid for a subscription on the online website.  This should have filtered through to CRM correctly.\\r\\n\\r\\nOrder Number: [commerce-order:order-number]\\r\\n\\r\\n[commerce-order:order-details]\\r\\n\\r\\nBilling address:\\r\\n[commerce-order:billing-address-full]\\r\\n\\r\\nShipping address:\\r\\n[commerce-order:shipping-address-full]\\r\\n\\r\\nYou can view the details of the order here:\\r\\n[commerce-order:customer-url]\\r\\n\\r\\nMembership number (if available):\\r\\n[commerce-order:membership-number]"
          }
        }
      ]
    }
  }');
  $items['rules_send_a_standard_order_notification_email_no_subscriptions_'] = entity_import('rules_config', '{ "rules_send_a_standard_order_notification_email_no_subscriptions_" : {
      "LABEL" : "Send a standard order notification email (no subscriptions in order)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "TAGS" : [ "rmets_membership_subscriptions" ],
      "REQUIRES" : [ "rmets_membership_subscriptions", "rules", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "IF" : [
        { "NOT rmets_membership_subscriptions_order_contains_rmets_membership" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[commerce-order:mail]",
            "subject" : "Order [commerce-order:order-number] at [site:name]",
            "message" : "Dear [commerce-order:owner:field-forenames] [commerce-order:owner:field-surname],\\r\\n\\r\\nThanks for placing the following order with the Royal Meteorological Society.  The unique reference for the order is [commerce-order:order-number].\\r\\n\\r\\n[commerce-order:order-details]\\r\\n\\r\\nYou can view your order history with us at any time by logging into our website at:\\r\\n[site:login-url]\\r\\n\\r\\nIf this is the first time you have made an order with us, you will receive a separate e-mail with login instructions to be able to view your orders.\\r\\n\\r\\nRegards\\r\\n\\r\\nCatherine Parker\\r\\nMembership Secretary\\r\\nThe Royal Meteorological Society",
            "language" : [ "commerce-order:state" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_a_subscription_order_notification_email'] = entity_import('rules_config', '{ "rules_send_a_subscription_order_notification_email" : {
      "LABEL" : "Send a subscription order notification email",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "7",
      "TAGS" : [ "rmets_membership_subscriptions" ],
      "REQUIRES" : [ "rmets_membership_subscriptions", "rules", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "IF" : [
        { "rmets_membership_subscriptions_order_contains_rmets_membership" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[commerce-order:mail]",
            "subject" : "Royal Meteorological Society subscription payment notification [commerce-order:order-number]",
            "message" : "Dear [commerce-order:owner:field-forenames] [commerce-order:owner:field-surname],\\r\\n\\r\\nThanks for placing the following order with the Royal Meteorological Society.  The unique reference for the order is [commerce-order:order-number].\\r\\n\\r\\n[commerce-order:order-details]\\r\\n\\r\\nYou can view your order history with us at any time by logging into our website at:\\r\\n[site:login-url]\\r\\n\\r\\nIf this is the first time you have made an order with us, you will receive a separate e-mail with login instructions to be able to view your orders.\\r\\n\\r\\nRegards\\r\\n\\r\\nCatherine Parker\\r\\nMembership Secretary\\r\\nThe Royal Meteorological Society",
            "language" : [ "commerce-order:state" ]
          }
        }
      ]
    }
  }');
  return $items;
}
