<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\Suffix;
/**
 *
 */
class SuffixResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Suffix[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new Suffix($item);
    }
    return $items;
  }

}
