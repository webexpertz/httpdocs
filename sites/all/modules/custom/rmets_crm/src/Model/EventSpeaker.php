<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_eventspeaker
class EventSpeaker extends AbstractModel {

  protected $contactID;
  protected $biography;
  protected $abstractID;
  protected $eventID;
  protected $sessionID;
  protected $title;
  protected $forenames;
  protected $surname;
  protected $dateOfBirth;
  protected $membershipNumber;
  protected $email;
  protected $mobilePhone;
  protected $affiliationID;
  protected $salutation;
  protected $affiliationName;

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
  public function getBiography() {
    return $this->biography;
  }

  /**
   * @param mixed $biography
   */
  public function setBiography($biography) {
    $this->biography = $biography;
  }

  /**
   * @return mixed
   */
  public function getAbstractID() {
    return $this->abstractID;
  }

  /**
   * @param mixed $abstractID
   */
  public function setAbstractID($abstractID) {
    $this->abstractID = $abstractID;
  }

  /**
   * @return mixed
   */
  public function getEventID() {
    return $this->eventID;
  }

  /**
   * @param mixed $eventID
   */
  public function setEventID($eventID) {
    $this->eventID = $eventID;
  }

  /**
   * @return mixed
   */
  public function getSessionID() {
    return $this->sessionID;
  }

  /**
   * @param mixed $sessionID
   */
  public function setSessionID($sessionID) {
    $this->sessionID = $sessionID;
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
    return $this->email;
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
  public function getAffiliationID() {
    return $this->affiliationID;
  }

  /**
   * @param mixed $affiliationID
   */
  public function setAffiliationID($affiliationID) {
    $this->affiliationID = $affiliationID;
  }

  /**
   * @return mixed
   */
  public function getSalutation() {
    return str_replace(array(chr(194), chr(32), chr(160)), ' ', $this->salutation);
  }

  /**
   * @param mixed $salutation
   */
  public function setSalutation($salutation) {
    $this->salutation = $salutation;
  }

  /**
   * @return mixed
   */
  public function getAffiliationName() {
    return $this->affiliationName;
  }

  /**
   * @param mixed $affiliationName
   */
  public function setAffiliationName($affiliationName) {
    $this->affiliationName = $affiliationName;
  }

}