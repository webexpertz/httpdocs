<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\OptionsetObject;
/**
 *
 */
class OptionsetResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return OptionsetObject[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new OptionsetObject($item);
    }
    return $items;
  }

}
