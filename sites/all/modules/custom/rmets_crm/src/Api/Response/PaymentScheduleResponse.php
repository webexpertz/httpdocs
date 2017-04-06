<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\PaymentSchedule;
/**
 *
 */
class PaymentScheduleResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return PaymentSchedule[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new PaymentSchedule($item);
    }
    return $items;
  }

}
