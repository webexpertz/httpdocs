<?php

/**
 * @file
 * Generic paragraph base wrapper class.
 */

namespace Drupal\rmets_membership_purchase\EntityWrapper\CommerceLineItem;

use Drupal\rmets_membership_purchase\EntityWrapper\CommerceOrder\CommerceOrderWrapper;
use \EntityDrupalWrapper;

/**
 * Generically wraps paragraphs.
 */
class CommerceLineItemWrapper extends EntityDrupalWrapper {

  /**
   * Get a wrapped paragraph_item object.
   *
   * @param int|object $data
   *   A paragraph_item id or paragraph_item object.
   *
   * @return CommerceLineItemWrapper
   */
  public static function GetObject($data) {
    $line_item = commerce_line_item_load($data);
    return new CommerceLineItemWrapper($line_item);
  }

  /**
   * Wrap a Commerce Line Item object.
   *
   * @param int|object $data
   *   A loaded entity object.
   *
   * @return CommerceLineItemWrapper
   */
  public function __construct($data) {
    parent::__construct('commerce_line_item', $data);
  }

  /**
   * @return CommerceOrderWrapper
   */
  public function getOrder() {
    $order_id = $this->order_id->value();
    return CommerceOrderWrapper::GetObject($order_id);
  }

  /**
   * @return mixed
   */
  public function getData() {
    return $this->value()->data;
  }
}
