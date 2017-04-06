<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\EventSession;
/**
 *
 */
class EventSessionResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return EventSession[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new EventSession($item);
    }
    return $items;
  }

}
