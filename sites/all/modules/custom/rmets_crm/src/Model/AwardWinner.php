<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_awardwinner
class AwardWinner extends AbstractModel {

  protected $award;
  protected $awardID;
  protected $contactID;
  protected $title;
  protected $forenames;
  protected $initials;
  protected $salutation;
  protected $surname;
  protected $eMail;
  protected $membershipNumber;
  protected $citation;
  protected $awardDate;

  /**
   * @return mixed
   */
  public function getAward() {
    return $this->award;
  }

  /**
   * @param mixed $award
   */
  public function setAward($award) {
    $this->award = $award;
  }

  /**
   * @return mixed
   */
  public function getAwardID() {
    return $this->awardID;
  }

  /**
   * @param mixed $awardID
   */
  public function setAwardID($awardID) {
    $this->awardID = $awardID;
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
    return $this->forenames;
  }

  /**
   * @param mixed $forename
   */
  public function setForename($forename) {
    $this->forenames = $forename;
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
  public function getCitation() {
    return $this->citation;
  }

  /**
   * @param mixed $citation
   */
  public function setCitation($citation) {
    $this->citation = $citation;
  }

  /**
   * @return mixed
   */
  public function getAwardDate() {
    return $this->awardDate;
  }

  /**
   * @param mixed $awardDate
   */
  public function setAwardDate($awardDate) {
    $this->awardDate = $awardDate;
  }

  /**
   * @return int
   */
  public function getAwardDateAsTimestamp() {
    $awardDate = $this->awardDate;
    if (empty($awardDate)) {
      watchdog('award_profiles', 'Award (@award_type) has no date set for membership number: @membership_number', array('@award_type' => $this->getAward(), '@membership_number' => $this->getMembershipNumber()), WATCHDOG_ERROR);
      return NULL;
    }

    list($date, $time) = explode(' ', $awardDate);
    list($day, $month, $year) = explode('/', $date);
    list($hour, $min, $sec) = explode(':', $time);
    return gmmktime($hour, $min, $sec, $month, $day, $year);
  }

}