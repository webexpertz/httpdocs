<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
interface GuidRequestInterface extends RequestInterface {

  /**
   * Set the guid for the request.
   *
   * @param string $guid
   *   The guid value to set.
   *
   * @return $this
   */
  public function setGuid($guid);

}
