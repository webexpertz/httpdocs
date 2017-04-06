<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\JournalSubscriptionItem;
/**
 *
 */
class JournalSubscriptionItemResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return JournalSubscriptionItem[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new JournalSubscriptionItem($item);
    }
    return $items;
  }

}
