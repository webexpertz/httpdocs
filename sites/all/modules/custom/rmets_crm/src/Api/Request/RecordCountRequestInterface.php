<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
interface RecordCountRequestInterface extends RequestInterface {

  /**
   * Set the number of records to be returned.
   *
   * @param int $count
   *   The record count to set to.
   *
   * @return $this
   */
  public function setRecordCount($count);

}
