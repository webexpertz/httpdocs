<?php
/**
 * @file
 * Created by PhpStorm.
 * User: danj
 * Date: 13/03/15
 * Time: 14:46.
 */

namespace Drupal\rmets_crm\Api\Request;
/**
 *
 */
interface PagedRequestInterface extends RequestInterface {

  /**
   * Set the page number.
   *
   * @param int $page
   *   The page number to set to.
   *
   * @return $this
   */
  public function setPage($page);

}
