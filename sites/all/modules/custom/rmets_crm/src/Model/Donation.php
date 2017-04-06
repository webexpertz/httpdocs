<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_donation
class Donation extends AbstractModel {

  protected $donationID;
  protected $name;
  protected $amount;
  protected $date;

  /**
   * @return mixed
   */
  public function getDonationID() {
    return $this->donationID;
  }

  /**
   * @param mixed $donationID
   */
  public function setDonationID($donationID) {
    $this->donationID = $donationID;
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
  public function getAmount() {
    return $this->amount;
  }

  /**
   * @param mixed $amount
   */
  public function setAmount($amount) {
    $this->amount = $amount;
  }

  /**
   * @return mixed
   */
  public function getDate() {
    return $this->date;
  }

  /**
   * @param mixed $date
   */
  public function setDate($date) {
    $this->date = $date;
  }

}