<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

class FrmetsContact extends AbstractModel {

  protected $fRMetS;
  protected $contactID;
  protected $title;
  protected $forename;
  protected $initials;
  protected $salutation;
  protected $surname;
  protected $eMail;
  protected $membershipNumber;
  protected $electionDate;

  /**
   * @return mixed
   */
  public function getFRMetS() {
    return $this->fRMetS;
  }

  /**
   * @param mixed $fRMetS
   */
  public function setFRMetS($fRMetS) {
    $this->fRMetS = $fRMetS;
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
  public function getEMail() {
    return $this->eMail;
  }

  /**
   * @param mixed $eMail
   */
  public function setEMail($eMail) {
    $this->eMail = $eMail;
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
  public function getElectionDate() {
    return $this->electionDate;
  }

  /**
   * @param mixed $electionDate
   */
  public function setElectionDate($electionDate) {
    $this->electionDate = $electionDate;
  }

  /**
   * @return int
   */
  public function getAwardDateAsTimestamp() {
    $awardDate = $this->electionDate;
    if (empty($awardDate)) {
      watchdog('award_profiles', 'Fellow has no date set for membership number: @membership_number', array('@membership_number' => $this->getMembershipNumber()), WATCHDOG_ERROR);
      return NULL;
    }

    list($date, $time) = explode(' ', $awardDate);
    list($day, $month, $year) = explode('/', $date);
    list($hour, $min, $sec) = explode(':', $time);
    return gmmktime($hour, $min, $sec, $month, $day, $year);
  }

}