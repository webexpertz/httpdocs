<?php
/**
 * @file
 * rmets_system.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rmets_system_default_rules_configuration() {
  $items = array();
  $items['rules_calculate_the_member_price_of_a_product'] = entity_import('rules_config', '{ "rules_calculate_the_member_price_of_a_product" : {
      "LABEL" : "Calculate the member price of a product",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "2",
      "TAGS" : [ "rmets_system" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : [ "commerce_product_calculate_sell_price" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "4" : "4" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "commerce_product" } },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_member_price"
          }
        }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_amount" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "commerce-line-item:commerce-product:field-member-price:amount" ],
            "component_name" : "base_price",
            "round_mode" : "1"
          }
        }
      ]
    }
  }');
  $items['rules_cloudbank_creation_unpublish_and_email'] = entity_import('rules_config', '{ "rules_cloudbank_creation_unpublish_and_email" : {
      "LABEL" : "Cloudbank Creation - unpublish and email",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "6" : "6", "5" : "5", "3" : "3" } },
            "operation" : "OR"
          }
        },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "image_gallery" : "image_gallery" } }
          }
        }
      ],
      "DO" : [
        { "node_unpublish" : { "node" : [ "node" ] } },
        { "mail" : {
            "to" : "[site:mail], administrator@rmets.org",
            "subject" : "New cloudbank content",
            "message" : "Hello,\\r\\n\\r\\nNew content has been added to the cloudbank. Please review this content here [node:url] and take the appropriate action.\\r\\n\\r\\nThanks,\\r\\n [site:name]",
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "node\\/12960" } }
      ]
    }
  }');
  $items['rules_email_administrator_on_address_change'] = entity_import('rules_config', '{ "rules_email_administrator_on_address_change" : {
      "LABEL" : "Email administrator on address change",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "rmets_membership_user" ],
      "ON" : [ "rmets_membership_user_address_updated" ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "8" : "8" } },
            "subject" : "Member has updated their details",
            "message" : "A member has edited their address on the online system.\\r\\n\\r\\n[user:field-forenames] [user:field-surname] ([user:field-membership-number])\\r\\n\\r\\nThe address edited was of type [user:changed-address-type]\\r\\n\\r\\nThe old address was:\\r\\n[user:old-address]\\r\\n\\r\\nThe new address is:\\r\\n[user:new-address]"
          }
        }
      ]
    }
  }');
  $items['rules_message_on_create_abstract'] = entity_import('rules_config', '{ "rules_message_on_create_abstract" : {
      "LABEL" : "Message on create abstract",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "event_map" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "event_abstract" : "event_abstract" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Thank you for your abstract submission to this event. The abstract will remain hidden until approved and timetabled by the event organisers." } },
        { "mail" : {
            "to" : "administrator@rmets.org, kathy123@gmail.com, ",
            "subject" : "RMetS Student Conference Abstract Submission\\r\\n",
            "message" : "Your submission is below\\r\\n[node:title] [node:body] ",
            "from" : "administrator@rmets.org",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_a_order_notification_email_to_admin_no_subs_'] = entity_import('rules_config', '{ "rules_send_a_order_notification_email_to_admin_no_subs_" : {
      "LABEL" : "Send a order notification email to order fulfilment",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "6",
      "REQUIRES" : [ "rmets_membership_subscriptions", "rules", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "IF" : [
        { "NOT rmets_membership_subscriptions_order_contains_rmets_membership" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "9" : "9" } },
            "subject" : "Website order received [commerce-order:order-number]",
            "message" : "A user has made a purchase on the online website which should now be fulfilled. Once it is posted you should change it\\u0027s status to complete.\\r\\n\\r\\nOrder Number: [commerce-order:order-number]\\r\\nCustomer Name: [commerce-order:customer-name]\\r\\n\\r\\n[commerce-order:order-details]\\r\\n\\r\\nBilling address:\\r\\n[commerce-order:billing-address-full]\\r\\n\\r\\nShipping address:\\r\\n[commerce-order:shipping-address-full]\\r\\n\\r\\nWebform fields (if any):\\r\\n[commerce-order:commerce-webform-submission]\\r\\n\\r\\nYou can view the details of the order here:\\r\\n[commerce-order:customer-url]"
          }
        }
      ]
    }
  }');
  return $items;
}
