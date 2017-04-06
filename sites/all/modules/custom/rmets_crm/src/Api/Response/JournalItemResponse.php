<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\JournalItem;
/**
 *
 */
class JournalItemResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return JournalItem[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new JournalItem($item);
    }
    return $items;
  }

}
