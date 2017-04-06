<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class AddMemberSubscriptionJournalsRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function __construct() {
    $this->setSubEntities(array());
  }

  public function getRequiredParams() {
    return array('guid', 'subscriptionID', 'subEntities');
  }

  public function getOptionalParams() {
    return array();
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
   * Set the contact id.
   *
   * @param string $subscriptionId
   *   The contact id to set to.
   *
   * @return $this
   */
  public function setSubscriptionId($subscriptionId) {
    $this->setParam('subscriptionID', $subscriptionId);
    return $this;
  }

  /**
   * @param $journalId
   */
  public function addJournal($journalId) {
    $journals = $this->getParam('subEntities');
    $item = new \stdClass();
    $item->JournalItemID = $journalId;
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
