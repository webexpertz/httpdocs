<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\Accreditation;
/**
 *
 */
class AccreditationResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Accreditation[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new Accreditation($item);
    }
    return $items;
  }

}
