<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_awardcategory
class AwardCategory extends AbstractModel {

  protected $awardID;
  protected $name;

  /**
   * @return mixed
   */
  public function getAwardID() {
    return $this->awardID;
  }

  /**
   * @param mixed $awardID
   */
  public function setAwardID($awardID) {
    $this->awardID = $awardID;
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