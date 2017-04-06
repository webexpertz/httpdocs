<?php

/**
 * @file
 * Generic paragraph base wrapper class.
 */

namespace Drupal\rmets_membership_purchase\EntityWrapper\CommerceOrder;

use Drupal\rmets_membership_purchase\EntityWrapper\CommercePaymentTransaction\CommercePaymentTransactionWrapper;
use \EntityDrupalWrapper;

/**
 * Generically wraps paragraphs.
 */
class CommerceOrderWrapper extends EntityDrupalWrapper {

  /**
   * Get a wrapped commerce_order object.
   *
   * @param int|object $data
   *   A commerce_order id or commerce_order object.
   *
   * @return CommerceOrderWrapper
   */
  public static function GetObject($data) {
    return new CommerceOrderWrapper($data);
  }

  /**
   * Wrap a Commerce Order object.
   *
   * @param int|object $data
   *   An entity id or entity object.
   *
   * @return CommerceOrderWrapper
   */
  public function __construct($data) {
    parent::__construct('commerce_order', $data);
  }

  /**
   * Get all transactions for this order.
   *
   * @return CommercePaymentTransactionWrapper[]
   */
  public function getTransactions() {
    $transactions = [];

    $transaction_ids = db_select('commerce_payment_transaction', 'cpt')
      ->fields('cpt', ['transaction_id'])
      ->condition('cpt.order_id', $this->getIdentifier())
      ->execute()
      ->fetchCol();

    foreach ($transaction_ids as $transaction_id) {
      $transactions[$transaction_id] = CommercePaymentTransactionWrapper::GetObject($transaction_id);
    }

    return $transactions;
  }

  /**
   * $balance = $order->getBalance();
   * commerce_currency_format($balance['amount'], $balance['currency_code']);
   *
   * @return array
   *   with keys 'amount' and 'currency_code'
   *
   * @throws \Exception
   */
  public function getBalance() {
    return commerce_payment_order_balance($this->value());
  }

  /**
   * @return string
   *   A string representing the transaction.
   */
  public function getTransactionString() {
    $output = [];

    foreach ($this->getTransactions() as $transaction) {
      $output[] = $transaction->getStatus() . ': ' . commerce_currency_format($transaction->getAmount(), $transaction->getCurrencyCode()) . ' [' . $transaction->getPaymentMethod() . ']';
    }

    return implode(' | ', $output);
  }

  /**
   * @return EntityDrupalWrapper
   *   Loaded user
   */
  public function getOwner() {
    $uid = $this->uid->value();
    return entity_metadata_wrapper('user', $uid);
  }

}
