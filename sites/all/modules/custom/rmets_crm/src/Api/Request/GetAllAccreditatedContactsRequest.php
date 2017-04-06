<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class GetAllAccreditatedContactsRequest extends AbstractRequest implements GuidRequestInterface, PagedRequestInterface, RecordCountRequestInterface {

  public function getRequiredParams() {
    return array('guid', 'accreditationID', 'page', 'recordcount');
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
   * Set the accreditation id.
   *
   * @param int $accreditationId
   *   The accreditation id to set to.
   *
   * @return $this
   */
  public function setAccreditationId($accreditationId) {
    $this->setParam('accreditationID', $accreditationId);
    return $this;
  }

  /**
   * Set the page number.
   *
   * @param int $page
   *   The page number to set to.
   *
   * @return $this
   */
  public function setPage($page) {
    $this->setParam('page', $page);
    return $this;
  }

  /**
   * Set the number of records to be returned.
   *
   * @param int $count
   *   The record count to set to.
   *
   * @return $this
   */
  public function setRecordCount($count) {
    $this->setParam('recordcount', $count);
    return $this;
  }
}
