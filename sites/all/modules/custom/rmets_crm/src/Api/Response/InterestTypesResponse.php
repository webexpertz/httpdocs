<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\Interest;

/**
 *
 */
class InterestTypesResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Interest[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new Interest($item);
    }
    return $items;
  }

}
