<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class CreateAbstractRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function __construct() {
    $this->setSubEntities(array());
  }

  public function getRequiredParams() {
    return array('guid', 'eventID', 'subEntities');
  }

  public function getOptionalParams() {
    return array('title', 'mainAuthorID', 'summary', 'theme', 'affiliationID', 'type');
  }

  /**
   * Set the guid for the request.
   *
   * @param string $guid
   *   The guid value to set.
   *
   * @return $this
   */
  public function setGuid($guid) {
    $this->setParam('guid', $guid);
    return $this;
  }

  /**
   * Set the type.
   *
   * @param string $type
   *   The type to set to.
   *
   * @return $this
   */
  public function setType($type) {
    $this->setParam('type', $type);
    return $this;
  }


  /**
   * Set the event id.
   *
   * @param string $eventId
   *   The event id to set to.
   *
   * @return $this
   */
  public function setEventId($eventId) {
    $this->setParam('eventID', $eventId);
    return $this;
  }

  /**
   * Set the main Author id.
   *
   * @param string $mainAuthorID
   *   The main Author to set to.
   *
   * @return $this
   */
  public function setMainAuthorId($mainAuthorID) {
    $this->setParam('mainAuthorID', $mainAuthorID);
    return $this;
  }

  /**
   * Set the title.
   *
   * @param string $title
   *   The title to set to.
   *
   * @return $this
   */
  public function setTitle($title) {
    $this->setParam('title', $title);
    return $this;
  }

  /**
   * Set the summary from.
   *
   * @param string $summary
   *   The summary.
   *
   * @return $this
   */
  public function setSummary($summary) {
    $this->setParam('summary', $summary);
    return $this;
  }

  /**
   * Set the theme.
   *
   * @param string $theme
   *   The theme to set to.
   *
   * @return $this
   */
  public function setTheme($theme) {
    $this->setParam('theme', $theme);
    return $this;
  }

  /**
   * Set the affiliation id.
   *
   * @param int $affiliationID
   *   The affiliation id to set to.
   *
   * @return $this
   */
  public function setAffiliationId($affiliationID) {
    $this->setParam('affiliationID', $affiliationID);
    return $this;
  }

  /**
   * @param $contactID
   */
  public function addContactId($contactID) {
    $journals = $this->getParam('subEntities');
    $item = new \stdClass();
    $item->ContactID = $contactID;
    $journals[] = $item;
    $this->setParam('subEntities', $journals);
  }

  /**
   * Set the sub entities.
   *
   * @param array $subEntities
   *   The subEntities to set to.
   *
   * @return $this
   */
  public function setSubEntities(array $subEntities) {
    $this->setParam('subEntities', $subEntities);
    return $this;
  }

  /**
   * {inheritdoc}
   * @return bool
   */
  public function isCacheable() {
    return FALSE;
  }
}
