<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class MarkSubscriptionPaymentsAsPaidRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function getRequiredParams() {
    return array('guid', 'subscriptionID');
  }

  public function getOptionalParams() {
    return array('donation');
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
   *   The subscription Id to set to.
   *
   * @return $this
   */
  public function setSubscriptionId($subscriptionId) {
    $this->setParam('subscriptionID', $subscriptionId);
    return $this;
  }

  /**
   * Set the donation.
   *
   * @param string $donation
   *   The donation to set to.
   *
   * @return $this
   */
  public function setDonation($donation) {
    $this->setParam('donation', $donation);
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
