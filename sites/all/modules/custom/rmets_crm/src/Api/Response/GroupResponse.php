<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\Group;
/**
 *
 */
class GroupResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Group[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new Group($item);
    }
    return $items;
  }

}
