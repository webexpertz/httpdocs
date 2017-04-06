<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_event
class EventRegistrationFees extends AbstractModel {

  protected $feeID;
  protected $name;
  protected $rate;
  protected $description;
  protected $membersOnly;

  /**
   * @return mixed
   */
  public function getFeeId() {
    return $this->feeID;
  }

  /**
   * @param mixed $eventId
   */
  public function setFeeId($feeID) {
    $this->feeID = $feeID;
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
  public function getRate() {
    return $this->rate;
  }

  /**
   * @param mixed $title
   */
  public function setRate($rate) {
    $this->rate = $rate;
  }

  /**
   * @return mixed
   */
  public function getMembersOnly() {
    return $this->membersOnly;
  }

  /**
   * @param mixed $membersOnly
   */
  public function setMembersOnly($membersOnly) {
    $this->membersOnly = $membersOnly;
  }

  /**
   * @return mixed
   */
  public function getDescription() {
    return $this->description;
  }

  /**
   * @param mixed $endDate
   */
  public function setDescription($description) {
    $this->description = $description;
  }


}