<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_event
class EventSession extends AbstractModel {

  protected $sessionID;
  protected $name;
  protected $room;
  protected $capacity;
  protected $startDate;
  protected $endDate;
  protected $sessionChair;

  /**
   * @return mixed
   */
  public function getSessionId() {
    return $this->sessionID;
  }

  /**
   * @param mixed $eventId
   */
  public function setSessionId($sessionId) {
    $this->sessionID = $sessionId;
  }

  /**
   * @return mixed
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @param mixed $title
   */
  public function setName($name) {
    $this->name = $name;
  }

  /**
   * @return mixed
   */
  public function getRoom() {
    return $this->room;
  }

  /**
   * @param mixed $title
   */
  public function setRoom($room) {
    $this->room = $room;
  }

  /**
   * @return mixed
   */
  public function getStartDate() {
    return $this->startDate;
  }

  /**
   * @return int
   */
  public function getStartDateAsTimestamp() {
    return \DateTime::createFromFormat('!d/m/Y H:i:s', $this->startDate)->getTimestamp();
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
   * @return int
   */
  public function getEndDateAsTimestamp() {
    return \DateTime::createFromFormat('!d/m/Y H:i:s', $this->endDate)->getTimestamp();
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
  public function getCapacity() {
    return $this->capacity;
  }

  /**
   * @param mixed $endDate
   */
  public function setCapacity($capacity) {
    $this->capacity = $capacity;
  }

  /**
   * @return mixed
   */
  public function getSessionChair() {
    return $this->sessionChair;
  }

  /**
   * @param mixed $sessionChair
   */
  public function setSessionChair($sessionChair) {
    $this->sessionChair = $sessionChair;
  }

}