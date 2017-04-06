<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\EventTheme;
/**
 *
 */
class EventThemeResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return EventTheme[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new EventTheme($item);
    }
    return $items;
  }

}
