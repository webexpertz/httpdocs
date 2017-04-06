<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_journalitem
class JournalItem extends AbstractModel {

  protected $journalItemID;
  protected $name;
  protected $vATCode;
  protected $vATRate;
  protected $journal;
  protected $defaulted;
  protected $amount;
  protected $joinOnline;
  protected $renewOnline;
  protected $publications;
  protected $printed;
  protected $onlineISSN;
  protected $iSSN;
  protected $packageID;

  /**
   * @return mixed
   */
  public function getJournalItemID() {
    return $this->journalItemID;
  }

  /**
   * @param mixed $journalItemID
   */
  public function setJournalItemID($journalItemID) {
    $this->journalItemID = $journalItemID;
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
  public function getJournal() {
    return $this->journal;
  }

  /**
   * @param mixed $journal
   */
  public function setJournal($journal) {
    $this->journal = $journal;
  }

  /**
   * @return mixed
   */
  public function getDefaulted() {
    return $this->defaulted;
  }

  /**
   * @param mixed $defaulted
   */
  public function setDefaulted($defaulted) {
    $this->defaulted = $defaulted;
  }

  /**
   * @return mixed
   */
  public function getAmount() {
    if (empty($this->amount)) {
      return 0;
    }
    return $this->amount;
  }

  /**
   * @return mixed
   */
  public function getAmountFormatted() {
    return number_format($this->getAmount(), 2);
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
   * @return mixed
   */
  public function getRenewOnline() {
    return $this->renewOnline;
  }

  /**
   * @param mixed $renewOnline
   */
  public function setRenewOnline($renewOnline) {
    $this->renewOnline = $renewOnline;
  }

  /**
   * @return mixed
   */
  public function getPublications() {
    return $this->publications;
  }

  /**
   * @param mixed $publications
   */
  public function setPublications($publications) {
    $this->publications = $publications;
  }

  /**
   * @return mixed
   */
  public function getPrinted() {
    return $this->printed;
  }

  /**
   * @param mixed $printed
   */
  public function setPrinted($printed) {
    $this->printed = $printed;
  }

  /**
   * @return mixed
   */
  public function getOnlineIssn() {
    return $this->onlineISSN;
  }

  /**
   * @param mixed $onlineIssn
   */
  public function setOnlineIssn($onlineIssn) {
    $this->onlineISSN = $onlineIssn;
  }

  /**
   * @return mixed
   */
  public function getIssn() {
    return $this->iSSN;
  }

  /**
   * @param mixed $issn
   */
  public function setIssn($issn) {
    $this->iSSN = $issn;
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

}