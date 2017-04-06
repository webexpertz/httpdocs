<?php

/**
 * @file
 * Token replacements for rmets_membership_subscriptions module.
 */

use Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper;

/**
 * Implements hook_token_info().
 */
function rmets_membership_subscriptions_token_info() {
  return array(
    'tokens' => array(
      'commerce-order' => array(
        'order-details' => array(
          'name' => t('Order details'),
          'description' => t('A detailed listing of the contents of the order. Useful in email confirmations.'),
        ),
        'billing-address-full' => array(
          'name' => t('The full billing address'),
          'description' => t('The full billing address (note: provided by the rmets_subscription module)'),
        ),
        'shipping-address-full' => array(
          'name' => t('The full shipping address'),
          'description' => t('The full shipping address (note: provided by the rmets_subscription module)'),
        ),
        'membership-number' => array(
          'name' => t('Membership number'),
          'description' => t('Membership number of the order owner'),
        ),
        'user' => array(
          'name' => t('user object of the buyer'),
          'description' => t('The full user node for the commerce order owner'),
          'type' => 'user',
        ),
        'customer-name' => array(
          'name' => t('Name of the person purchasing the order'),
          'description' => t('The customer name of who the order is for'),
        ),
      ),
      /*'user' => array(
        'subscription-details' => array(
          'name' => t('RMetS Subscription details'),
          'description' => t('A listing of the users current subscriptions.'),
        ),
      ),*/
    ),
  );
}

/**
 * Implements hook_token().
 */
function rmets_membership_subscriptions_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'commerce-order' && !empty($data['commerce-order'])) {
    $order = $data['commerce-order'];
    foreach ($tokens as $name => $original) {
      switch ($name) {

        case 'user':
          $user = user_load($order->uid);
          $replacements[$original] = $user;
          break;

        case 'customer-name':
          try {
            $customer_name = NULL;
            foreach (entity_metadata_wrapper('commerce_order', $order)->commerce_line_items->value() as $line_item) {
              if ($line_item->type != 'rmets_events_smartimpact') {
                continue;
              }
              if (!isset($line_item->data['forenames'])) {
                continue;
              }
              $customer_name = $line_item->data['title'] . ' ' . $line_item->data['forenames'] . ' ' . $line_item->data['surname'];
              break;
            }

            if (is_null($customer_name)) {
              $user = user_load($order->uid);
              /** @var UserWrapper $user_wrapper */
              $user_wrapper = new UserWrapper($user);
              $user_wrapper->updateFromCrm();

              $customer_name = $user_wrapper->getTitle() . ' ' . $user_wrapper->getForename() . ' ' . $user_wrapper->getSurname();
            }

            $replacements[$original] = $customer_name;
          }
          catch (Exception $e) {
            watchdog_exception('rmets_membership_subscriptions', $e);
            $replacements[$original] = '';
          }
          break;

        case 'membership-number':
          $user = user_load($order->uid);
          try {
            $user_wrapper = new UserWrapper($user);
            $user_wrapper->updateFromCrm();
            $replacements[$original] = $user_wrapper->getMembershipNumber();
          }
          catch (Exception $e) {
            watchdog_exception('rmets_membership_subscriptions', $e);
            $replacements[$original] = '';
          }
          break;

        case 'order-details':
          $details = '<p>';
          $giftaidable = FALSE;
          $giftaid = FALSE;
          /*$receiptable = FALSE;
          $receipt = FALSE;*/
          foreach (entity_metadata_wrapper('commerce_order', $order)->commerce_line_items->value() as $line_item) {
            $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
            $product = $line_item_wrapper->commerce_product->value();
            $product_wrapper = entity_metadata_wrapper('commerce_product', $product);
            $giftaidable = $product_wrapper->commerce_product_giftaid->value() == 1 ? TRUE : $giftaidable;
            $price = $line_item_wrapper->commerce_total->value();
            $giftaid = $line_item_wrapper->commerce_product_giftaid->value() == 1 ? TRUE : $giftaid;
            $product_title = $product->title . ' (x' . $line_item->quantity . ')';
            if (rmets_membership_subscriptions_is_subscription_product($product) && isset($line_item->data['product'])) {
              /*$receiptable = TRUE;
              $receipt = $line_item->data['receipt'] ? TRUE : FALSE;*/
              $product_title = $line_item->data['title_of_item'];
            }
            $details .= $product_title . commerce_currency_format($price['amount'], $price['currency_code'], $product) . "<br />\r\n";
          }
          if ($giftaidable) {
            $details .= t('Giftaid: @giftaid', array('@giftaid' => ($giftaid ? t('Yes') : t('No')))) . "<br />\r\n";
          }
          /*if ($receiptable) {
            $details .= t('Receipt required: @require_receipt', array('@require_receipt' => ($receipt ? t('Yes') : t('No'))));
          }*/
          $details .= "</p>\r\n";
          $replacements[$original] = $details;
          break;

        case 'billing-address-full':
          $details = '';
          if (isset($order->commerce_customer_billing)) {
            $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
            $billing_profile = $order_wrapper->commerce_customer_billing->value();
            $billing_profile_wrapper = entity_metadata_wrapper('commerce_customer_profile', $billing_profile);
            $address = $billing_profile_wrapper->commerce_customer_address->value();
            if ($address) {
              $details = '<p>';
              $details .= $address['last_name'] ? "{$address['first_name']} {$address['last_name']}<br />\r\n" : '';
              $details .= $address['name_line'] ? "{$address['name_line']}<br />\r\n" : '';
              $details .= $address['organisation_name'] ? $address['organisation_name'] . "<br />\r\n" : '';
              $details .= $address['sub_premise'] ? $address['sub_premise'] . "<br />\r\n" : '';
              $details .= $address['thoroughfare'] ? $address['thoroughfare'] . "<br />\r\n" : '';
              $details .= $address['premise'] ? $address['premise'] . "<br />\r\n" : '';
              $details .= $address['locality'] ? $address['locality'] . "<br />\r\n" : '';
              $details .= $address['administrative_area'] ? $address['administrative_area'] . "<br />\r\n" : '';
              $details .= $address['postal_code'] ? $address['postal_code'] . "<br />\r\n" : '';
              $details .= "</p>\r\n";
            }
          }
          $replacements[$original] = $details;
          break;

        case 'shipping-address-full':
          $details = '';
          if (isset($order->commerce_customer_shipping)) {
            $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
            $shipping_profile = $order_wrapper->commerce_customer_shipping->value();
            $shipping_profile_wrapper = entity_metadata_wrapper('commerce_customer_profile', $shipping_profile);
            $address = $shipping_profile_wrapper->commerce_customer_address->value();
            if ($address) {
              $details = '<p>';
              $details .= $address['last_name'] ? "{$address['first_name']} {$address['last_name']}<br />\r\n" : '';
              $details .= $address['name_line'] ? "{$address['name_line']}<br />\r\n" : '';
              $details .= $address['organisation_name'] ? $address['organisation_name'] . "<br />\r\n" : '';
              $details .= $address['sub_premise'] ? $address['sub_premise'] . "<br />\r\n" : '';
              $details .= $address['thoroughfare'] ? $address['thoroughfare'] . "<br />\r\n" : '';
              $details .= $address['premise'] ? $address['premise'] . "<br />\r\n" : '';
              $details .= $address['locality'] ? $address['locality'] . "<br />\r\n" : '';
              $details .= $address['administrative_area'] ? $address['administrative_area'] . "<br />\r\n" : '';
              $details .= $address['postal_code'] ? $address['postal_code'] . "<br />\r\n" : '';
              $details .= "</p>\r\n";
            }
          }
          $replacements[$original] = $details;
          break;

      }
    }
  }

  /*if ($type == 'user' && !empty($data['user'])) {
    $account = $data['user'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
      case 'subscription-details':
        try {
          $user_wrapper = new UserWrapper($account);
          $details = '<p>';
          $membership_number = $user_wrapper->getMembershipNumber();
          $details .= "Membership number: {$membership_number}\r\n";
          $subscriptionID = $user_wrapper->getActiveSubscriptionID();
          $current_year = date('Y');

          // Details of subscriptions.
          foreach ($subscriptions as $subscription) {

            if ($subscription->Outstanding > 0 || ($subscription->Outstanding == 0 && $subscription->StartDate['year'] < $current_year)) {
              // Don't list old subscriptions on the subscriptions tab.
              continue;
            }
            $details .= "{$subscription->membershipType->SubDescription} 1 Jan {$subscription->StartDate['year']} - 31 Dec {$subscription->StartDate['year']}<br />\r\n";
          }

          // Get the last donation given by the member.
          if (count($donations) > 1) {
            // The ledger system has two entries for a transaction.
            // The last one shows the total amount negative.
            $donation = $donations[count($donations) - 1]->Total * -1;
            if ($donation > 0) {
                $details .= t('Last donation: £ !donation', array('!donation' => $donation)) . "<br />\r\n";
              }
            }

            $details .= "</p>\r\n";
            $replacements[$original] = $details;
          }
          catch (Exception $e) {
            $replacements[$original] = t('Unable to connect to membership database.');
          }
          break;
      }
    }
  }*/

  return $replacements;
}
