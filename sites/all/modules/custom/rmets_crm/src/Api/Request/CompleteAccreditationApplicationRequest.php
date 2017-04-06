<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class CompleteAccreditationApplicationRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function getRequiredParams() {
    return array('guid', 'accreditationItemID');
  }

  public function getOptionalParams() {
    return array();
  }

  /**
   * Set the guid for the request.
   *
   * @param string $guid
   *   The guid value to set.
   *
   * @return $this
   */
  public function setGuid($guid) {
    $this->setParam('guid', $guid);
    return $this;
  }

  /**
   * Set the accreditation application Id.
   *
   * @param string $accreditationApplicationId
   *   The accreditation application Id to set to.
   *
   * @return $this
   */
  public function setAccreditationApplicationId($accreditationApplicationId) {
    $this->setParam('accreditationApplicationID', $accreditationApplicationId);
    return $this;
  }

  /**
   * {inheritdoc}
   * @return bool
   */
  public function isCacheable() {
    return FALSE;
  }
}
