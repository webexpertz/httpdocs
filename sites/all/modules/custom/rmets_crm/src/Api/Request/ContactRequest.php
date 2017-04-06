<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class ContactRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function __construct() {
    $this->setSubEntities(array());
  }

  public function getRequiredParams() {
    return array('contactID', 'title', 'forenames', 'surname', 'dateOfBirth',
          'membershipNumber', 'email', 'businessPhone', 'mobilePhone', 'homePhone', 'organisationID',
          'gender', 'marketingMaterials', 'address1', 'address2', 'address3', 'city',
          'stateProvince', 'postCode', 'country', 'snd_Address1', 'snd_Address2',
          'snd_Address3', 'snd_City', 'snd_StateProvince', 'snd_PostCode',
          'snd_Country', 'hearAboutRMetS', 'graduationDate', 'occupation', 'otherOccupation',
          'giftAid', 'subEntities', 'organisationName');
  }

  public function getOptionalParams() {
    return array();
  }

  /**
   * Set the guid for the request.
   *
   * @param string $value
   *   The guid value to set.
   *
   * @return $this
   */
  public function setGuid($value) {
    $this->setParam('guid', $value);
    return $this;
  }

  /**
   * Set the contact id.
   *
   * @param string $value
   *   The contact id to set to.
   *
   * @return $this
   */
  public function setContactId($value) {
    $this->setParam('contactID', $value);
    return $this;
  }

  /**
   * Set the title.
   *
   * @param string $value
   *   The title to set to.
   *
   * @return $this
   */
  public function setTitle($value) {
    $this->setParam('title', $value);
    return $this;
  }

  /**
   * Set the forename.
   *
   * @param string $value
   *   The forename to set to.
   *
   * @return $this
   */
  public function setForename($value) {
    $this->setParam('forenames', $value);
    return $this;
  }

  /**
   * Set the surname.
   *
   * @param string $value
   *   The surname to set to.
   *
   * @return $this
   */
  public function setSurname($value) {
    $this->setParam('surname', $value);
    return $this;
  }

  /**
   * Set the email.
   *
   * @param string $value
   *   The email to set to.
   *
   * @return $this
   */
  public function setEmail($value) {
    $this->setParam('email', $value);
    return $this;
  }

  /**
   * Set the dateOfBirth.
   *
   * @param string $value
   *   The dateOfBirth to set to.
   *
   * @return $this
   */
  public function setDateOfBirth($value) {
    preg_match('/([0-9]{2})\/([0-9]{2})\/([0-9]{4}) ([0-9]{2}):([0-9]{2}):([0-9]{2})/', $value, $matches);
    if (!$matches) {
      // Not a date format, so convert timestamp to dd/mm/yyyy.
      $value = date('d/M/Y', $value);
    }
    else {
      // Setting date from Drupal, with date in yyyy-mm-dd format - convert to dd/mm/yyyy.
      preg_match('/([0-9]{4})-([0-9]{2})-([0-9]{2})/', $value, $matches);
      if ($matches) {
        $value = date('d/M/Y', strtotime($value));
      }
    }

    $this->setParam('dateOfBirth', $value);
    return $this;
  }

  /**
   * Set the membership number.
   *
   * @param string $value
   *   The membership number to set to.
   *
   * @return $this
   */
  public function setMembershipNumber($value) {
    $this->setParam('membershipNumber', $value);
    return $this;
  }

  /**
   * Set the businessPhone.
   *
   * @param string $value
   *   The businessPhone to set to.
   *
   * @return $this
   */
  public function setBusinessPhone($value) {
    $this->setParam('businessPhone', $value);
    return $this;
  }

  /**
   * Set the mobilePhone.
   *
   * @param string $value
   *   The mobilePhone to set to.
   *
   * @return $this
   */
  public function setMobilePhone($value) {
    $this->setParam('mobilePhone', $value);
    return $this;
  }

  /**
   * Set the homePhone.
   *
   * @param string $value
   *   The homePhone to set to.
   *
   * @return $this
   */
  public function setHomePhone($value) {
    $this->setParam('homePhone', $value);
    return $this;
  }

  /**
   * Set the organisationID.
   *
   * @param string $value
   *   The organisationID to set to.
   *
   * @return $this
   */
  public function setOrganisationId($value) {
    $this->setParam('organisationID', $value);
    return $this;
  }

  /**
   * Set the gender.
   *
   * @param string $value
   *   The gender to set to.
   *
   * @return $this
   */
  public function setGender($value) {
    $this->setParam('gender', $value);
    return $this;
  }

  /**
   * Set the marketingMaterials.
   *
   * @param string $value
   *   The marketingMaterials to set to.
   *
   * @return $this
   */
  public function setMarketingMaterials($value) {
    $this->setParam('marketingMaterials', $value);
    return $this;
  }

  /**
   * Set the address1.
   *
   * @param string $value
   *   The address1 to set to.
   *
   * @return $this
   */
  public function setAddress1($value) {
    $this->setParam('address1', $value);
    return $this;
  }

  /**
   * Set the address2.
   *
   * @param string $value
   *   The address2 to set to.
   *
   * @return $this
   */
  public function setAddress2($value) {
    $this->setParam('address2', $value);
    return $this;
  }

  /**
   * Set the address3.
   *
   * @param string $value
   *   The address3 to set to.
   *
   * @return $this
   */
  public function setAddress3($value) {
    $this->setParam('address3', $value);
    return $this;
  }

  /**
   * Set the city.
   *
   * @param string $value
   *   The city to set to.
   *
   * @return $this
   */
  public function setCity($value) {
    $this->setParam('city', $value);
    return $this;
  }

  /**
   * Set the stateProvince.
   *
   * @param string $value
   *   The stateProvince to set to.
   *
   * @return $this
   */
  public function setStateProvince($value) {
    $this->setParam('stateProvince', $value);
    return $this;
  }

  /**
   * Set the postCode.
   *
   * @param string $value
   *   The postCode to set to.
   *
   * @return $this
   */
  public function setPostCode($value) {
    $this->setParam('postCode', $value);
    return $this;
  }

  /**
   * Set the country.
   *
   * @param string $value
   *   The country to set to.
   *
   * @return $this
   */
  public function setCountry($value) {
    $this->setParam('country', $value);
    return $this;
  }

  /**
   * Set the address1.
   *
   * @param string $value
   *   The address1 to set to.
   *
   * @return $this
   */
  public function set2ndAddress1($value) {
    $this->setParam('snd_Address1', $value);
    return $this;
  }

  /**
   * Set the address2.
   *
   * @param string $value
   *   The address2 to set to.
   *
   * @return $this
   */
  public function set2ndAddress2($value) {
    $this->setParam('snd_Address2', $value);
    return $this;
  }

  /**
   * Set the address3.
   *
   * @param string $value
   *   The address3 to set to.
   *
   * @return $this
   */
  public function set2ndAddress3($value) {
    $this->setParam('snd_Address3', $value);
    return $this;
  }

  /**
   * Set the city.
   *
   * @param string $value
   *   The city to set to.
   *
   * @return $this
   */
  public function set2ndCity($value) {
    $this->setParam('snd_City', $value);
    return $this;
  }

  /**
   * Set the stateProvince.
   *
   * @param string $value
   *   The stateProvince to set to.
   *
   * @return $this
   */
  public function set2ndStateProvince($value) {
    $this->setParam('snd_StateProvince', $value);
    return $this;
  }

  /**
   * Set the postCode.
   *
   * @param string $value
   *   The postCode to set to.
   *
   * @return $this
   */
  public function set2ndPostCode($value) {
    $this->setParam('snd_PostCode', $value);
    return $this;
  }

  /**
   * Set the country.
   *
   * @param string $value
   *   The country to set to.
   *
   * @return $this
   */
  public function set2ndCountry($value) {
    $this->setParam('snd_Country', $value);
    return $this;
  }

  /**
   * Set the hearAboutRMetS.
   *
   * @param string $value
   *   The hearAboutRMetS to set to.
   *
   * @return $this
   */
  public function setHearAboutRMetS($value) {
    $this->setParam('hearAboutRMetS', $value);
    return $this;
  }

  /**
   * Set the GraduationDate.
   *
   * @param string $value
   *   The GraduationDate to set to.
   *
   * @return $this
   */
  public function setGraduationDate($value) {
    $this->setParam('graduationDate', $value);
    return $this;
  }

  /**
   * @param $interestId
   */
  public function addInterest($interestId) {
    $interests = $this->getParam('subEntities');
    $item = new \stdClass();
    $item->InterestID = $interestId;
    $interests[] = $item;
    $this->setParam('subEntities', $interests);
  }

  /**
   * Set the SubEntities.
   *
   * These is an array of stdClass objects with InterestId as key and the
   * interest value.
   *
   * @param array $value
   *   The SubEntities to set to.
   *
   * @return $this
   */
  public function setSubEntities(array $value) {
    $this->setParam('subEntities', $value);
    return $this;
  }

  /**
   * Set the occupation.
   *
   * @param string $value
   *   The occupation to set to.
   *
   * @return $this
   */
  public function setOccupation($value) {
    $this->setParam('occupation', $value);
    return $this;
  }

  /**
   * Set the otherOccupation.
   *
   * @param string $value
   *   The otherOccupation to set to.
   *
   * @return $this
   */
  public function setOtherOccupation($value) {
    $this->setParam('otherOccupation', $value);
    return $this;
  }

  /**
   * Set the giftAid.
   *
   * @param string $value
   *   The giftAid to set to.
   *
   * @return $this
   */
  public function setGiftAid($value) {
    $this->setParam('giftAid', $value);
    return $this;
  }

  /**
   * Set the organisation name.
   *
   * @param string $value
   *   The organisation name to set to.
   *
   * @return $this
   */
  public function setOrganisationName($value) {
    $this->setParam('organisationName', $value);
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
