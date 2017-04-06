<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\MembershipPackagePrice;
/**
 *
 */
class MembershipPackagePricesResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return MembershipPackagePrice[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new MembershipPackagePrice($item);
    }
    return $items;
  }

}
