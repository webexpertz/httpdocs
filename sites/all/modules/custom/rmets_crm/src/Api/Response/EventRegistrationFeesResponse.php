<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\EventRegistrationFees;
/**
 *
 */
class EventRegistrationFeesResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Event[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new EventRegistrationFees($item);
    }
    return $items;
  }

}
