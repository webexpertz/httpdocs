<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_accreditation
class Accreditation extends AbstractModel {

  protected $accreditationID;
  protected $name;

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