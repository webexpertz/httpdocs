<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class UpdateContactSuffixesRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function __construct() {
    $this->setSubEntities(array());
  }

  public function getRequiredParams() {
    return array('guid', 'contactID', 'subEntities');
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
   * Set the abstract id.
   *
   * @param string $abstractId
   *   The abstract id to set to.
   *
   * @return $this
   */
  public function setContactId($abstractId) {
    $this->setParam('contactID', $abstractId);
    return $this;
  }

  /**
   * Set the sub entities.
   *
   * @param array $subEntities
   *   The subEntities to set to.
   *
   * @return $this
   */
  public function setSubEntities(array $subEntities) {
    $this->setParam('subEntities', $subEntities);
    return $this;
  }

  /**
   * @param $contactID
   */
  public function addSuffixId($suffixID) {
    $suffixes = $this->getParam('subEntities');
    $item = new \stdClass();
    $item->SuffixID = $suffixID;
    $suffixes[] = $item;
    $this->setParam('subEntities', $suffixes);
  }

  /**
   * {inheritdoc}
   * @return bool
   */
  public function isCacheable() {
    return FALSE;
  }
}
