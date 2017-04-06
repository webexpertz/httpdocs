<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

use Drupal\rmets_crm\Model\EventSpeaker;
/**
 *
 */
class EventSpeakerResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return EventSpeaker[]
   */
  public function buildItems(array $items) {
    foreach ($items as $i => $item) {
      $items[$i] = new EventSpeaker($item);
    }
    return $items;
  }

}
