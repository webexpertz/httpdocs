<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class CreateContactSubscriptionRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function __construct() {
    $this->setSubEntities(array());
  }

  public function getRequiredParams() {
    return array('guid', 'contactID', 'packagePriceID', 'subEntities');
  }

  public function getOptionalParams() {
    return array('donation', 'giftFrom', 'sponsors', 'reciprocalOrganisationID', 'reciprocalMembershipNumber');
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
   * Set the package price id.
   *
   * @param string $packagePriceId
   *   The membership package price to set to.
   *
   * @return $this
   */
  public function setPackagePriceId($packagePriceId) {
    $this->setParam('packagePriceID', $packagePriceId);
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
   * Set the gift from.
   *
   * @param string $giftFrom
   *   The ContactID of who this subscription is from.
   *
   * @return $this
   */
  public function setGiftFrom($giftFrom) {
    $this->setParam('giftFrom', $giftFrom);
    return $this;
  }

  /**
   * Set the sponsors.
   *
   * @param string $sponsors
   *   The sponsors to set to.
   *
   * @return $this
   */
  public function setSponsors($sponsors) {
    $this->setParam('sponsors', $sponsors);
    return $this;
  }

  /**
   * @param $journalId
   */
  public function addJournal($journalId) {
    $journals = $this->getParam('subEntities');
    $item = new \stdClass();
    $item->JournalItemID = $journalId;
    $journals[] = $item;
    $this->setParam('subEntities', $journals);
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
   * Set the reciprocal organisation id.
   *
   * @param int $reciprocalOrganisationID
   *   The reciprocal organisation id to set to.
   *
   * @return $this
   */
  public function setReciprocalOrganisationID($reciprocalOrganisationID) {
    $this->setParam('reciprocalOrganisationID', $reciprocalOrganisationID);
    return $this;
  }

  /**
   * Set the reciprocal membership number.
   *
   * @param string $reciprocalMembershipNumber
   *   The reciprocal membership number to set to.
   *
   * @return $this
   */
  public function setReciprocalMembershipNumber($reciprocalMembershipNumber) {
    $this->setParam('reciprocalMembershipNumber', $reciprocalMembershipNumber);
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
