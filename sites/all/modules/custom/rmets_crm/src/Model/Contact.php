<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

class Contact extends AbstractModel {

  protected $contactID;
  protected $title;
  protected $forenames;
  protected $surname;
  protected $dateOfBirth;
  protected $membershipNumber;
  protected $email;
  protected $businessPhone;
  protected $mobilePhone;
  protected $homePhone;
  protected $organisationID;
  protected $organisationName;
  protected $gender;
  protected $marketingMaterials;
  protected $address1;
  protected $address2;
  protected $address3;
  protected $city;
  protected $stateProvince;
  protected $postCode;
  protected $country;
  protected $snd_Address1;
  protected $snd_Address2;
  protected $snd_Address3;
  protected $snd_City;
  protected $snd_StateProvince;
  protected $snd_PostCode;
  protected $snd_Country;
  protected $activeSubscriptionID;
  protected $occupation;
  protected $otherOccupation;
  protected $hearAboutRMetS;
  protected $graduationDate;
  protected $giftAid;

  // Local vars.
  protected $interestTypes;

  function __construct(array $item) {
    parent::__construct($item);
  }

  /**
   * @return mixed
   */
  public function getContactId() {
    return $this->contactID;
  }

  /**
   * @param mixed $contactID
   */
  public function setContactId($contactID) {
    $this->contactID = $contactID;
  }

  /**
   * @return mixed
   */
  public function getTitle() {
    return $this->title;
  }

  /**
   * @param mixed $title
   */
  public function setTitle($title) {
    $this->title = $title;
  }

  /**
   * @return mixed
   */
  public function getForenames() {
    return $this->forenames;
  }

  /**
   * @param mixed $forenames
   */
  public function setForenames($forenames) {
    $this->forenames = $forenames;
  }

  /**
   * @return mixed
   */
  public function getSurname() {
    return $this->surname;
  }

  /**
   * @param mixed $surname
   */
  public function setSurname($surname) {
    $this->surname = $surname;
  }

  /**
   * @return mixed
   */
  public function getDateOfBirth() {
    return $this->dateOfBirth;
  }

  /**
   * @param mixed $dateOfBirth
   */
  public function setDateOfBirth($dateOfBirth) {
    $this->dateOfBirth = $dateOfBirth;
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
  public function getEmail() {
    return trim($this->email);
  }

  /**
   * @param mixed $email
   */
  public function setEmail($email) {
    $this->email = $email;
  }

  /**
   * @return mixed
   */
  public function getHomePhone() {
    return $this->homePhone;
  }

  /**
   * @param mixed $homePhone
   */
  public function setHomePhone($homePhone) {
    $this->homePhone = $homePhone;
  }

  /**
   * @return mixed
   */
  public function getBusinessPhone() {
    return $this->businessPhone;
  }

  /**
   * @param mixed $businessPhone
   */
  public function setBusinessPhone($businessPhone) {
    $this->businessPhone = $businessPhone;
  }

  /**
   * @return mixed
   */
  public function getMobilePhone() {
    return $this->mobilePhone;
  }

  /**
   * @param mixed $mobilePhone
   */
  public function setMobilePhone($mobilePhone) {
    $this->mobilePhone = $mobilePhone;
  }

  /**
   * @return mixed
   */
  public function getOrganisationId() {
    return $this->organisationID;
  }

  /**
   * @param mixed $organisationID
   */
  public function setOrganisationId($organisationID) {
    $this->organisationID = $organisationID;
  }

  /**
   * @return mixed
   */
  public function getGender() {
    return $this->gender;
  }

  /**
   * @param mixed $gender
   */
  public function setGender($gender) {
    $this->gender = $gender;
  }

  /**
   * @return mixed
   */
  public function getMarketingMaterials() {
    return $this->marketingMaterials;
  }

  /**
   * @param mixed $marketingMaterials
   */
  public function setMarketingMaterials($marketingMaterials) {
    $this->marketingMaterials = $marketingMaterials;
  }

  /**
   * @return mixed
   */
  public function getAddress1() {
    return $this->address1;
  }

  /**
   * @param mixed $address1
   */
  public function setAddress1($address1) {
    $this->address1 = $address1;
  }

  /**
   * @return mixed
   */
  public function getAddress2() {
    return $this->address2;
  }

  /**
   * @param mixed $address2
   */
  public function setAddress2($address2) {
    $this->address2 = $address2;
  }

  /**
   * @return mixed
   */
  public function getAddress3() {
    return $this->address3;
  }

  /**
   * @param mixed $address3
   */
  public function setAddress3($address3) {
    $this->address3 = $address3;
  }

  /**
   * @return mixed
   */
  public function getCity() {
    return $this->city;
  }

  /**
   * @param mixed $city
   */
  public function setCity($city) {
    $this->city = $city;
  }

  /**
   * @return mixed
   */
  public function getStateProvince() {
    return $this->stateProvince;
  }

  /**
   * @param mixed $stateProvince
   */
  public function setStateProvince($stateProvince) {
    $this->stateProvince = $stateProvince;
  }

  /**
   * @return mixed
   */
  public function getPostCode() {
    return $this->postCode;
  }

  /**
   * @param mixed $postCode
   */
  public function setPostCode($postCode) {
    $this->postCode = $postCode;
  }

  /**
   * @return mixed
   */
  public function getCountry() {
    return $this->country;
  }

  /**
   * @param mixed $country
   */
  public function setCountry($country) {
    $this->country = $country;
  }

  /**
   * @return mixed
   */
  public function get2ndAddress1() {
    return $this->snd_Address1;
  }

  /**
   * @param mixed $snd_Address1
   */
  public function set2ndAddress1($snd_Address1) {
    $this->snd_Address1 = $snd_Address1;
  }

  /**
   * @return mixed
   */
  public function get2ndAddress2() {
    return $this->snd_Address2;
  }

  /**
   * @param mixed $snd_Address2
   */
  public function set2ndAddress2($snd_Address2) {
    $this->snd_Address2 = $snd_Address2;
  }

  /**
   * @return mixed
   */
  public function get2ndAddress3() {
    return $this->snd_Address3;
  }

  /**
   * @param mixed $snd_Address3
   */
  public function set2ndAddress3($snd_Address3) {
    $this->snd_Address3 = $snd_Address3;
  }

  /**
   * @return mixed
   */
  public function get2ndCity() {
    return $this->snd_City;
  }

  /**
   * @param mixed $snd_City
   */
  public function set2ndCity($snd_City) {
    $this->snd_City = $snd_City;
  }

  /**
   * @return mixed
   */
  public function get2ndStateProvince() {
    return $this->snd_StateProvince;
  }

  /**
   * @param mixed $snd_StateProvince
   */
  public function set2ndStateProvince($snd_StateProvince) {
    $this->snd_StateProvince = $snd_StateProvince;
  }

  /**
   * @return mixed
   */
  public function get2ndPostCode() {
    return $this->snd_PostCode;
  }

  /**
   * @param mixed $snd_PostCode
   */
  public function set2ndPostCode($snd_PostCode) {
    $this->snd_PostCode = $snd_PostCode;
  }

  /**
   * @return mixed
   */
  public function get2ndCountry() {
    return $this->snd_Country;
  }

  /**
   * @param mixed $snd_Country
   */
  public function set2ndCountry($snd_Country) {
    $this->snd_Country = $snd_Country;
  }

  /**
   * @return mixed
   */
  public function getActiveSubscriptionID() {
    return $this->activeSubscriptionID;
  }

  /**
   * @param mixed $activeSubscriptionID
   */
  public function setActiveSubscriptionID($activeSubscriptionID) {
    $this->activeSubscriptionID = $activeSubscriptionID;
  }

  /**
   * @return mixed
   */
  public function getOccupation() {
    return $this->occupation;
  }

  /**
   * @param mixed $occupation
   */
  public function setOccupation($occupation) {
    $this->occupation = $occupation;
  }

  /**
   * @return mixed
   */
  public function getOtherOccupation() {
    return $this->otherOccupation;
  }

  /**
   * @param mixed $otherOccupation
   */
  public function setOtherOccupation($otherOccupation) {
    $this->otherOccupation = $otherOccupation;
  }

  /**
   * @return mixed
   */
  public function getHearAboutRMetS() {
    return $this->hearAboutRMetS;
  }

  /**
   * @param mixed $hearAboutRMetS
   */
  public function setHearAboutRMetS($hearAboutRMetS) {
    $this->hearAboutRMetS = $hearAboutRMetS;
  }

  /**
   * @return mixed
   */
  public function getGraduationDate() {
    return $this->graduationDate;
  }

  /**
   * @param mixed $graduationDate
   */
  public function setGraduationDate($graduationDate) {
    $this->graduationDate = $graduationDate;
  }

  /**
   * @return mixed
   */
  public function getGiftAid() {
    return $this->giftAid;
  }

  /**
   * @param mixed $giftAid
   */
  public function setGiftAid($giftAid) {
    $this->giftAid = $giftAid;
  }

  /**
   * @return mixed
   */
  public function getInterestTypes() {
    return $this->interestTypes;
  }

  /**
   * @param mixed $interestTypes
   */
  public function setInterestTypes($interestTypes) {
    $this->interestTypes = $interestTypes;
  }

  /**
   * @return mixed
   */
  public function getOrganisationName() {
    return $this->organisationName;
  }

  /**
   * @param mixed $organisationName
   */
  public function setOrganisationName($organisationName) {
    $this->organisationName = $organisationName;
  }

}