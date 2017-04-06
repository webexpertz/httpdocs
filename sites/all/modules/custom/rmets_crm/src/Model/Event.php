<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_event
class Event extends AbstractModel {

  protected $eventID;
  protected $title;
  protected $theme;
  protected $startDate;
  protected $endDate;
  protected $summary;
  protected $availableSeats;
  protected $rMetSContactEmail;
  protected $venueName;
  protected $venueAddress;
  protected $eventType;
  protected $groupName;
  protected $groupType;

  /**
   * @return mixed
   */
  public function getEventId() {
    return $this->eventID;
  }

  /**
   * @param mixed $eventId
   */
  public function setEventId($eventId) {
    $this->eventID = $eventId;
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
  public function getTheme() {
    return $this->theme;
  }

  /**
   * @param mixed $theme
   */
  public function setTheme($theme) {
    $this->theme = $theme;
  }

  /**
   * @return mixed
   */
  public function getStartDate() {
    return $this->startDate;
  }

  /**
   * @param mixed $startDate
   */
  public function setStartDate($startDate) {
    $this->startDate = $startDate;
  }

  /**
   * @return mixed
   */
  public function getEndDate() {
    return $this->endDate;
  }

  /**
   * @param mixed $endDate
   */
  public function setEndDate($endDate) {
    $this->endDate = $endDate;
  }

  /**
   * @return mixed
   */
  public function getSummary() {
    return $this->summary;
  }

  /**
   * @param mixed $summary
   */
  public function setSummary($summary) {
    $this->summary = $summary;
  }

  /**
   * @return mixed
   */
  public function getAvailableSeats() {
    return $this->availableSeats;
  }

  /**
   * @param mixed $availableSeats
   */
  public function setAvailableSeats($availableSeats) {
    $this->availableSeats = $availableSeats;
  }

  /**
   * @return mixed
   */
  public function getRmetsContactEmail() {
    return $this->rMetSContactEmail;
  }

  /**
   * @param mixed $rmetsContactEmail
   */
  public function setRmetsContactEmail($rmetsContactEmail) {
    $this->rMetSContactEmail = $rmetsContactEmail;
  }

  /**
   * @return mixed
   */
  public function getVenueName() {
    return $this->venueName;
  }

  /**
   * @param mixed $venueName
   */
  public function setVenueName($venueName) {
    $this->venueName = $venueName;
  }

  /**
   * @return mixed
   */
  public function getVenueAddress() {
    return $this->venueAddress;
  }

  /**
   * @param mixed $venueAddress
   */
  public function setVenueAddress($venueAddress) {
    $this->venueAddress = $venueAddress;
  }

  /**
   * @return mixed
   */
  public function getEventType() {
    return $this->eventType;
  }

  /**
   * @param mixed $eventType
   */
  public function setEventType($eventType) {
    $this->eventType = $eventType;
  }

  /**
   * @return mixed
   */
  public function getGroupType() {
    return $this->groupType;
  }

  /**
   * @param mixed $groupType
   */
  public function setGroupType($groupType) {
    $this->groupType = $groupType;
  }

  /**
   * @return mixed
   */
  public function getGroupName() {
    return $this->groupName;
  }

  /**
   * @param mixed $groupType
   */
  public function setGroupName($groupName) {
    $this->groupType = $groupName;
  }

}