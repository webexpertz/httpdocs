<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;


class Interest extends AbstractModel {

  protected $interestID;
  protected $name;

  function __construct(array $item) {
    parent::__construct($item);
  }

  /**
   * @return mixed
   */
  public function getInterestID() {
    return $this->interestID;
  }

  /**
   * @param mixed $interestID
   */
  public function setInterestID($interestID) {
    $this->interestID = $interestID;
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

}