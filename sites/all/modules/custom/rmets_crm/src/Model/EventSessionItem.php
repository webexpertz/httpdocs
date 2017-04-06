<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_eventsessionitem
class EventSessionItem extends AbstractModel {

  protected $sessionItemID;
  protected $sessionID;
  protected $eventID;
  protected $abstractID;
  protected $name;
  protected $startDateTime;
  protected $number;
  protected $speakerName;
  protected $contactID;

  /**
   * @return mixed
   */
  public function getSessionItemID() {
    return $this->sessionItemID;
  }

  /**
   * @param mixed $sessionItemID
   */
  public function setSessionItemID($sessionItemID) {
    $this->sessionItemID = $sessionItemID;
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
  public function getStartDateTime() {
    return $this->startDateTime;
  }

  /**
   * @param mixed $startDateTime
   */
  public function setStartDateTime($startDateTime) {
    $this->startDateTime = $startDateTime;
  }

  /**
   * @return int
   */
  public function getStartDateTimeAsTimestamp() {
    return \DateTime::createFromFormat('!d/m/Y H:i:s', $this->startDateTime)->getTimestamp();
  }

  /**
   * @return mixed
   */
  public function getNumber() {
    return $this->number;
  }

  /**
   * @param mixed $number
   */
  public function setNumber($number) {
    $this->number = $number;
  }

  /**
   * @return mixed
   */
  public function getSpeakerName() {
    return $this->speakerName;
  }

  /**
   * @param mixed $speakerName
   */
  public function setSpeakerName($speakerName) {
    $this->speakerName = $speakerName;
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

}