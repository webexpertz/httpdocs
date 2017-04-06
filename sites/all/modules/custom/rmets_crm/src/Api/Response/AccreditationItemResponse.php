<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\AccreditationItem;
/**
 *
 */
class AccreditationItemResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return AccreditationItem[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new AccreditationItem($item);
    }
    return $items;
  }

}
