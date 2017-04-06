<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class CreateAccreditationApplicationRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function getRequiredParams() {
    return array('guid', 'contactID', 'accreditationItemID');
  }

  public function getOptionalParams() {
    return array('URL');
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
   * Set the contact id.
   *
   * @param string $contactId
   *   The contact id to set to.
   *
   * @return $this
   */
  public function setContactId($contactId) {
    $this->setParam('contactID', $contactId);
    return $this;
  }

  /**
   * Set the accreditation Item Id.
   *
   * @param string $accreditationItemId
   *   The accreditation Item Id to set to.
   *
   * @return $this
   */
  public function setAccreditationItemId($accreditationItemId) {
    $this->setParam('accreditationItemID', $accreditationItemId);
    return $this;
  }

  /**
   * Set the url.
   *
   * @param string $url
   *   The url to set to.
   *
   * @return $this
   */
  public function setUrl($url) {
    $this->setParam('URL', $url);
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
