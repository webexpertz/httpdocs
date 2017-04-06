<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\EventAbstract;
/**
 *
 */
class EventAbstractResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return EventAbstract[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new EventAbstract($item);
    }
    return $items;
  }

}
