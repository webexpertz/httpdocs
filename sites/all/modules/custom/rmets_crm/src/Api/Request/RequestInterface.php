<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Request;
/**
 *
 */
interface RequestInterface {

  public function validate();

  public function getParams();

  public function setParam($key, $value);

  public function setParams(array $params);

  public function getParam($key, $default = NULL);

  public function getRequiredParams();

  public function getOptionalParams();

  public function isCacheable();

  public function getCacheLifetime();

}

interface RequestPostInterface extends RequestInterface {

  public function getHttpPostRequestBody();

}