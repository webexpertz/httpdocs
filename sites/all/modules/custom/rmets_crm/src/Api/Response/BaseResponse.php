<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Response;

/**
 *
 */
class BaseResponse extends AbstractResponse {

  /**
   * @param array $items
   *
   * @return array
   */
  public function buildItems(array $items) {
    if (empty($items)) {
      return array();
    }
    return $items;
  }

}
