<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Driver;

use Drupal\rmets_crm\Api\Request\RequestInterface;
use Drupal\rmets_crm\Api\Request\RequestPostInterface;

/**
 *
 */
interface DriverInterface {

  /**
   * Provide configuration options in an array.
   *
   * All options will be supplied and drivers can choose which to implement.
   *
   * @param array $conf
   */
  public function __construct($conf);

  public function get($endpoint, RequestInterface $request = NULL);

  public function post($endpoint, RequestPostInterface $request = NULL);

}
