<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class GetMemberUnpaidSubscriptionPaymentsRequest extends AbstractRequest implements GuidRequestInterface, PagedRequestInterface, RecordCountRequestInterface {

  public function getRequiredParams() {
    return array('guid', 'subscriptionId', 'page', 'recordcount');
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
   * Set the subscription id to retrieve records for.
   *
   * @param string $subscriptionId
   *   The subscription id to set to.
   *
   * @return $this
   */
  public function setSubscriptionId($subscriptionId) {
    $this->setParam('subscriptionId', $subscriptionId);
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
