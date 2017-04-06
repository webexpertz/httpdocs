<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\Contact;
/**
 *
 */
class ContactsResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return Contact[]
   */
  public function buildItems(array $items) {
    if (empty($items)) {
      return array();
    }

    foreach ($items as $i => $item) {
      $items[$i] = new Contact($item);
    }
    return $items;
  }

}
