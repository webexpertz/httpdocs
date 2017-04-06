<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\FrmetsContact;
/**
 *
 */
class FrmetsContactsResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return FrmetsContact[]
   */
  public function buildItems(array $items) {
    if (empty($items)) {
      return array();
    }

    foreach ($items as $i => $item) {
      $items[$i] = new FrmetsContact($item);
    }
    return $items;
  }

}
