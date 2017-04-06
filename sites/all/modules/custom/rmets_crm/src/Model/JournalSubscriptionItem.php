<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_journalsubscriptionitem
class JournalSubscriptionItem extends AbstractModel {

  protected $subscriptionJournalID;
  protected $name;
  protected $amount;
  protected $vATCode;
  protected $vATRate;
  protected $journalID;
  protected $journalItemID;
  protected $subscriptionID;

  /**
   * @return mixed
   */
  public function getSubscriptionJournalId() {
    return $this->subscriptionJournalID;
  }

  /**
   * @param mixed $subscriptionJournalId
   */
  public function setSubscriptionJournalId($subscriptionJournalId) {
    $this->subscriptionJournalID = $subscriptionJournalId;
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
  public function getJournalId() {
    return $this->journalID;
  }

  /**
   * @param mixed $journalId
   */
  public function setJournalId($journalId) {
    $this->journalID = $journalId;
  }

  /**
   * @return mixed
   */
  public function getJournalItemId() {
    return $this->journalItemID;
  }

  /**
   * @param mixed $journalItemId
   */
  public function setJournalItemId($journalItemId) {
    $this->journalItemID = $journalItemId;
  }

  /**
   * @return mixed
   */
  public function getSubscriptionId() {
    return $this->subscriptionID;
  }

  /**
   * @param mixed $subscriptionId
   */
  public function setSubscriptionId($subscriptionId) {
    $this->subscriptionID = $subscriptionId;
  }

}