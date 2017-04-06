<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_subscription (???)
class AccreditatedContact extends AbstractModel {

  protected $accreditation;
  protected $accreditationID;
  protected $contactID;
  protected $title;
  protected $forename;
  protected $initials;
  protected $salutation;
  protected $surname;
  protected $eMail;
  protected $membershipNumber;
  protected $rMETSAccDate;
  protected $cMETSAccDate;

  /**
   * @return mixed
   */
  public function getAccreditation() {
    return $this->accreditation;
  }

  /**
   * @param mixed $accreditation
   */
  public function setAccreditation($accreditation) {
    $this->accreditation = $accreditation;
  }

  /**
   * @return mixed
   */
  public function getAccreditationID() {
    return $this->accreditationID;
  }

  /**
   * @param mixed $accreditationID
   */
  public function setAccreditationID($accreditationID) {
    $this->accreditationID = $accreditationID;
  }

  /**
   * @return mixed
   */
  public function getContactId() {
    return $this->contactID;
  }

  /**
   * @param mixed $contactId
   */
  public function setContactId($contactId) {
    $this->contactID = $contactId;
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
  public function getForename() {
    return $this->forename;
  }

  /**
   * @param mixed $forename
   */
  public function setForename($forename) {
    $this->forename = $forename;
  }

  /**
   * @return mixed
   */
  public function getInitials() {
    return $this->initials;
  }

  /**
   * @param mixed $initials
   */
  public function setInitials($initials) {
    $this->initials = $initials;
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
   * @return string
   */
  public function getSuffix() {
    $salutation = $this->getSalutation();
    $surname = $this->getSurname();
    return trim((string)substr($salutation, strpos($salutation, $surname) + strlen($surname)));
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
  public function getEmail() {
    return $this->eMail;
  }

  /**
   * @param mixed $email
   */
  public function setEmail($email) {
    $this->eMail = $email;
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
  public function getRmetsAccDate() {
    return $this->rMETSAccDate;
  }

  /**
   * @param mixed $rmetsAccDate
   */
  public function setRmetsAccDate($rmetsAccDate) {
    $this->rMETSAccDate = $rmetsAccDate;
  }

  /**
   * @return mixed
   */
  public function getCmetsAccDate() {
    return $this->cMETSAccDate;
  }

  /**
   * @param mixed $cmetsAccDate
   */
  public function setCmetsAccDate($cmetsAccDate) {
    $this->cMETSAccDate = $cmetsAccDate;
  }

  /**
   * @return mixed
   */
  public function getAwardDateAsTimestamp() {
    $awardDate = (strstr(drupal_strtolower($this->getAccreditation()), 'cmet')) ?
      $this->getCmetsAccDate() : $this->getRmetsAccDate();
    if (empty($awardDate)) {
      watchdog('award_profiles', 'Accreditation (@accreditation_type) has no date set for membership number: @membership_number', array('@accreditation_type' => $this->getAccreditation(), '@membership_number' => $this->getMembershipNumber()), WATCHDOG_ERROR);
      return NULL;
    }

    list($date, $time) = explode(' ', $awardDate);
    list($day, $month, $year) = explode('/', $date);
    list($hour, $min, $sec) = explode(':', $time);
    return gmmktime($hour, $min, $sec, $month, $day, $year);
  }

}