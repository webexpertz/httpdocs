<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
abstract class AbstractRequest implements RequestInterface {
  protected $params = array();

  protected $cacheable = NULL;

  public function setParam($key, $value) {
    $this->params[$key] = $value;
    return $this;
  }

  public function setParams(array $params) {
    foreach ($params as $key => $value) {
      $this->setParam($key, $value);
    }
    return $this;
  }

  public function getParam($key, $default = NULL) {
    if (isset($this->params[$key])) {
      return $this->params[$key];
    }

    $optional = $this->getOptionalParams();
    if (in_array($key, $optional)) {
      return $default;
    }

    throw new \LogicException('Non optional param "' . $key . '" is missing.');
  }

  public function getParams() {
    return $this->params;
  }

  public function validate() {
    // Ignore empty values as invalid.
    $params = array_filter($this->getParams());

    $required = array_flip($this->getRequiredParams());

    // Check that all required parameters are specified.
    $supplied_required_params = array_intersect_key($required, $params);
    if (count($required) !== count($supplied_required_params)) {
      return array('Missing parameters: ' . implode(', ', array_keys(array_diff_key($required, $supplied_required_params))));
    }

    $params_not_required = array_diff_key($params, $required);
    $optional = array_flip($this->getOptionalParams());

    // Check that only recognised parameters are left.
    if ($unexpected = array_diff_key($params_not_required, $optional)) {
      return array('Unexpected parameters: ' . implode(', ', $unexpected));
    }

    return array();
  }

  public function setIsCacheable($cacheable) {
    $this->cacheable = $cacheable;
  }

  public function isCacheable() {
    if (!is_null($this->cacheable)) {
      return $this->cacheable;
    }
    return variable_get('rmets_crm_enable_cache', TRUE);
  }

  public function getCacheLifetime() {
    return 3600;
  }

  abstract public function getRequiredParams();
  abstract public function getOptionalParams();

}
