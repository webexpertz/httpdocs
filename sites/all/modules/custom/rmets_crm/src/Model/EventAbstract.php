<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_abstract
class EventAbstract extends AbstractModel {

  protected $abstractID;
  protected $title;
  protected $theme;
  protected $eventID;
  protected $summary;
  protected $affiliationID;
  protected $mainAuthorID;
  protected $number;
  protected $declinedReason;
  protected $status;
  protected $type;
  protected $sessionID;

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
  public function getMainAuthorID() {
    return $this->mainAuthorID;
  }

  /**
   * @param mixed $mainAuthorID
   */
  public function setMainAuthorID($mainAuthorID) {
    $this->mainAuthorID = $mainAuthorID;
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
  public function getDeclinedReason() {
    return $this->declinedReason;
  }

  /**
   * @param mixed $declinedReason
   */
  public function setDeclinedReason($declinedReason) {
    $this->declinedReason = $declinedReason;
  }

  /**
   * @return mixed
   */
  public function getStatus() {
    return $this->status;
  }

  /**
   * @param mixed $status
   */
  public function setStatus($status) {
    $this->status = $status;
  }

  /**
   * @return mixed
   */
  public function getType() {
    return $this->type;
  }

  /**
   * @param mixed $type
   */
  public function setType($type) {
    $this->type = $type;
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

}