<?php
/**
 * @file
 * Firm Profile wrapper class.
 */

namespace Drupal\rmets_membership_user\EntityWrapper\User;

use Drupal\rmets_crm\Api\ApiServerException;
use Drupal\rmets_crm\Api\Request\ContactRequest;
use Drupal\rmets_crm\Api\Request\GetContactByEmailRequest;
use Drupal\rmets_crm\Api\Request\GetContactByIdRequest;
use Drupal\rmets_crm\Api\Request\InvalidRequestException;
use Drupal\rmets_crm\Api\Request\GetAllInterestsTypesRequest;
use Drupal\rmets_crm\Api\Request\GetContactInterestsRequest;
use Drupal\rmets_crm\Api\Request\GetAllUnpaidSubscriptionPaymentsRequest;
use Drupal\rmets_crm\Api\Request\GetContactDonationsRequest;
use Drupal\rmets_crm\Api\Request\GetMemberSubscriptionByIdRequest;
use Drupal\rmets_crm\Api\Request\OptionsetRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipPackageAccreditationsRequest;
use Drupal\rmets_crm\Api\Response\AbstractResponse;
use Drupal\rmets_crm\Api\Request\UpdateContactSuffixesRequest;
use Drupal\rmets_crm\Model\AccreditationItem;
use Drupal\rmets_crm\Model\Contact;
use Drupal\rmets_crm\Model\Interest;
use Drupal\rmets_crm\Model\OptionsetObject;
use Drupal\rmets_crm\Model\PaymentSchedule;
use Drupal\rmets_crm\Api\Request\GetContactCommitteesRequest;
use Drupal\rmets_crm\Model\Subscription;
use \EntityDrupalWrapper;

/**
 * Wraps users with additional functionality.
 */
class UserWrapper extends EntityDrupalWrapper {

  protected $guid = NULL;

  /**
   * @var \Drupal\rmets_crm\Model\Contact
   */
  protected $contact;

  /**
   * @var bool
   */
  protected $invalidContactCount = FALSE;

  /**
   * @var array
   */
  protected $unpaidSubscriptions = array();

  /**
   * @var bool
   */
  protected $saveToDrupal = TRUE;

  /**
   * Creates a new Drupal user based upon the provide email address.
   *
   * @param string $email
   *   The email address to create the user with.
   *
   * @return mixed
   *   A new instance of the entity type or FALSE if there is no information for
   *   the given entity type.
   */
  public static function createNewUserAccount($email) {
    $name = substr($email, 0, strpos($email, '@'));
    return entity_create('user', array(
      'name' => $name,
      'mail' => $email,
      'access' => '0',
      'status' => 1,
      ));
  }

  /**
   * Wrap a user object.
   *
   * @param int|object $data
   *   A uid or user object.
   */
  public function __construct($data) {
    parent::__construct('user', $data);
    $this->guid = variable_get('rmets_crm_api_guid', '');
    $this->contact = new Contact(array());
  }

  /**
   * Permanently save the wrapped entity.
   *
   * @param bool $updateCrm
   *   If true will update the CRM, otherwise will only update Drupal record.
   *
   * @return \EntityDrupalWrapper
   * @throws \EntityMetadataWrapperException
   */
  public function save($updateCrm = TRUE) {
    // Update the CRM contact.
    if ($updateCrm) {
      $this->updateCrmContact();
    }

    return parent::save();
  }

  /**
   * Update the user from the CRM.
   */
  public function updateFromCrm() {
    $contact = $this->getContactFromCrm();
    if (is_null($contact)) {
      return;
    }

    $this->contact = $contact;

    // Update Drupal fields from CRM contact.
    $this->setMembershipNumber($contact->getMembershipNumber());
    $this->setCrmContactId($contact->getContactId());
    $this->setEmail($contact->getEmail());
    $this->setTitle($contact->getTitle());
    $this->setForename($contact->getForenames());
    $this->setSurname($contact->getSurname());
    $this->setMobileNumber($contact->getMobilePhone());
    $this->setDateOfBirth($contact->getDateOfBirth());
    //$this->setCommitteeMembership($contact->getCommitteeMember());
  }

  /**
   * Get a UserWrapper by CRM Id
   *
   * @param $crm_id
   * @return bool|UserWrapper
   */
  public static function getObjectByCrmId($crm_id) {
    $uid = db_query("SELECT entity_id FROM {field_data_field_crm_contact_id}
      WHERE field_crm_contact_id_value=:value",
      [':value' => $crm_id])->fetchField();
    if (is_numeric($uid)) {
      $wrapper = new UserWrapper($uid);
      return $wrapper;
    }
    return FALSE;
  }

  /**
   * Get a UserWrapper by Membership Number
   *
   * @param $membership_number
   * @return bool|UserWrapper
   */
  public static function getObjectByMembershipNumber($membership_number) {
    $uid = db_query("SELECT entity_id FROM field_data_field_membership_number
      WHERE bundle='user' AND field_membership_number_value=:value",
      [':value' => $membership_number])->fetchField();
    if (is_numeric($uid)) {
      $wrapper = new UserWrapper($uid);
      return $wrapper;
    }
    return FALSE;
  }

  /**
   * Get a UserWrapper by CRM Id
   *
   * @param $crm_id
   * @return bool|\Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper
   */
  public static function getObjectByEmail($email) {
    $uid = db_query("SELECT uid FROM {users}
      WHERE mail=:value",
      [':value' => $email])->fetchField();
    if (is_numeric($uid)) {
      $wrapper = new UserWrapper($uid);
      return $wrapper;
    }
    return FALSE;
  }

  /**
   * Checks to see if the Drupal user has a valid CRM contact ID.
   *
   * @return bool
   */
  public function isValidCrmContact() {
    return $this->getCrmContactId() != '';
  }

  /**
   * Checks if there is only one contact returned by the CRM.
   *
   * @return bool
   */
  public function hasMultipleMatchingContacts() {
    return $this->invalidContactCount;
  }

  /**
   * @return string
   */
  public function getRoles() {
    return $this->roles->value();
  }

  /**
   * @param array $roles
   */
  public function setRoles($roles) {
    $this->setPropertyValue('roles', $roles);
  }

  /**
   * Returns TRUE if the user has the role of 'member'.
   *
   * @return bool
   */
  public function hasMemberRole() {
    $roles = $this->getRoles();
    $member_role = $this->getMemberRole();
    return in_array($member_role->rid, $roles);
  }

  /**
   * Adds the member role to the user.
   */
  public function addMemberRole() {
    $roles = $this->getRoles();
    $member_role = $this->getMemberRole();
    $this->setRoles(array_merge($roles, array($member_role->rid)));
  }

  /**
   * Removes the member role from the user.
   */
  public function removeMemberRole() {
    $roles = $this->getRoles();
    $member_role = $this->getMemberRole();
    $member_role_key = array_search($member_role->rid, $roles);
    unset($roles[$member_role_key]);
    $this->setRoles($roles);
  }

  /**
   * @return string
   */
  public function getMembershipNumber() {
    return $this->field_membership_number->value();
  }

  /**
   * @param $number
   */
  public function setMembershipNumber($number) {
    $this->setPropertyValue('field_membership_number', $number);
  }

  /**
   * @return string
   */
  public function getCrmContactId() {
    return $this->field_crm_contact_id->value();
  }

  /**
   * @param $id
   */
  public function setCrmContactId($id) {
    $this->setPropertyValue('field_crm_contact_id', $id);
  }

  /**
   * @return string
   */
  public function getEmail() {
    return $this->mail->value();
  }

  /**
   * @para $email
   */
  public function setEmail($email) {
    $this->setPropertyValue('mail', $email);
  }

  /**
   * Gets the list of titles.
   *
   * @return array
   */
  function getTitleOptions() {
    return array(
      'Canon' => 'Canon',
      'Capt' => 'Capt',
      'Cdr' => 'Cdr',
      'Cdre' => 'Cdre',
      'Chev' => 'Chev',
      'Cmdr' => 'Cmdr',
      'Col' => 'Col',
      'Comm' => 'Comm',
      'Cpt' => 'Cpt',
      'Dr' => 'Dr',
      'Earl' => 'Earl',
      'G/C' => 'G/C',
      'Grp Ct' => 'Grp Ct',
      'Her' => 'Her',
      'Herr' => 'Herr',
      'His' => 'His',
      'Hon' => 'Hon',
      'L Cdr' => 'L Cdr',
      'L Col' => 'L Col',
      'L/Cdr' => 'L/Cdr',
      'L/Col' => 'L/Col',
      'Lt' => 'Lt',
      'Lt Cd' => 'Lt Cd',
      'Lt Cdr' => 'Lt Cdr',
      'Lt Col' => 'Lt Col',
      'M' => 'M',
      'Major' => 'Major',
      'Miss' => 'Miss',
      'Mlle' => 'Mlle',
      'Mr' => 'Mr',
      'Mr/Mrs' => 'Mr/Mrs',
      'Mrs' => 'Mrs',
      'Ms' => 'Ms',
      'Prof' => 'Prof',
      'Rev' => 'Rev',
      'Rev Dr' => 'Rev Dr',
      'Revd' => 'Revd',
      'Rev\'d' => 'Rev\'d',
      'Sqn Ldr' => 'S Ldr',
      'S/Ldr' => 'S/Ldr',
      'Sher' => 'Sher',
      'Sir' => 'Sir',
      'SPS' => 'SPS',
      'Sqd L' => 'Sqd L',
      'The' => 'The',
      'W/Cdr' => 'W/Cdr',
      'Cllr' => 'Councillor',
    );
  }

  /**
   * @return string
   */
  public function getTitle() {
    return $this->field_title->value();
  }

  /**
   * @param $title
   */
  public function setTitle($title) {
    $this->setPropertyValue('field_title', $title);
  }

  /**
   * @return string
   */
  public function getForename() {
    return $this->field_forenames->value();
  }

  /**
   * @param $forename
   */
  public function setForename($forename) {
    $this->setPropertyValue('field_forenames', $forename);
  }

  /**
   * @return string
   */
  public function getSurname() {
    return $this->field_surname->value();
  }

  /**
   * @param $surname
   */
  public function setSurname($surname) {
    $this->setPropertyValue('field_surname', $surname);
  }

  /**
   * @return string
   */
  public function getMobileNumber() {
    return $this->field_mobiletelephone->value();
  }

  /**
   * @param $mobileNumber
   */
  public function setMobileNumber($mobileNumber) {
    $this->setPropertyValue('field_mobiletelephone', $mobileNumber);
  }

  /**
   * @return string
   */
  public function getDateOfBirth() {
    return $this->field_dateofbirth->value();
  }

  /**
   * @param $date
   */
  public function setDateOfBirth($date) {
    if (is_array($date)) {
      // Setting date from form.
      $date = mktime(NULL, NULL, NULL, $date['month'], $date['day'], $date['year']);
    }
    else {
      // Setting date from CRM, with date in dd/mm/yyyy format - convert to timestamp.
      preg_match('/([0-9]{2})\/([0-9]{2})\/([0-9]{4}) ([0-9]{2}):([0-9]{2}):([0-9]{2})/', $date, $matches);
      if ($matches) {
        $date = strtotime(str_replace('/', '-', $date));
      }
      else {
        // Setting date from Drupal, with date in yyyy-mm-dd format - convert to dd/mm/yyyy.
        preg_match('/([0-9]{4})-([0-9]{2})-([0-9]{2})/', $date, $matches);
        if ($matches) {
          $date = strtotime($date);
        }
      }
    }
    $this->setPropertyValue('field_dateofbirth', $date);
  }

  /**
   * @return string
   */
  public function getCommitteeMembership() {
    return $this->field_committee_membership->value();
  }

  /**
   * @param $committee_membership
   */
  public function setCommitteeMembership($committee_membership) {
    $this->setPropertyValue('field_committee_membership', $committee_membership);
  }

  /**
   * Gets the list of CRM genders.
   *
   * @return array
   */
  public function getGenderOptions() {
    try {
      $request = new OptionsetRequest();
      $request->setGuid($this->guid);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->optionsetGender($request);
      $iterator = $response->getIterator();

      $list = array();
      for($iterator; $iterator->valid(); $iterator->next()) {
        /** @var OptionsetObject $item */
        $item = $iterator->current();
        $list[$item->getKey()] = $item->getValue();
      }
      return $list;
    }
    catch (InvalidRequestException $e) {
      drupal_set_message($e->getMessage(), 'error');
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return array();
  }

  /**
   * @return string
   */
  public function getMarketingMaterials() {
    return $this->contact->getMarketingMaterials();
  }

  /**
   * @param $marketingMaterials
   */
  public function setMarketingMaterials($marketingMaterials) {
    $this->contact->setMarketingMaterials($marketingMaterials);
  }

  /**
   * @return string
   */
  public function getGender() {
    return $this->contact->getGender();
  }

  /**
   * @param $gender
   */
  public function setGender($gender) {
    $this->contact->setGender($gender);
  }

  /**
   * @return string
   */
  public function getHomePhone() {
    return $this->contact->getHomePhone();
  }

  /**
   * @param $phone
   */
  public function setHomePhone($phone) {
    $this->contact->setHomePhone($phone);
  }

  /**
   * @return string
   */
  public function getBusinessPhone() {
    return $this->contact->getBusinessPhone();
  }

  /**
   * @param $phone
   */
  public function setBusinessPhone($phone) {
    $this->contact->setBusinessPhone($phone);
  }

  /**
   * Gets the list of CRM Hear About RMetS.
   *
   * @return array
   */
  public function getHearAboutRmetsOptions() {
    try {
      $request = new OptionsetRequest();
      $request->setGuid($this->guid);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->optionsetHeardAboutRMetS($request);
      $iterator = $response->getIterator();

      $list = array();
      for($iterator; $iterator->valid(); $iterator->next()) {
        /** @var OptionsetObject $item */
        $item = $iterator->current();
        $list[$item->getKey()] = $item->getValue();
      }
      return $list;
    }
    catch (InvalidRequestException $e) {
      drupal_set_message($e->getMessage(), 'error');
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return array();
  }

  /**
   * @return string
   */
  public function getHearAboutRMetS() {
    return $this->contact->getHearAboutRMetS();
  }

  /**
   * @param $hearAboutRMetS
   */
  public function setHearAboutRMetS($hearAboutRMetS) {
    $this->contact->setHearAboutRMetS($hearAboutRMetS);
  }

  /**
   * Gets the list of CRM Hear About RMetS.
   *
   * @return array
   */
  public function getInterestTypeOptions() {
    try {
      $request = new GetAllInterestsTypesRequest();
      $request->setGuid($this->guid);
      $request->setPage(1);
      $request->setRecordCount(100);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getAllInterestsTypes($request);
      $iterator = $response->getIterator();

      $list = array();
      for($iterator; $iterator->valid(); $iterator->next()) {
        /** @var Interest $item */
        $item = $iterator->current();
        $list[$item->getInterestID()] = $item->getName();
      }
      return $list;
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "getAllInterestsTypes" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return array();
  }

  /**
   * @return string
   */
  public function getCrmContactInterestTypes() {
    try {
      $request = new GetContactInterestsRequest();
      $request->setGuid($this->guid);
      $request->setContactId($this->getCrmContactId());
      $request->setPage(1);
      $request->setRecordCount(100);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getContactInterests($request);
      $iterator = $response->getIterator();

      $list = array();
      for($iterator; $iterator->valid(); $iterator->next()) {
        /** @var Interest $item */
        $item = $iterator->current();
        $list[] = $item->getInterestID();
      }
      return $list;
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "getContactInterests" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return array();
  }

  /**
   * @return mixed
   */
  public function getInterestTypes() {
    return $this->contact->getInterestTypes();
  }

  /**
   * @param $interestTypes
   */
  public function setInterestTypes($interestTypes) {
    $this->contact->setInterestTypes($interestTypes);
  }

  /**
   * @return string
   */
  public function getAddress1() {
    return $this->contact->getAddress1();
  }

  /**
   * @param $address1
   */
  public function setAddress1($address1) {
    $this->contact->setAddress1($address1);
  }

  /**
   * @return string
   */
  public function getAddress2() {
    return $this->contact->getAddress2();
  }

  /**
   * @param $address2
   */
  public function setAddress2($address2) {
    $this->contact->setAddress2($address2);
  }

  /**
   * @return string
   */
  public function getAddress3() {
    return $this->contact->getAddress3();
  }

  /**
   * @param $address3
   */
  public function setAddress3($address3) {
    $this->contact->setAddress3($address3);
  }

  /**
   * @return string
   */
  public function getCity() {
    return $this->contact->getCity();
  }

  /**
   * @param $city
   */
  public function setCity($city) {
    $this->contact->setCity($city);
  }

  /**
   * @return string
   */
  public function getStateProvince() {
    return $this->contact->getStateProvince();
  }

  /**
   * @param $state
   */
  public function setStateProvince($state) {
    $this->contact->setStateProvince($state);
  }

  /**
   * @return string
   */
  public function getPostCode() {
    return $this->contact->getPostCode();
  }

  /**
   * @param $postcode
   */
  public function setPostCode($postcode) {
    $this->contact->setPostCode($postcode);
  }

  /**
   * @return string
   */
  public function getCountry() {
    $country = $this->contact->getCountry();
    if (!empty($country)) {
      return $country;
    }
    return $this->getDefaultCountry();
  }

  /**
   * @param $country
   */
  public function setCountry($country) {
    $this->contact->setCountry($country);
  }

  /**
   * @return string
   */
  public function getFullAddress1() {
    $address = array(
      $this->getAddress1(),
      $this->getAddress2(),
      $this->getAddress3(),
      $this->getCity(),
      $this->getStateProvince(),
      $this->getPostCode(),
      $this->getCountry(),
    );
    return implode("\n", $address);
  }

  /**
   * @return string
   */
  public function get2ndAddress1() {
    return $this->contact->get2ndAddress1();
  }

  /**
   * @param $address1
   */
  public function set2ndAddress1($address1) {
    $this->contact->set2ndAddress1($address1);
  }

  /**
   * @return string
   */
  public function get2ndAddress2() {
    return $this->contact->get2ndAddress2();
  }

  /**
   * @param $address2
   */
  public function set2ndAddress2($address2) {
    $this->contact->set2ndAddress2($address2);
  }

  /**
   * @return string
   */
  public function get2ndAddress3() {
    return $this->contact->get2ndAddress3();
  }

  /**
   * @param $address3
   */
  public function set2ndAddress3($address3) {
    $this->contact->set2ndAddress3($address3);
  }

  /**
   * @return string
   */
  public function get2ndCity() {
    return $this->contact->get2ndCity();
  }

  /**
   * @param $city
   */
  public function set2ndCity($city) {
    $this->contact->set2ndCity($city);
  }

  /**
   * @return string
   */
  public function get2ndStateProvince() {
    return $this->contact->get2ndStateProvince();
  }

  /**
   * @param $state
   */
  public function set2ndStateProvince($state) {
    $this->contact->set2ndStateProvince($state);
  }

  /**
   * @return string
   */
  public function get2ndPostCode() {
    return $this->contact->get2ndPostCode();
  }

  /**
   * @param $postcode
   */
  public function set2ndPostCode($postcode) {
    $this->contact->set2ndPostCode($postcode);
  }

  /**
   * @return string
   */
  public function get2ndCountry() {
    $country = $this->contact->get2ndCountry();
    if ($country != '') {
      return $country;
    }
    return $this->getDefaultCountry();
  }

  /**
   * @param $country
   */
  public function set2ndCountry($country) {
    $this->contact->set2ndCountry($country);
  }

  /**
   * Whether we have any accreditations for the user.
   *
   * @return bool
   */
  public function hasAccreditationTypes() {
    return count($this->getAccreditationTypes()) ? TRUE : FALSE;
  }

  /**
   * Get the users accreditations.
   *
   * @return mixed
   */
  public function getAccreditationTypes() {
    return $this->field_accreditation_types->value();
  }

  /**
   * Set the users accreditations.
   *
   * @param $types
   */
  public function setAccreditationTypes($types) {
    $this->setPropertyValue('field_accreditation_types', $types, TRUE);
  }

  /**
   * Gets the list of countries.
   *
   * @return array
   */
  public function getCountryOptions() {
    module_load_include('inc', 'locale', 'locale');
    $countries_none = array('' => 'Please select a county');
    $countries_list = country_get_list();
    $countries = array_combine(array_values($countries_list), array_values($countries_list));
    return $countries_none + $countries;
  }

  /**
   * Gets the default country to select on the country selector.
   *
   * @return string
   */
  public function getDefaultCountry() {
    return 'United Kingdom';
  }

  /**
   * @param bool $returnTimestamp
   *   If set to TRUE, will return the timestamp value of the graduation date.
   *
   * @return string
   */
  public function getGraduationDate($returnTimestamp = FALSE) {
    $date = $this->contact->getGraduationDate();
    // Setting graduation date from CRM, with date in dd/mm/yyyy format - convert to timestamp.
    preg_match('/([0-9]{2})\/([0-9]{2})\/([0-9]{4}) ([0-9]{2}):([0-9]{2}):([0-9]{2})/', $date, $matches);
    if ($matches && $returnTimestamp) {
      return strtotime(str_replace('/', '-', $date));
    }
    return $date;
  }

  /**
   * @param $date
   */
  public function setGraduationDate($date) {
    if (is_array($date)) {
      // Setting date from form.
      //$date = mktime(NULL, NULL, NULL, $date['month'], $date['day'], $date['year']);
      $date = sprintf('%s/%s/%s', $date['day'], $date['month'], $date['year']);
    }
    else {
      // Setting date from CRM, with date in dd/mm/yyyy format - convert to timestamp.
      preg_match('/([0-9]{2})\/([0-9]{2})\/([0-9]{4}) ([0-9]{2}):([0-9]{2}):([0-9]{2})/', $date, $matches);
      if ($matches) {
        $date = strtotime(str_replace('/', '-', $date));
      }
      else {
        // Setting date from Drupal, with date in yyyy-mm-dd format - convert to dd/mm/yyyy.
        preg_match('/([0-9]{4})-([0-9]{2})-([0-9]{2})/', $date, $matches);
        if ($matches) {
          $date = date('d/M/Y', strtotime($date));
        }
      }
    }
    $this->contact->setGraduationDate($date);
  }

  /**
   * @return string
   */
  public function getGiftAid() {
    return $this->contact->getGiftAid();
  }

  /**
   * @param $giftAid
   */
  public function setGiftAid($giftAid) {
    $this->contact->setGiftAid($giftAid);
  }

  /**
   * @return string
   */
  public function getOccupation() {
    return $this->contact->getOccupation();
  }

  /**
   * @param $occupation
   */
  public function setOccupation($occupation) {
    $this->contact->setOccupation($occupation);
  }

  /**
   * @return string
   */
  public function getOrganisationName() {
    return $this->contact->getOrganisationName();
  }

  /**
   * @param $companyName
   */
  public function setOrganisationName($companyName) {
    $this->contact->setOrganisationName($companyName);
  }

  /**
   * @return string
   */
  public function getActiveSubscriptionID() {
    return $this->contact->getActiveSubscriptionID();
  }

  /**
   * Get the unpaid subscription payments for this user.
   *
   * @return array
   */
  public function getAllUnpaidSubscriptionPayments() {
    try {
      $request = new GetAllUnpaidSubscriptionPaymentsRequest();
      $request->setIsCacheable(FALSE);
      $request->setGuid($this->guid);
      $request->setContactId($this->getCrmContactId());
      $request->setPage(1);
      $request->setRecordCount(100);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getAllUnpaidSubscriptionPayments($request);
      $iterator = $response->getIterator();

      $list = array();
      for($iterator; $iterator->valid(); $iterator->next()) {
        /** @var PaymentSchedule $item */
        $list[] = $iterator->current();
      }
      return $list;
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "getAllUnpaidSubscriptionPayments" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return array();
  }

  /**
   * Returns TRUE if there are unpaid subscription payments.
   *
   * @return bool
   */
  public function hasUnpaidSubscriptionPayments() {
    $subscriptions = $this->getAllUnpaidSubscriptionPayments();
    if (!empty($subscriptions)) {
      $this->unpaidSubscriptions = $subscriptions;
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Returns the timestamp of a subscription renewal deadline.
   *
   * @return int
   *   Timestamp for next payment due date + 59 days.
   */
  public function getSubscriptionPaymentDeadline() {
    $unpaid_subscriptions = $this->unpaidSubscriptions;
    /** @var PaymentSchedule $next_unpaid_payment */
    $next_unpaid_payment = $unpaid_subscriptions[0];
    $due_date = $next_unpaid_payment->getDueDate();

    list($date, $time) = explode(' ', $due_date);
    list($day, $month, $year) = explode('/', $date);
    return mktime(NULL, NULL, NULL, $month, $day + 59, $year);
  }

  /**
   * Get the list of donations that this contact has made.
   *
   * @return array
   */
  public function getDonationsList() {
    try {
      $request = new GetContactDonationsRequest();
      $request->setGuid($this->guid);
      $request->setContactId($this->getCrmContactId());
      $request->setPage(1);
      $request->setRecordCount(100);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getContactDonations($request);
      return $response->getIterator();
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "getContactDonations" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return array();
  }

  /**
   * Sets the property value onto the object.
   *
   * @param string $name
   *   Property name to be set.
   * @param string $value
   *   Value to set on the property name.
   */
  protected function setPropertyValue($name, $value, $allow_empty = FALSE) {
    if (!empty($value) || $allow_empty) {
      $this->$name->set($value);
    }
  }

  /**
   * Returns the member role object.
   *
   * @return mixed
   */
  protected function getMemberRole() {
    return user_role_load_by_name(ACCESS_MEMBER_ROLE);
  }

  /**
   * Retrieves the CRM contact.
   *
   * @return \Drupal\rmets_crm\Model\Contact
   */
  protected function getContactFromCrm() {
    $crm_contact_id = $this->getCrmContactId();
    if (empty($crm_contact_id)) {
      $email = $this->getEmail();
      if (empty($email)) {
        return NULL;
      }
      return $this->getContactFromCrmByEmail();
    }
    return $this->getContactFromCrmById();
  }

  /**
   * Get the contact from the CRM by the CRM id.
   *
   * @return Contact
   */
  protected function getContactFromCrmById() {
    try {
      $request = new GetContactByIdRequest();
      $request->setIsCacheable(FALSE);
      $request->setGuid($this->guid);
      $request->setContactId($this->getCrmContactId());
      $request->setPage(1);
      $request->setRecordCount(1);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getContactById($request);
      $iterator = $response->getIterator();
      return $iterator->current();
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "getContactById" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return NULL;
  }

  /**
   * Get the contact from the CRM by the CRM email.
   *
   * @return Contact
   */
  protected function getContactFromCrmByEmail() {
    try {
      $request = new GetContactByEmailRequest();
      $request->setIsCacheable(FALSE);
      $request->setGuid($this->guid);
      $request->setContactEmail($this->getEmail());
      $request->setPage(1);
      $request->setRecordCount(5);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getContactByEmail($request);
      $iterator = $response->getIterator();

      if ($iterator->count() > 1) {
        $this->invalidContactCount = TRUE;
        return NULL;
      }

      return $iterator->current();
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "getContactByEmail" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return NULL;
  }

  /**
   * Create a contact but don't save a drupal user.
   */
  public function updateCrmContactNoDrupalSave() {
    $this->saveToDrupal = FALSE;
    try {
      $this->updateCrmContact();
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "updateCrmContact" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }
    $this->saveToDrupal = TRUE;
  }

  /**
   * @return mixed
   */
  protected function updateCrmContact() {
    try {
      $request = new ContactRequest();
      $request->setGuid($this->guid);
      $request->setTitle($this->getTitle());
      $request->setForename($this->getForename());
      $request->setSurname($this->getSurname());
      $request->setEmail($this->getEmail());
      $request->setDateOfBirth($this->getDateOfBirth());
      $request->setMembershipNumber($this->getMembershipNumber());
      $request->setBusinessPhone($this->getBusinessPhone());
      $request->setHomePhone($this->getHomePhone());
      $request->setMobilePhone($this->getMobileNumber());
      $request->setGender($this->getGender());
      $request->setMarketingMaterials($this->getMarketingMaterials());
      $request->setAddress1($this->getAddress1());
      $request->setAddress2($this->getAddress2());
      $request->setAddress3($this->getAddress3());
      $request->setCity($this->getCity());
      $request->setStateProvince($this->getStateProvince());
      $request->setPostCode($this->getPostCode());
      $request->setCountry($this->getCountry());
      $request->set2ndAddress1($this->get2ndAddress1());
      $request->set2ndAddress2($this->get2ndAddress2());
      $request->set2ndAddress3($this->get2ndAddress3());
      $request->set2ndCity($this->get2ndCity());
      $request->set2ndStateProvince($this->get2ndStateProvince());
      $request->set2ndPostCode($this->get2ndPostCode());
      $request->set2ndCountry($this->get2ndCountry());
      $request->setHearAboutRMetS($this->getHearAboutRMetS());
      $request->setGraduationDate($this->getGraduationDate());
      $request->setOccupation($this->getOccupation());
      $request->setGiftAid($this->getGiftAid());
      $request->setOrganisationName($this->getOrganisationName());

      $interests = $this->getInterestTypes();
      if (!empty($interests)) {
        foreach ($interests as $interest) {
          $request->addInterest($interest);
        }
      }

      // Determine if this is a create / update request.
      $crm_contact_id = $this->getCrmContactId();
      if (empty($crm_contact_id)) {
        $method = 'createContact';
      }
      else {
        $method = 'updateContact';
        $request->setContactId($crm_contact_id);
      }

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();

      /** @var AbstractResponse $response */
      $response = $api->$method($request);

      if ($method == 'updateContact' && (trim(strtolower($response->getId())) != trim(strtolower($crm_contact_id)))) {
        drupal_mail('rmets_crm', 'rmets_crm_alert', variable_get('rmets_crm_alert_to'), language_default(),
          array(
            'expected' => $crm_contact_id,
            'received' => $response->getId(),
          )
        );
        Throw new InvalidRequestException('Deeson contact ID check failed');
      }

      $this->setCrmContactId($response->getId());
      if ($this->saveToDrupal) {
        $this->save(FALSE);
      }
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'Error Updating user record in CRM: %ex', array('%ex' => $e->getMessage()), WATCHDOG_CRITICAL);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }
  }

  public function syncCommitteeMemberships() {
    $crm_committees = array();
    try {
      $request = new GetContactCommitteesRequest();
      $request->setGuid($this->guid);
      $request->setContactId($this->getCrmContactId());
      $request->setPage(1);
      $request->setRecordCount(100);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getContactCommittees($request);
      foreach ($response AS $id => $committee) {
        $tid = $this->committeeIdToTaxonomyTid($committee->getCommitteeId());
        if ($tid) {
          $crm_committees[] = $tid;
        }
      }
      $this->field_committee_membership = $crm_committees;
      $this->save();
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "getContactCommittees" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      print drupal_set_message('FATAL' . 'Unable to communicate with the CRM API: ' . $apie->getMessage(), 'error');
    }
  }

  public function committeeIdToTaxonomyTid($committee_id) {
    $query = new \EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term');
    $query->entityCondition('bundle', 'committees');
    $query->fieldCondition('field_crm_committees', 'value', $committee_id);
    $result = $query->execute();
    return isset($result['taxonomy_term']) ? current($result['taxonomy_term'])->tid : FALSE;
  }

  /**
   * Gets the subscription details of the current user.
   *
   * @return \Drupal\rmets_crm\Model\Subscription
   */
  public function getSubscriptionDetails() {
    try {
      if (empty($this->getActiveSubscriptionID())) {
        return NULL;
      }

      $request = new GetMemberSubscriptionByIdRequest();
      $request->setGuid($this->guid);
      $request->setSubscriptionId($this->getActiveSubscriptionID());
      $request->setPage(1);
      $request->setRecordCount(100);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getMemberSubscriptionByID($request);
      $iterator = $response->getIterator();

      return $iterator->current();
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'Failed to get accreditation list the CRM API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_CRITICAL);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

    return NULL;
  }

  /**
   * @return array|\Drupal\rmets_crm\Api\Response\AccreditationItemResponse
   * @throws \Drupal\rmets_crm\Api\ApiServerException
   */
  public function getMembershipPackageAccreditations() {
    /** @var Subscription $subscription */
    $subscription = $this->getSubscriptionDetails();

    if (!is_a($subscription, 'Drupal\rmets_crm\Model\Subscription')) {
      return array();
    }

    $request = new GetMembershipPackageAccreditationsRequest();
    $request->setGuid($this->guid);
    $request->setPackageId($subscription->getPackageID());
    $request->setPage(1);
    $request->setRecordCount(100);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    return $api->getMembershipPackageAccreditations($request);
  }

  /**
   * Get the Accreditation Application List
   *
   * @param bool|FALSE $returnObject
   *   If TRUE will return an array of AccreditationItem objects.
   *
   * @return array
   */
  public function getAccreditationApplicationList($returnObject = FALSE) {
    try {
      $response = $this->getMembershipPackageAccreditations();
      $options = array();

      $cmet = $this->getCurrentSubscriptionMembershipPackageNameIsAFellow();

      if (!is_object($response)) {
        return array();
      }
      foreach ($response->getIterator() as $category) {
        /** @var AccreditationItem $category */
        if (!$cmet && preg_match('/^cmet/i', $category->getName())) {
          continue;
        }
        if (!$category->isJoinOnline()) {
          continue;
        }

        $options[$category->getAccreditationItemID()] = ($returnObject) ? $category : $category->getName();
      }
      return $options;
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'Failed to get accreditation list the CRM API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_CRITICAL);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }
    return array();
  }

  /**
   * The name of the current subscription, e.g. Fellow
   *
   * @return string
   */
  public function getCurrentSubscriptionMembershipPackageName() {
    $type = '';
    $subscription_id = $this->getActiveSubscriptionID();
    if (!empty($subscription_id)) {
      module_load_include('inc', 'rmets_membership_purchase', 'rmets_membership_purchase.form_options');
      /** @var \Drupal\rmets_crm\Model\Subscription $current_membership_subscription */
      $current_membership_subscription = rmets_membership_subscriptions_get_subscription($subscription_id);
      if (!empty($current_membership_subscription)) {
        $type = $current_membership_subscription->getMembershipPackagePriceName();
      }
    }
    return $type;
  }

  /**
   * Whether the member is a fellow.
   *
   * @return bool
   */
  public function getCurrentSubscriptionMembershipPackageNameIsAFellow() {
    $type = $this->getCurrentSubscriptionMembershipPackageName();
    if (!empty($type) && preg_match('/^Fellow/', $type)) {
      return TRUE;
    }
    return FALSE;
  }

  function updateContactSuffixes($suffixes, $contact_id = NULL) {

    try {
      if (empty($contact_id)) {
        $contact_id = $this->getCrmContactId();
      }
      $request = new UpdateContactSuffixesRequest();
      $request->setGuid($this->guid);
      $request->setContactId($contact_id);

      if (!empty($suffixes)) {
        foreach ($suffixes AS $suffix) {
          $request->addSuffixId($suffix);
        }
      }

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->updateContactSuffixes($request);
      print_r($response);
    }
    catch (InvalidRequestException $e) {
      watchdog('CRM', 'There was an error returned when making a request for "updateContactSuffixes" on the API: %ex', array('%ex' => $e->getMessage()), WATCHDOG_ERROR);
    }
    catch (ApiServerException $apie) {
      watchdog('CRM', 'Unable to communicate with the CRM API: %ex', array('%ex' => $apie->getMessage()), WATCHDOG_CRITICAL);
    }

  }

  /**
   * Gets the AccreditationItem object for the given accreditationItemId.
   *
   * @param string $accreditationItemId
   *
   * @return AccreditationItem object|null
   */
  public function getAccreditationApplicationDetails($accreditationItemId) {
    $this->updateFromCrm();

    // Show an error message to a CRM admin person.
    if ($this->hasMultipleMatchingContacts()) {
      drupal_set_message(t('There were multiple records found in CRM for your email address. Please contact the membership department for further instructions.'), 'error');
      return NULL;
    }

    $accreditationItems = $this->getAccreditationApplicationList(TRUE);
    return array_key_exists($accreditationItemId, $accreditationItems) ? $accreditationItems[$accreditationItemId] : NULL;
  }
}
