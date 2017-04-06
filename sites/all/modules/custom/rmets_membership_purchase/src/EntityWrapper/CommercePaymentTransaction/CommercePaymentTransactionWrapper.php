<?php

/**
 * @file
 * Generic payment base wrapper class.
 */

namespace Drupal\rmets_membership_purchase\EntityWrapper\CommercePaymentTransaction;

use \EntityDrupalWrapper;

/**
 * Generically wraps payments.
 */
class CommercePaymentTransactionWrapper extends EntityDrupalWrapper {

  /**
   * Get a wrapped commerce_payment_transaction object.
   *
   * @param int|object $data
   *   A commerce_payment_transaction id or commerce_payment_transaction object.
   *
   * @return CommercePaymentTransactionWrapper
   */
  public static function GetObject($data) {
    return new CommercePaymentTransactionWrapper($data);
  }

  /**
   * Wrap a Commerce Order object.
   *
   * @param int|object $data
   *   An entity id or entity object.
   *
   * @return CommercePaymentTransactionWrapper
   */
  public function __construct($data) {
    parent::__construct('commerce_payment_transaction', $data);
  }

  public function getStatus() {
    return $this->status->value();
  }

  /**
   * @return string
   *   The machine name of the payment method
   */
  public function getPaymentMethod() {
    return $this->payment_method->value();
  }

  /**
   * @return string
   *   The total amount in pence (e.g. "3500" is £35.00)
   */
  public function getAmount() {
    $amount = $this->amount->value();
    return $amount;
  }

  /**
   * @return string
   *   The currency code e.g. "GBP"
   */
  public function getCurrencyCode() {
    return $this->currency_code->value();
  }

}
