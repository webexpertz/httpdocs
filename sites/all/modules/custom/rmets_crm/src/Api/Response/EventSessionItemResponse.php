<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\EventSessionItem;
/**
 *
 */
class EventSessionItemResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return EventSessionItem[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new EventSessionItem($item);
    }
    return $items;
  }

}
