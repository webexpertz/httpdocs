<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\Subscription;
/**
 *
 */
class SubscriptionResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Subscription[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new Subscription($item);
    }
    return $items;
  }

}
