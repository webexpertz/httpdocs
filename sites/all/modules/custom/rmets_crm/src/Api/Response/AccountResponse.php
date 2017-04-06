<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\Account;
/**
 *
 */
class AccountResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Account[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new Account($item);
    }
    return $items;
  }

}
