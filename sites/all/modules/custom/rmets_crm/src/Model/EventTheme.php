<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_event
class EventTheme extends AbstractModel {

  protected $eventId;
  protected $name;
  protected $themeID;

  /**
   * @return mixed
   */
  public function getEventId() {
    return $this->eventId;
  }

  /**
   * @param mixed $eventId
   */
  public function setEventId($eventId) {
    $this->eventID = $eventId;
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
  public function getThemeId() {
    return $this->themeID;
  }

  /**
   * @param mixed $themeID
   */
  public function setThemeId($themeId) {
    $this->themeID = $themeId;
  }

}