<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\Donation;
/**
 *
 */
class DonationResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Donation[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new Donation($item);
    }
    return $items;
  }

}
