<?php
/**
 * @file
 *
 */

namespace Drupal\rmets_crm\Api\Request;

/**
 *
 */
class CreateEventRegistrationRequest extends AbstractPostRequest implements GuidRequestInterface {

  public function __construct() {
    $this->setSubEntities(array());
  }

  public function getRequiredParams() {
    return array('guid', 'eventID', 'contactID', 'registrationFeeID', 'subEntities');
  }

  public function getOptionalParams() {
    return array('organisationName', 'diretaryReq', 'specialReq');
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
   * @param string $eventId
   *   The type to set to.
   *
   * @return $this
   */
  public function setEventId($eventId) {
    $this->setParam('eventID', $eventId);
    return $this;
  }

  /**
   * Set the type.
   *
   * @param string $contactId
   *   The type to set to.
   *
   * @return $this
   */
  public function setContactId($contactId) {
    $this->setParam('contactID', $contactId);
    return $this;
  }

  /**
   * Set the type.
   *
   * @param string $registrationFeeId
   *   The type to set to.
   *
   * @return $this
   */
  public function setRegistrationFeeId($registrationFeeId) {
    $this->setParam('registrationFeeID', $registrationFeeId);
    return $this;
  }

  /**
   * Set the type.
   *
   * @param string $dietaryRequirements
   *   The type to set to.
   *
   * @return $this
   */
  public function setDietaryRequirements($dietaryRequirements) {
    $this->setParam('diretaryReq', $dietaryRequirements);
    return $this;
  }

  /**
   * Set the type.
   *
   * @param string $specialRequirements
   *   The type to set to.
   *
   * @return $this
   */
  public function setSpecialRequirements($specialRequirements) {
    $this->setParam('specialReq', $specialRequirements);
    return $this;
  }

  /**
   * Set the type.
   *
   * @param string $organisationName
   *   The type to set to.
   *
   * @return $this
   */
  public function setOrganisationName($organisationName) {
    $this->setParam('organisationName', $organisationName);
    return $this;
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
