<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_subscription
class Subscription extends AbstractModel {

  protected $subscriptionID;
  protected $membershipPackagePriceName;
  protected $membershipPackagePriceID;
  protected $validFrom;
  protected $validTo;
  protected $memberStatus;
  protected $membershipNumber;
  protected $joiningFee;
  protected $contactID;
  protected $accreditationItemID;
  protected $accreditationName;
  protected $packageID;

  /**
   * @return mixed
   */
  public function getSubscriptionID() {
    return $this->subscriptionID;
  }

  /**
   * @param mixed $subscriptionID
   */
  public function setSubscriptionID($subscriptionID) {
    $this->subscriptionID = $subscriptionID;
  }

  /**
   * @return mixed
   */
  public function getMembershipPackagePriceName() {
    return $this->membershipPackagePriceName;
  }

  /**
   * @param mixed $membershipPackagePriceName
   */
  public function setMembershipPackagePriceName($membershipPackagePriceName) {
    $this->membershipPackagePriceName = $membershipPackagePriceName;
  }

  /**
   * @return mixed
   */
  public function getMembershipPackagePriceID() {
    return $this->membershipPackagePriceID;
  }

  /**
   * @param mixed $membershipPackagePriceID
   */
  public function setMembershipPackagePriceID($membershipPackagePriceID) {
    $this->membershipPackagePriceID = $membershipPackagePriceID;
  }

  /**
   * @return mixed
   */
  public function getValidFrom() {
    return $this->validFrom;
  }

  /**
   * @return mixed
   */
  public function getValidFromDate() {
    list($date, ) = explode(' ', $this->validFrom);
    return $date;
  }

  /**
   * @param mixed $validFrom
   */
  public function setValidFrom($validFrom) {
    $this->validFrom = $validFrom;
  }

  /**
   * @return mixed
   */
  public function getValidTo() {
    return $this->validTo;
  }

  /**
   * @return mixed
   */
  public function getValidToDate() {
    list($date, ) = explode(' ', $this->validTo);
    return $date;
  }

  /**
   * @param mixed $validTo
   */
  public function setValidTo($validTo) {
    $this->validTo = $validTo;
  }

  /**
   * @return mixed
   */
  public function getMemberStatus() {
    return $this->memberStatus;
  }

  /**
   * @param mixed $memberStatus
   */
  public function setMemberStatus($memberStatus) {
    $this->memberStatus = $memberStatus;
  }

  /**
   * @return mixed
   */
  public function getMembershipNumber() {
    return $this->membershipNumber;
  }

  /**
   * @param mixed $membershipNumber
   */
  public function setMembershipNumber($membershipNumber) {
    $this->membershipNumber = $membershipNumber;
  }

  /**
   * @return mixed
   */
  public function getJoiningFee() {
    return $this->joiningFee;
  }

  /**
   * @param mixed $joiningFee
   */
  public function setJoiningFee($joiningFee) {
    $this->joiningFee = $joiningFee;
  }

  /**
   * @return mixed
   */
  public function getContactID() {
    return $this->contactID;
  }

  /**
   * @param mixed $contactID
   */
  public function setContactID($contactID) {
    $this->contactID = $contactID;
  }

  /**
   * @return mixed
   */
  public function getAccreditationItemID() {
    return $this->accreditationItemID;
  }

  /**
   * @param mixed $accreditationItemID
   */
  public function setAccreditationItemID($accreditationItemID) {
    $this->accreditationItemID = $accreditationItemID;
  }

  /**
   * @return mixed
   */
  public function getAccreditationName() {
    return $this->accreditationName;
  }

  /**
   * @param mixed $accreditationName
   */
  public function setAccreditationName($accreditationName) {
    $this->accreditationName = $accreditationName;
  }

  /**
   * @return mixed
   */
  public function getPackageID() {
    return $this->packageID;
  }

  /**
   * @param mixed $packageID
   */
  public function setPackageID($packageID) {
    $this->packageID = $packageID;
  }


}