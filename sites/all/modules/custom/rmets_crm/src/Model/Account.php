<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:account
class Account extends AbstractModel {

  protected $organisationID;
  protected $name;
  protected $address1;
  protected $address2;
  protected $address3;
  protected $city;
  protected $stateProvince;
  protected $postCode;
  protected $country;

  /**
   * @return mixed
   */
  public function getOrganisationID() {
    return $this->organisationID;
  }

  /**
   * @param mixed $organisationID
   */
  public function setOrganisationID($organisationID) {
    $this->organisationID = $organisationID;
  }

  /**
   * @return mixed
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @param mixed $name
   */
  public function setName($name) {
    $this->name = $name;
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

}