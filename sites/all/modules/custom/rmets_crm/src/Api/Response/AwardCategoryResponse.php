<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\AwardCategory;
/**
 *
 */
class AwardCategoryResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return AwardCategory[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new AwardCategory($item);
    }
    return $items;
  }

}
