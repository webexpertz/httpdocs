<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_paymentschedule
class PaymentSchedule extends AbstractModel {

  protected $paymentID;
  protected $paymentFrom;
  protected $amount;
  protected $paymentMethod;
  protected $paymentStatus;
  protected $contactID;
  protected $subscriptionID;
  protected $dueDate;

  function __construct(array $item) {
    parent::__construct($item);
  }

  /**
   * @return mixed
   */
  public function getPaymentID() {
    return $this->paymentID;
  }

  /**
   * @param mixed $paymentID
   */
  public function setPaymentID($paymentID) {
    $this->paymentID = $paymentID;
  }

  /**
   * @return mixed
   */
  public function getPaymentFrom() {
    return $this->paymentFrom;
  }

  /**
   * @param mixed $paymentFrom
   */
  public function setPaymentFrom($paymentFrom) {
    $this->paymentFrom = $paymentFrom;
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
  public function getPaymentMethod() {
    return $this->paymentMethod;
  }

  /**
   * @param mixed $paymentMethod
   */
  public function setPaymentMethod($paymentMethod) {
    $this->paymentMethod = $paymentMethod;
  }

  /**
   * @return mixed
   */
  public function getPaymentStatus() {
    return $this->paymentStatus;
  }

  /**
   * @param mixed $paymentStatus
   */
  public function setPaymentStatus($paymentStatus) {
    $this->paymentStatus = $paymentStatus;
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

  /**
   * @return mixed
   */
  public function getSubscriptionID() {
    return $this->subscriptionID;
  }

  /**
   * @param mixed $subscriptionID
   */
  public function setSubscriptionID($subscriptionID) {
    $this->subscriptionID = $subscriptionID;
  }

  /**
   * @return mixed
   */
  public function getDueDate() {
    return $this->dueDate;
  }

  /**
   * @return mixed
   */
  public function getDueDateFormatted() {
    list($date, $time) = explode(' ', $this->getDueDate());
    list($day, $month, $year) = explode('/', $date);
    return sprintf("%s/%s/%s", $day, $month, $year);
  }

  /**
   * @param mixed $dueDate
   */
  public function setDueDate($dueDate) {
    $this->dueDate = $dueDate;
  }

}