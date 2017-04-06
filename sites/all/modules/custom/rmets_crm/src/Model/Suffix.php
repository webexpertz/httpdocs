<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_event
class Suffix extends AbstractModel {

  protected $suffixID;
  protected $name;

  /**
   * @return mixed
   */
  public function getSuffixId() {
    return $this->suffixID;
  }

  /**
   * @param mixed $eventId
   */
  public function setSuffixId($eventId) {
    $this->suffixID = $eventId;
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