<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class RemoveMemberSubscriptionJournalsRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function getRequiredParams() {
    return array('guid', 'subscriptionID');
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
   * Set the contact id.
   *
   * @param string $subscriptionId
   *   The contact id to set to.
   *
   * @return $this
   */
  public function setSubscriptionId($subscriptionId) {
    $this->setParam('subscriptionID', $subscriptionId);
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
