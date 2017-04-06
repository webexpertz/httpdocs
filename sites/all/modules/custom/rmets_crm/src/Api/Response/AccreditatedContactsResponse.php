<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\AccreditatedContact;
/**
 *
 */
class AccreditatedContactsResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return AwardWinner[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new AccreditatedContact($item);
    }
    return $items;
  }

}
