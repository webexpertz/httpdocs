<?php

/**
 * @file
 */

use Drupal\rmets_membership_purchase\EntityWrapper\CommerceLineItem\CommerceLineItemWrapper;
use Drupal\rmets_events\EntityWrapper\Node\EventWrapper;

/**
 * Implements of hook_drush_command().
 */
function play_drush_command() {
  $items = array();

  $items['play'] = array(
    'description' => 'Generate a report to list all payments to an event.',
    'aliases' => array('ps'),
    'argumnets' => array(
      'node_id' => 'The node id of the event node',
    ),
  );

  return $items;
}

/**
 * Generate a report of people who registered for an event.
 */
function drush_play($node_id) {
  global $base_url;

  $event = EventWrapper::GetObject($node_id);
  $event_id = $event->getEventId();

  drush_print('Generating all transactions for: ' . $event->label());
  drush_print('CRM ID: ' . $event_id);

  // We use a like to find the unique id for the event in the data field.
  // Don't worry, we double check everything that comes back later.
  $line_item_ids = db_select('commerce_line_item', 'cli')
    ->fields('cli', ['line_item_id'])
    ->condition('data',  '%' . db_like($event_id) . '%', 'LIKE')
    ->execute()
    ->fetchCol();

  drush_print('Number of commerce line items: ' . count($line_item_ids));

  $items = [];

  $items[] = [
    'email',
    'title',
    'forenames',
    'surname',
    'dob',
    'affiliate_name',
    'product_name',
    'website_id',
    'crm_id',
    'order_link',
    'balance to pay',
    'transactions',
    'email date',
  ];

  foreach ($line_item_ids as $line_item_id) {
    $line_item = CommerceLineItemWrapper::GetObject($line_item_id);

    $order =  $line_item->getOrder();
    $data = $line_item->getData();

    if ($data['event_id'] != $node_id || empty($order)) {
      // If this transaction is not really for the current event then skip it.
      continue;
    }

    $balance = $order->getBalance();

    if (empty($data['email'])) {
      // The user is the order owner as this person did not fill in the form.
      $user = $order->getOwner();
      $data['email'] = $user->mail->value();
      $data['forenames'] = $user->field_forenames->value();
      $data['surname'] = $user->field_surname->value();
    }

    // The data about the user is attached to the order.
    $items[] = [
      'email' => strtolower($data['email']),
      'title' => $data['title'],
      'forenames' => $data['forenames'],
      'surname' => $data['surname'],
      'dob' => $data['date_of_birth'],
      'affiliate_name' => $data['affiliate_name'],
      'product_name' => $data['title_of_item'],
      'website_id' => $data['event_id'],
      'crm_id' => $data['crm_event_id'],
      'order_link' => 'https://www.rmets.org/admin/commerce/orders/' . $order->getIdentifier() . '/view',
      'balance' => commerce_currency_format($balance['amount'], $balance['currency_code']),
      'transactions' => $order->getTransactionString(),
      'email_date' => '',
    ];

  }

  // Lets see what Maillog sent out by checking the known subject pattern.
  $emails = db_select('maillog', 'm')
    ->fields('m', ['idmaillog', 'header_to', 'sent_date'])
    ->condition('m.subject', 'Thank you for registering for: ' . $event->label())
    ->execute()
    ->fetchAllAssoc('idmaillog');

  foreach ($emails as $email_key => $details) {
    foreach ($items as $key => $purchase) {
      // Check if this maillog email is referring to this person
      // And if a previous email didn't refer to this person
      // And if this person managed to clear their balance this time then
      // this must be the email for them, probably.
      if ($purchase['email'] == strtolower($details->header_to) && empty($items[$key]['email_date']) && (empty($items[$key]['balance']) || $items[$key]['balance'] == '£0.00')) {
        $items[$key]['email_date'] = date('c', $details->sent_date);
        unset($emails[$email_key]);
        continue 2;
      }
    }
  }

  if (!empty($emails)) {
    drush_print('Number of registrations with no payment trail: ' . count($emails));
  }

  // We don't have much to go on with users that got in for free as the data
  // would otherwise be stored on the line items which we do not have.
  foreach ($emails as $details) {
    $items[] = [
      'email' => strtolower($details->header_to),
      'title' => '',
      'forenames' => '',
      'surname' => '',
      'dob' => '',
      'affiliate_name' => '',
      'product_name' => '',
      'website_id' => $event->getIdentifier(),
      'crm_id' => $event_id,
      'order_link' => '',
      'balance' => '',
      'transactions' => '',
      'email_date' => date('c', $details->sent_date),
    ];
  }

  $uri = 'public://' . $event_id . '.csv';
  $fp = fopen($uri, 'w');
  foreach ($items as $item) {
    fputcsv($fp, $item);
  }
  fclose($fp);

  drush_print('done');
  drush_print('Download: ' . file_create_url($uri));
}