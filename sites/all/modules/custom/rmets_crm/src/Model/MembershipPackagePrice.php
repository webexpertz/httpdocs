<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_membershippackageprice
class MembershipPackagePrice extends AbstractModel {

  protected $membershipPackagePriceID;
  protected $name;
  protected $amount;
  protected $vATCode;
  protected $vATRate;
  protected $validTo;
  protected $validFrom;
  protected $packageId;
  protected $class;
  protected $grade;
  protected $giftMembership;

  function __construct(array $item) {
    parent::__construct($item);
  }

  /**
   * @return mixed
   */
  public function getMembershipPackagePriceID() {
    return $this->membershipPackagePriceID;
  }

  /**
   * @param mixed $membershipPackagePriceID
   */
  public function setMembershipPackagePriceID($membershipPackagePriceID) {
    $this->membershipPackagePriceID = $membershipPackagePriceID;
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
   * @return mixed
   */
  public function getAmountFormatted() {
    return number_format($this->amount, 2);
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
  public function getVatCode() {
    return $this->vatCode;
  }

  /**
   * @param mixed $vatCode
   */
  public function setVatCode($vatCode) {
    $this->vatCode = $vatCode;
  }

  /**
   * @return mixed
   */
  public function getVatRate() {
    return $this->vatRate;
  }

  /**
   * @param mixed $vatRate
   */
  public function setVatRate($vatRate) {
    $this->vatRate = $vatRate;
  }

  /**
   * @return mixed
   */
  public function getValidTo() {
    return $this->validTo;
  }

  /**
   * @param mixed $validTo
   */
  public function setValidTo($validTo) {
    $this->validTo = $validTo;
  }

  /**
   * @return mixed
   */
  public function getValidFrom() {
    return $this->validFrom;
  }

  /**
   * @param mixed $validFrom
   */
  public function setValidFrom($validFrom) {
    $this->validFrom = $validFrom;
  }

  /**
   * @return mixed
   */
  public function getPackageId() {
    return $this->packageId;
  }

  /**
   * @param mixed $packageId
   */
  public function setPackageId($packageId) {
    $this->packageId = $packageId;
  }

  /**
   * @return mixed
   */
  public function getClass() {
    return $this->class;
  }

  /**
   * @param mixed $class
   */
  public function setClass($class) {
    $this->class = $class;
  }

  /**
   * @return mixed
   */
  public function getGrade() {
    return $this->grade;
  }

  /**
   * @param mixed $grade
   */
  public function setGrade($grade) {
    $this->grade = $grade;
  }

  /**
   * @return mixed
   */
  public function getGiftMembership() {
    return $this->giftMembership;
  }

  /**
   * @param mixed $giftMembership
   */
  public function setGiftMembership($giftMembership) {
    $this->giftMembership = $giftMembership;
  }

}