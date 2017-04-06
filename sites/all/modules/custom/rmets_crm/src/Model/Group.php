<?php
/**
 * @file
 */

namespace Drupal\rmets_crm\Model;

//entity type:si_group
class Group extends AbstractModel {

  protected $committeeID;
  protected $name;
  protected $twitter;
  protected $facebook;
  protected $contactID;
  protected $description;

  /**
   * @return mixed
   */
  public function getCommitteeID() {
    return $this->committeeID;
  }

  /**
   * @param mixed $committeeID
   */
  public function setCommitteeID($committeeID) {
    $this->committeeID = $committeeID;
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
  public function getTwitter() {
    return $this->twitter;
  }

  /**
   * @param mixed $twitter
   */
  public function setTwitter($twitter) {
    $this->twitter = $twitter;
  }

  /**
   * @return mixed
   */
  public function getFacebook() {
    return $this->facebook;
  }

  /**
   * @param mixed $facebook
   */
  public function setFacebook($facebook) {
    $this->facebook = $facebook;
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
  public function getDescription() {
    return $this->description;
  }

  /**
   * @param mixed $description
   */
  public function setDescription($description) {
    $this->description = $description;
  }

}