<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_accreditationitem
class AccreditationItem extends AbstractModel {

  protected $accreditationItemID;
  protected $name;
  protected $amount;
  protected $joiningFee;
  protected $vATCode;
  protected $vATRate;
  protected $joinOnline;
  protected $packageID;
  protected $accreditationID;

  /**
   * @return mixed
   */
  public function getAccreditationItemID() {
    return $this->accreditationItemID;
  }

  /**
   * @param mixed $accreditationItemID
   */
  public function setAccreditationItemID($accreditationItemID) {
    $this->accreditationItemID = $accreditationItemID;
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
  public function getJoiningFee() {
    return $this->joiningFee;
  }

  /**
   * @param mixed $joiningFee
   */
  public function setJoiningFee($joiningFee) {
    $this->joiningFee = $joiningFee;
  }

  /**
   * @return mixed
   */
  public function getVatCode() {
    return $this->vATCode;
  }

  /**
   * @param mixed $vatCode
   */
  public function setVatCode($vatCode) {
    $this->vATCode = $vatCode;
  }

  /**
   * @return mixed
   */
  public function getVatRate() {
    return $this->vATRate;
  }

  /**
   * @param mixed $vatRate
   */
  public function setVatRate($vatRate) {
    $this->vATRate = $vatRate;
  }

  /**
   * @return mixed
   */
  public function getJoinOnline() {
    return $this->joinOnline;
  }

  /**
   * @param mixed $joinOnline
   */
  public function setJoinOnline($joinOnline) {
    $this->joinOnline = $joinOnline;
  }

  /**
   * @return bool
   */
  public function isJoinOnline() {
    return strtolower($this->joinOnline) !== 'false';
  }

  /**
   * @return mixed
   */
  public function getPackageId() {
    return $this->packageID;
  }

  /**
   * @param mixed $packageId
   */
  public function setPackageId($packageId) {
    $this->packageID = $packageId;
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

}