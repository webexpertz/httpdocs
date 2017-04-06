<?php

/**
 * @file
 * Drush import scripts.
 */

use Drupal\rmets_crm\Api\ApiServerException;
use Drupal\rmets_crm\Api\Request\InvalidRequestException;
use Drupal\rmets_crm\Api\ApiClientException;

use Drupal\rmets_crm\Api\Request\GetAllContactsRequest;
use Drupal\rmets_crm\Api\Request\GetContactByEmailRequest;
use Drupal\rmets_crm\Api\Request\GetContactByIdRequest;
use Drupal\rmets_crm\Api\Request\GetAllMembershipPackagePricesRequest;
use Drupal\rmets_crm\Api\Request\GetAllUnpaidSubscriptionPaymentsRequest;
use Drupal\rmets_crm\Api\Request\GetMemberUnpaidSubscriptionPaymentsRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipPackageJournalsRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipPackageAccreditationsRequest;
use Drupal\rmets_crm\Api\Request\CreateEventRegistrationRequest;
use Drupal\rmets_crm\Api\Request\CreateContactSubscriptionRequest;
use Drupal\rmets_crm\Api\Request\GetMemberSubscriptionJournalsRequest;
use Drupal\rmets_crm\Api\Request\GetAllInterestsTypesRequest;
use Drupal\rmets_crm\Api\Request\GetContactInterestsRequest;
use Drupal\rmets_crm\Api\Request\GetAllEventsRequest;
use Drupal\rmets_crm\Api\Request\GetEventRegistrationFeesRequest;
use Drupal\rmets_crm\Api\Request\GetEventRegistrationFeesOptionalsRequest;
use Drupal\rmets_crm\Api\Request\GetEventSessionsRequest;
use Drupal\rmets_crm\Api\Request\GetEventSessionItemsRequest;
use Drupal\rmets_crm\Api\Request\GetEventSpeakersRequest;
use Drupal\rmets_crm\Api\Request\GetEventAbstractRequest;
use Drupal\rmets_crm\Api\Request\GetEventAbstractsAuthorsRequest;
use Drupal\rmets_crm\Api\Request\GetEventAbstractsSpeakersRequest;
use Drupal\rmets_crm\Api\Request\GetEventThemesRequest;
use Drupal\rmets_crm\Api\Request\GetMemberSubscriptionByIdRequest;
use Drupal\rmets_crm\Api\Request\RemoveMemberSubscriptionJournalsRequest;
use Drupal\rmets_crm\Api\Request\AddMemberSubscriptionJournalsRequest;
use Drupal\rmets_crm\Api\Request\MarkSubscriptionPaymentsAsPaidRequest;
use Drupal\rmets_crm\Api\Request\GetContactDonationsRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipPackagePricesByIdRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipAccreditationItemByIdRequest;
use Drupal\rmets_crm\Api\Request\GetAllReciprocalOrganisationsRequest;
use Drupal\rmets_crm\Api\Request\GetAllAccreditationCategoriesRequest;
use Drupal\rmets_crm\Api\Request\GetAllAccreditatedContactsRequest;
use Drupal\rmets_crm\Api\Request\GetAllAwardsCategoriesRequest;
use Drupal\rmets_crm\Api\Request\CreateAbstractRequest;
use Drupal\rmets_crm\Api\Request\UpdateAbstractRequest;
use Drupal\rmets_crm\Api\Request\GetAwardsWinnersRequest;
use Drupal\rmets_crm\Api\Request\GetAllCommitteesRequest;
use Drupal\rmets_crm\Api\Request\GetContactCommitteesRequest;
use Drupal\rmets_crm\Api\Request\CreateAccreditationApplicationRequest;
use Drupal\rmets_crm\Api\Request\CompleteAccreditationApplicationRequest;
use Drupal\rmets_crm\Api\Request\GetAllFrmetsContactsRequest;
use Drupal\rmets_crm\Api\Request\ContactRequest;
use Drupal\rmets_crm\Api\Request\OptionsetRequest;

/**
 * Implements hook_drush_command().
 */
function rmets_crm_drush_command() {
  $items = array();

  $items['rmets-crm-get-contact-by-email'] = array(
    'description' => 'Process the CRM endpoint for the command: GetContactByEmail',
    'options' => array(
      'guid' => '',
      'email' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-contact-by-id'] = array(
    'description' => 'Process the CRM endpoint for the command: GetContactById',
    'options' => array(
      'guid' => '',
      'contactId' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-all-contacts'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllContacts',
    'options' => array(
      'guid' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-create-contact'] = array(
    'description' => 'Process the CRM endpoint for the command: CreateContact',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-all-membership-package-prices'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllMembershipPackagePrices',
    'options' => array(
      'guid' => '',
      'validFrom' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-membership-package-prices-by-id'] = array(
    'description' => 'Process the CRM endpoint for the command: GetMembershipPackagePricesById',
    'options' => array(
      'guid' => '',
      'membershipPackagePriceID' => 'MembershipPackagePriceID GUID',
    ),
  );

  $items['rmets-crm-get-membership-package-journals'] = array(
    'description' => 'Process the CRM endpoint for the command: GetMembershipPackageJournals',
    'options' => array(
      'guid' => '',
      'packageId' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-create-contact-subscription'] = array(
    'description' => 'Process the CRM endpoint for the command: CreateContactSubscription',
    'options' => array(
      'guid' => '',
      'contactId' => 'ContactID',
      'packagePriceId' => 'MembershipPackagePriceID',
      'donation' => '',
      'giftFrom' => 'GUID of the contact that is creating the gift',
      'sponsors' => '',
      'reciprocalOrganisationID' => 'Organistation ID from GetAllReciprocalOrganistation API endpoint',
      'reciprocalMembershipNumber' => '',
      'subEntities' => 'A comma separated list of JournalItemIDs to add.',
    ),
  );

  $items['rmets-crm-remove-member-subscription-journals'] = array(
    'description' => 'Process the CRM endpoint for the command: RemoveMemberSubscriptionJournals',
    'options' => array(
      'guid' => '',
      'subscriptionId' => '',
    ),
  );

  $items['rmets-crm-add-member-subscription-journals'] = array(
    'description' => 'Process the CRM endpoint for the command: AddMemberSubscriptionJournals',
    'options' => array(
      'guid' => '',
      'subscriptionId' => '',
      'subEntities' => '',
    ),
  );

  $items['rmets-crm-get-all-unpaid-subscription-payments'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllUnpaidSubscriptionPayments',
    'options' => array(
      'guid' => '',
      'contactId' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-mark-subscription-payments-as-paid'] = array(
    'description' => 'Process the CRM endpoint for the command: MarkSubscriptionPaymentsAsPaid',
    'options' => array(
      'guid' => '',
      'subscriptionId' => '',
      'donation' => '',
      'subEntities' => '',
    ),
  );

  $items['rmets-crm-update-contact'] = array(
    'description' => 'Process the CRM endpoint for the command: UpdateContact',
    'options' => array(
      'guid' => '',
      'contactId' => '',
    ),
  );

  $items['rmets-crm-get-membership-package-accreditations'] = array(
    'description' => 'Process the CRM endpoint for the command: GetMembershipPackageAccreditations',
    'options' => array(
      'guid' => '',
      'packageId' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-membership-accreditation-item-by-id'] = array(
    'description' => 'Process the CRM endpoint for the command: GetMembershipAccreditationItemById',
    'options' => array(
      'guid' => '',
      'accreditationItemID' => 'AccreditationItemID GUID',
    ),
  );

  $items['rmets-crm-create-accreditation-application'] = array(
    'description' => 'Process the CRM endpoint for the command: CreateAccreditationApplication',
    'options' => array(
      'guid' => '',
      'accreditationItemId' => '',
      'contactId' => '',
      'url' => '',
    ),
  );

  $items['rmets-crm-complete-accreditation-application'] = array(
    'description' => 'Process the CRM endpoint for the command: CompleteAccreditationApplication',
    'options' => array(
      'guid' => '',
      'accreditationApplicationId' => '',
    ),
  );

  $items['rmets-crm-get-all-events'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllEvents',
    'options' => array(
      'guid' => '',
      'fromDate' => '',
    ),
  );

  $items['rmets-crm-get-event-sessions'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventSessions',
    'options' => array(
      'guid' => '',
      'eventId' => '',
    ),
  );

  $items['rmets-crm-get-event-session-items'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventSessionItems',
    'options' => array(
      'guid' => '',
      'eventId' => '',
    ),
  );

  $items['rmets-crm-get-event-speakers'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventSpeakers',
    'options' => array(
      'guid' => '',
      'eventId' => '',
    ),
  );

  $items['rmets-crm-get-event-abstract'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventAbstract',
    'options' => array(
      'guid' => '',
      'abstractId' => '',
    ),
  );

  $items['rmets-crm-get-event-abstract-authors'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventAbstractsAuthors',
    'options' => array(
      'guid' => '',
      'abstractId' => '',
    ),
  );

  $items['rmets-crm-get-event-abstract-speakers'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventAbstractsSpeakers',
    'options' => array(
      'guid' => '',
      'abstractId' => '',
    ),
  );

  $items['rmets-crm-get-event-themes'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventThemes',
    'options' => array(
      'guid' => '',
      'eventId' => '',
    ),
  );

  $items['rmets-crm-get-event-registration-fees'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventRegistrationFees',
    'options' => array(
      'guid' => '',
      'eventId' => '',
    ),
  );

  $items['rmets-crm-get-event-registration-fees-optionals'] = array(
    'description' => 'Process the CRM endpoint for the command: GetEventRegistrationFeesOptionals',
    'options' => array(
      'guid' => '',
      'eventId' => '',
    ),
  );

  $items['rmets-crm-create-event-registration'] = array(
    'description' => 'Process the CRM endpoint for the command: CreateEventRegistration',
    'options' => array(
      'guid' => '',
      'eventId' => '',
      'contactId' => '',
      'registrationFee' => '',
      'dietaryRequirements' => '',
      'specialRequirements' => '',
      'organisationName' => '',
    ),
  );

  $items['rmets-crm-create-abstract'] = array(
    'description' => 'Process the CRM endpoint for the command: CreateAbstract',
    'options' => array(
      'guid' => '',
      'eventId' => 'Event GUID',
      'title' => '',
      'mainAuthorId' => 'Contact GUID',
      'summary' => '',
      'theme' => '',
      'affiliationId' => '',
      'subEntities' => 'List of Contact GUIDs',
    ),
  );

  $items['rmets-crm-update-abstract'] = array(
    'description' => 'Process the CRM endpoint for the command: UpdateAbstract',
    'options' => array(
      'guid' => '',
      'abstractId' => 'Abstract GUID',
      'eventId' => 'Event GUID',
      'title' => '',
      'mainAuthorId' => 'Contact GUID',
      'summary' => '',
      'theme' => '',
      'affiliationId' => '',
      'subEntities' => '',
    ),
  );

  /* @todo
  $items['rmets-crm-update-contact-dietary-requirements'] = array(
    'description' => 'Process the CRM endpoint for the command: UpdateContactDietaryRequirements',
    'options' => array(
      'guid' => '',
    ),
  );*/

  /* @todo
  $items['rmets-crm-update-contact-special-requirements'] = array(
    'description' => 'Process the CRM endpoint for the command: UpdateContactSpecialRequirements',
    'options' => array(
      'guid' => '',
    ),
  );*/

  $items['rmets-crm-get-all-interest-types'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllInterestsTypes',
    'options' => array(
      'guid' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-all-accredditation-categories'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllAccreditationCategories',
    'options' => array(
      'guid' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-all-accredditated-contacts'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllAccreditatedContacts',
    'options' => array(
      'guid' => '',
      'accreditationId' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-all-frmets-contacts'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllFRMetSContacts',
    'options' => array(
      'guid' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-all-award-categories'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllAwardsCategories',
    'options' => array(
      'guid' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-award-winners'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAwardsWinners',
    'options' => array(
      'guid' => '',
      'awardId' => 'Award GUID',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-member-subscription-by-id'] = array(
    'description' => 'Process the CRM endpoint for the command: GetMemberSubscriptionByID',
    'options' => array(
      'guid' => '',
      'subscriptionId' => '',
    ),
  );

  $items['rmets-crm-get-member-subscription-journals'] = array(
    'description' => 'Process the CRM endpoint for the command: GetMemberSubscriptionJournals',
    'options' => array(
      'guid' => '',
      'subscriptionId' => '',
    ),
  );

  $items['rmets-crm-get-contact-donations'] = array(
    'description' => 'Process the CRM endpoint for the command: GetContactDonations',
    'options' => array(
      'guid' => '',
      'contactId' => '',
    ),
  );

  $items['rmets-crm-get-contact-interests'] = array(
    'description' => 'Process the CRM endpoint for the command: GetContactInterests',
    'options' => array(
      'guid' => '',
      'contactId' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-all-reciprocal-organisations'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllReciprocalOrganisations',
    'options' => array(
      'guid' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-all-committees'] = array(
    'description' => 'Process the CRM endpoint for the command: GetAllCommittees',
    'options' => array(
      'guid' => '',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-contact-committees'] = array(
    'description' => 'Process the CRM endpoint for the command: GetContactCommittees',
    'options' => array(
      'guid' => '',
      'contactId' => 'Contact GUID',
      'page' => '',
      'recordcount' => '',
    ),
  );

  $items['rmets-crm-get-all-suffixes'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetSubscriptionPaymentStatus',
    'options' => array(
      'guid' => '',
    ),
  );

  /******** OptionSets ********/

  $items['rmets-crm-get-optionset-abstracts-types'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetAbstractsTypes',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-dietary-requirements'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetDietaryRequirements',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-gender'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetGender',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-heard-about-rmets'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetHeardAboutRMetS',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-membership-status'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetMembershipStatus',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-payment-frequency'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetPaymentFrequency',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-payment-method'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetPaymentMethod',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-prefferred-contact-method'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetPreferredContactMethod',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-special-requirements'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetSpecialRequirements',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-subscription-payment-status'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetSubscriptionPaymentStatus',
    'options' => array(
      'guid' => '',
    ),
  );

  $items['rmets-crm-get-optionset-events-types'] = array(
    'description' => 'Process the CRM endpoint for the command: OptionsetEventsTypes',
    'options' => array(
      'guid' => '',
    ),
  );

  return $items;
}

/**
 * Drush callback to make a request for the API command getAllContacts.
 * @return mixed
 */
function drush_rmets_crm_get_all_contacts() {
  $cmd = 'getAllContacts';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount");

  try {
    $request = new GetAllContactsRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllContacts($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command getContactByEmail.
 * @return mixed
 */
function drush_rmets_crm_get_contact_by_email() {
  $cmd = 'getContactByEmail';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $email = drush_get_option('email', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, email: $email");

  try {
    $request = new GetContactByEmailRequest();
    $request->setGuid($guid);
    $request->setContactEmail($email);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getContactByEmail($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command getContactById.
 * @return mixed
 */
function drush_rmets_crm_get_contact_by_id() {
  $cmd = 'getContactById';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $contactId = drush_get_option('contactId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, contactId: $contactId");

  try {
    $request = new GetContactByIdRequest();
    $request->setGuid($guid);
    $request->setContactId($contactId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getContactById($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command getAllMembershipPackagePrices.
 * @return mixed
 */
function drush_rmets_crm_get_all_membership_package_prices() {
  $cmd = 'getAllMembershipPackagePrices';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $validFrom = drush_get_option('validFrom', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, validFrom: $validFrom");

  try {
    $request = new GetAllMembershipPackagePricesRequest();
    $request->setGuid($guid);
    $request->setValidFrom($validFrom);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllMembershipPackagePrices($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetMembershipPackagePricesById.
 * @return mixed
 */
function drush_rmets_crm_get_membership_package_prices_by_id() {
  $cmd = 'GetMembershipPackagePricesById';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $membershipPackagePriceID = drush_get_option('membershipPackagePriceID', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, membershipPackagePriceID: $membershipPackagePriceID");

  try {
    $request = new GetMembershipPackagePricesByIdRequest();
    $request->setGuid($guid);
    $request->setMembershipPackagePriceId($membershipPackagePriceID);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getMembershipPackagePricesById($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetMembershipAccreditationItemById.
 * @return mixed
 */
function drush_rmets_crm_get_membership_accreditation_item_by_id() {
  $cmd = 'GetMembershipAccreditationItemById';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $accreditationItemID = drush_get_option('accreditationItemID', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, accreditationItemID: $accreditationItemID");

  try {
    $request = new GetMembershipAccreditationItemByIdRequest();
    $request->setGuid($guid);
    $request->setAccreditationItemID($accreditationItemID);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getMembershipAccreditationItemById($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetMembershipPackageJournals.
 * @return mixed
 */
function drush_rmets_crm_get_membership_package_journals() {
  $cmd = 'getMembershipPackageJournals';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $packageId= drush_get_option('packageId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, packageId: $packageId");

  try {
    $request = new GetMembershipPackageJournalsRequest();
    $request->setGuid($guid);
    $request->setPackageId($packageId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getMembershipPackageJournals($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAllEvents.
 * @return mixed
 */
function drush_rmets_crm_get_all_events() {
  $cmd = 'GetAllEvents';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $fromDate = drush_get_option('fromDate', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, fromDate: $fromDate");

  try {
    $request = new GetAllEventsRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    if (!empty($fromDate)) {
      $request->setFromDate($fromDate);
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllEvents($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAllSuffixes.
 * @return mixed
 */
function drush_rmets_crm_get_all_suffixes() {
  $cmd = 'GetAllSuffixes';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, fromDate: $fromDate");

  try {
    $request = new GetAllSuffixesRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);


    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllSuffixes($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventRegistrationFees.
 * @return mixed
 */
function drush_rmets_crm_get_event_registration_fees() {
  $cmd = 'GetEventRegistrationFees';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $eventId = drush_get_option('eventId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, eventId: $eventId");

  try {
    $request = new GetEventRegistrationFeesRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setEventId($eventId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventRegistrationFees($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventRegistrationFeesOptionals.
 * @return mixed
 */
function drush_rmets_crm_get_event_registration_fees_optionals() {
  $cmd = 'GetEventRegistrationFeesOptionals';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $eventId = drush_get_option('eventId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, eventId: $eventId");

  try {
    $request = new GetEventRegistrationFeesOptionalsRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setEventId($eventId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventRegistrationFeesOptionals($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command CreateEventRegistration.
 * @return mixed
 */
function drush_rmets_crm_create_event_registration() {
  $cmd = 'createEventRegistration';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $eventId = drush_get_option('eventId', '');
  $contactId = drush_get_option('contactId', '');
  $registrationFee = drush_get_option('registrationFee', '');
  $dietaryRequirements = drush_get_option('dietaryRequirements', '');
  $specialRequirements = drush_get_option('specialRequirements', '');
  $organisationName = drush_get_option('organisationName', '');

  drush_print("process command: $cmd for eventId: $eventId, contactId: $contactId, organisationName: $organisationName");

  try {
    $request = new CreateEventRegistrationRequest();
    $request->setGuid($guid);
    $request->setEventId($eventId);
    $request->setContactId($contactId);
    $request->setRegistrationFeeId($registrationFee);
    if (!empty($dietaryRequirements)) {
      $request->setDietaryRequirements($dietaryRequirements);
    }
    if (!empty($specialRequirements)) {
      $request->setSpecialRequirements($specialRequirements);
    }
    if (!empty($organisationName)) {
      $request->setOrganisationName($organisationName);
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->createEventRegistration($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventSessions.
 * @return mixed
 */
function drush_rmets_crm_get_event_sessions() {
  $cmd = 'GetEventSessions';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $eventId = drush_get_option('eventId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, eventId: $eventId");

  try {
    $request = new GetEventSessionsRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setEventId($eventId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventSessions($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventSessionItems.
 * @return mixed
 */
function drush_rmets_crm_get_event_session_items() {
  $cmd = 'GetEventSessionItems';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $eventId = drush_get_option('eventId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, eventId: $eventId");

  try {
    $request = new GetEventSessionItemsRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setEventId($eventId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventSessionItems($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventSpeakers.
 * @return mixed
 */
function drush_rmets_crm_get_event_speakers() {
  $cmd = 'GetEventSpeakers';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $eventId = drush_get_option('eventId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, eventId: $eventId");

  try {
    $request = new GetEventSpeakersRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setEventId($eventId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventSpeakers($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventAbstract.
 * @return mixed
 */
function drush_rmets_crm_get_event_abstract() {
  $cmd = 'GetEventAbstract';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $abstractId = drush_get_option('abstractId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, abstractId: $abstractId");

  try {
    $request = new GetEventAbstractRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setAbstractId($abstractId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventAbstract($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventAbstractsAuthors.
 * @return mixed
 */
function drush_rmets_crm_get_event_abstract_authors() {
  $cmd = 'GetEventAbstractsAuthors';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $abstractId = drush_get_option('abstractId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, abstractId: $abstractId");

  try {
    $request = new GetEventAbstractsAuthorsRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setAbstractId($abstractId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventAbstractsAuthors($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventAbstractsSpeakers.
 * @return mixed
 */
function drush_rmets_crm_get_event_abstract_speakers() {
  $cmd = 'GetEventAbstractsSpeakers';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $abstractId = drush_get_option('abstractId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, abstractId: $abstractId");

  try {
    $request = new GetEventAbstractsSpeakersRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setAbstractId($abstractId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventAbstractsSpeakers($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetEventSessions.
 * @return mixed
 */
function drush_rmets_crm_get_event_themes() {
  $cmd = 'GetEventThemes';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $eventId = drush_get_option('eventId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, eventId: $eventId");

  try {
    $request = new GetEventThemesRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);
    $request->setEventId($eventId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getEventThemes($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command CreateContactSubscription.
 * @return mixed
 */
function drush_rmets_crm_create_contact_subscription() {
  $cmd = 'CreateContactSubscription';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $contactId = drush_get_option('contactId', '');
  $packagePriceId = drush_get_option('packagePriceId', '');
  $donation = drush_get_option('donation', '');
  $giftFrom = drush_get_option('giftFrom', '');
  $sponsors = drush_get_option('sponsors', '');
  $reciprocalOrganisationID = drush_get_option('reciprocalOrganisationID', '');
  $reciprocalMembershipNumber = drush_get_option('reciprocalMembershipNumber', '');
  $subEntities = drush_get_option('subEntities', '');
  drush_print("process command: $cmd for contactId: $contactId, packagePriceId: $packagePriceId, donation: $donation, giftFrom: $giftFrom, sponsors: $sponsors, reciprocalOrganisationID: $reciprocalOrganisationID, reciprocalMembershipNumber: $reciprocalMembershipNumber, subEntities: $subEntities");

  try {
    $request = new CreateContactSubscriptionRequest();
    $request->setGuid($guid);
    $request->setContactId($contactId);
    $request->setPackagePriceId($packagePriceId);

    if (!empty($donation)) {
      $request->setDonation($donation);
    }

    if (!empty($giftFrom)) {
      $request->setGiftFrom($giftFrom);
    }

    if (!empty($sponsors)) {
      $request->setSponsors($sponsors);
    }

    if (!empty($reciprocalOrganisationID)) {
      $request->setReciprocalOrganisationID($reciprocalOrganisationID);
    }

    if (!empty($reciprocalMembershipNumber)) {
      $request->setReciprocalMembershipNumber($reciprocalMembershipNumber);
    }

    if (!empty($subEntities)) {
      $entities = explode(',', $subEntities);
      foreach ($entities as $entityId) {
        $request->addJournal($entityId);
      }
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->createContactSubscription($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiClientException $apice) {
    print drush_set_error('FATAL', $apice->getMessage());
  }
  catch (ApiServerException $apise) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apise->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command getAllUnpaidSubscriptionPayments.
 * @return mixed
 */
function drush_rmets_crm_get_all_unpaid_subscription_payments() {
  $cmd = 'getAllUnpaidSubscriptionPayments';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $contactId = drush_get_option('contactId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, contactId: $contactId");

  try {
    $request = new GetAllUnpaidSubscriptionPaymentsRequest();
    $request->setGuid($guid);
    $request->setContactId($contactId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllUnpaidSubscriptionPayments($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command RemoveMemberSubscriptionJournals.
 * @return mixed
 */
function drush_rmets_crm_remove_member_subscription_journals() {
  $cmd = 'RemoveMemberSubscriptionJournals';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $subscriptionId = drush_get_option('subscriptionId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, subscriptionId: $subscriptionId");

  try {
    $request = new RemoveMemberSubscriptionJournalsRequest();
    $request->setGuid($guid);
    $request->setSubscriptionId($subscriptionId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->removeMemberSubscriptionJournals($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command AddMemberSubscriptionJournals.
 * @return mixed
 */
function drush_rmets_crm_add_member_subscription_journals() {
  $cmd = 'AddMemberSubscriptionJournals';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $subscriptionId = drush_get_option('subscriptionId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  $subEntities = drush_get_option('subEntities', '');
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, subscriptionId: $subscriptionId, subEntities: $subEntities");

  try {
    $request = new AddMemberSubscriptionJournalsRequest();
    $request->setGuid($guid);
    $request->setSubscriptionId($subscriptionId);

    if (!empty($subEntities)) {
      $entities = explode(',', $subEntities);
      foreach ($entities as $entityId) {
        $request->addJournal($entityId);
      }
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->addMemberSubscriptionJournals($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command CreateAbstract.
 * @return mixed
 */
function drush_rmets_crm_create_abstract() {
  $cmd = 'CreateAbstract';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $eventId = drush_get_option('eventId', '');
  $mainAuthorId = drush_get_option('mainAuthorId', '');
  $title = drush_get_option('title', '');
  $summary = drush_get_option('summary', '');
  $theme = drush_get_option('theme', '');
  $affiliationId = drush_get_option('affiliationId', '');
  $subEntities = drush_get_option('subEntities', '');
  drush_print("process command: $cmd for eventId: $eventId, title: $title, mainAuthorID: $mainAuthorId, summary: $summary, theme: $theme, affiliationID: $affiliationId, subEntities: $subEntities");

  try {
    $request = new CreateAbstractRequest();
    $request->setGuid($guid);
    $request->setEventId($eventId);

    if (!empty($mainAuthorId)) {
      $request->setMainAuthorId($mainAuthorId);
    }

    if (!empty($title)) {
      $request->setTitle($title);
    }

    if (!empty($summary)) {
      $request->setSummary($summary);
    }

    if (!empty($theme)) {
      $request->setTheme($theme);
    }

    if (!empty($affiliationId)) {
      $request->setAffiliationId($affiliationId);
    }

    if (!empty($subEntities)) {
      $entities = explode(',', $subEntities);
      foreach ($entities as $entityId) {
        $request->addContactId($entityId);
      }
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->createAbstract($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}
/**
 * Drush callback to make a request for the API command UpdateAbstract.
 * @return mixed
 */
function drush_rmets_crm_update_abstract() {
  $cmd = 'UpdateAbstract';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $abstractId = drush_get_option('abstractId', '');
  $eventId = drush_get_option('eventId', '');
  $mainAuthorId = drush_get_option('mainAuthorId', '');
  $title = drush_get_option('title', '');
  $summary = drush_get_option('summary', '');
  $theme = drush_get_option('theme', '');
  $affiliationId = drush_get_option('affiliationId', '');
  $subEntities = drush_get_option('subEntities', '');
  drush_print("process command: $cmd for abstractId: $abstractId, eventId: $eventId, title: $title, mainAuthorID: $mainAuthorId, summary: $summary, theme: $theme, affiliationID: $affiliationId, subEntities: $subEntities");

  try {
    $request = new UpdateAbstractRequest();
    $request->setGuid($guid);
    $request->setAbstractId($abstractId);
    $request->setEventId($eventId);

    if (!empty($mainAuthorId)) {
      $request->setMainAuthorId($mainAuthorId);
    }

    if (!empty($title)) {
      $request->setTitle($title);
    }

    if (!empty($summary)) {
      $request->setSummary($summary);
    }

    if (!empty($theme)) {
      $request->setTheme($theme);
    }

    if (!empty($affiliationId)) {
      $request->setAffiliationId($affiliationId);
    }

    if (!empty($subEntities)) {
      $entities = explode(',', $subEntities);
      foreach ($entities as $entityId) {
        $request->addContactId($entityId);
      }
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->updateAbstract($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetMemberUnpaidSubscriptionPayments.
 * @return mixed
 */
function drush_rmets_crm_get_membership_unpaid_subscription_payments() {
  $cmd = 'GetMemberUnpaidSubscriptionPayments';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $subscriptionId = drush_get_option('subscriptionId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, subscriptionId: $subscriptionId");

  try {
    $request = new GetMemberUnpaidSubscriptionPaymentsRequest();
    $request->setGuid($guid);
    $request->setSubscriptionId($subscriptionId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getMemberUnpaidSubscriptionPayments($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command MarkSubscriptionPaymentsAsPaid.
 * @return mixed
 */
function drush_rmets_crm_mark_subscription_payments_as_paid() {
  $cmd = 'MarkSubscriptionPaymentsAsPaid';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $subscriptionId = drush_get_option('subscriptionId', '');
  $donation = drush_get_option('donation', '');
  drush_print("process command: $cmd for subscriptionId: $subscriptionId, donation: $donation");

  try {
    $request = new MarkSubscriptionPaymentsAsPaidRequest();
    $request->setGuid($guid);
    $request->setSubscriptionId($subscriptionId);

    if (!empty($donation)) {
      $request->setDonation($donation);
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->markSubscriptionPaymentsAsPaid($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command UpdateContact.
 * @return mixed
 */
function drush_rmets_crm_update_contact() {
  $cmd = 'UpdateContact';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  //$contactId = drush_get_option('contactId', '');
  $contactId = '7b2f7f70-8b2c-e511-80bb-00155dfb730d';
  drush_print("process command: $cmd for contactId: $contactId");

  try {
    $request = new ContactRequest();
    $request->setGuid($guid);
    $request->setContactId($contactId);
    $request->setTitle('Mr1');
    $request->setForename('Joe1');
    $request->setSurname('1Test ' . time());
    $request->setEmail('1test+@' . time() . '.com');
    $request->setDateOfBirth('01/01/2001');
    $request->setMembershipNumber('111');
    $request->setBusinessPhone('221');
    $request->setMobilePhone('331');
    $request->setHomePhone('4441');
    //$request->setOrganisationId('');
    $request->setGender(2);
    $request->setMarketingMaterials(1);
    $request->setAddress1('a111');
    $request->setAddress2('a121');
    $request->setAddress3('a131');
    $request->setCity('c11');
    $request->setStateProvince('s11');
    $request->setPostCode('p11');
    $request->setCountry('co11');
    $request->set2ndAddress1('a211');
    $request->set2ndAddress2('a221');
    $request->set2ndAddress3('a231');
    $request->set2ndCity('c21');
    $request->set2ndStateProvince('s21');
    $request->set2ndPostCode('p21');
    $request->set2ndCountry('co21');
    $request->setHearAboutRMetS(157420007);
    $request->setGraduationDate('01/01/2011');
    $request->setOccupation('tea boy1');
    $request->setOtherOccupation('coffee boy1');
    $request->setGiftAid(1);
    $request->setOrganisationName('test company2');

    $subEntities = array();
    //$subEntities = array('226e4dce-070a-e511-80ba-00155dfb730d', 'ffa745d4-070a-e511-80ba-00155dfb730d');
    if (!empty($subEntities)) {
      foreach ($subEntities as $entityId) {
        $request->addInterest($entityId);
      }
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->updateContact($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiClientException $apice) {
    print drush_set_error('FATAL', $apice->getMessage());
  }
  catch (ApiServerException $apise) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apise->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command UpdateContact.
 * @return mixed
 */
function drush_rmets_crm_create_contact() {
  $cmd = 'CreateContact';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  drush_print("process command: $cmd");

  try {
    $request = new ContactRequest();
    $request->setGuid($guid);
    $request->setTitle('Mr1');
    $request->setForename('Joe1');
    $request->setSurname('1Test ' . time());
    $request->setEmail('1test@' . time() . '.com');
    $request->setDateOfBirth('01/01/2001');
    $request->setMembershipNumber('111');
    $request->setBusinessPhone('221');
    $request->setMobilePhone('331');
    //$request->setOrganisationId('');
    $request->setGender(2);
    $request->setMarketingMaterials(0);
    $request->setAddress1('a111');
    $request->setAddress2('a121');
    $request->setAddress3('a131');
    $request->setCity('c11');
    $request->setStateProvince('s11');
    $request->setPostCode('PO32 6AH');
    $request->setCountry('co11');
    $request->set2ndAddress1('a211');
    $request->set2ndAddress2('a221');
    $request->set2ndAddress3('a231');
    $request->set2ndCity('c21');
    $request->set2ndStateProvince('s21');
    $request->set2ndPostCode('CT1 2PT');
    $request->set2ndCountry('co21');
    $request->setHearAboutRMetS(157420007);
    $request->setGraduationDate('01/01/2011');
    $request->setOccupation('tea boy1');
    $request->setOtherOccupation('coffee boy1');
    $request->setGiftAid(0);
    $request->setOrganisationName('test company');

    //$subEntities = array('226e4dce-070a-e511-80ba-00155dfb730d', 'ffa745d4-070a-e511-80ba-00155dfb730d');
    $subEntities = array();
    if (!empty($subEntities)) {
      foreach ($subEntities as $entityId) {
        $request->addInterest($entityId);
      }
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->createContact($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiClientException $apice) {
    print drush_set_error('FATAL', $apice->getMessage());
  }
  catch (ApiServerException $apise) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apise->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetMembershipPackageAccreditations.
 * @return mixed
 */
function drush_rmets_crm_get_membership_package_accreditations() {
  $cmd = 'GetMembershipPackageAccreditations';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $packageId = drush_get_option('packageId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, packageId: $packageId");

  try {
    $request = new GetMembershipPackageAccreditationsRequest();
    $request->setGuid($guid);
    $request->setPackageId($packageId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getMembershipPackageAccreditations($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAllInterestsTypes.
 * @return mixed
 */
function drush_rmets_crm_get_all_interest_types() {
  $cmd = 'GetAllInterestsTypes';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount");

  try {
    $request = new GetAllInterestsTypesRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllInterestsTypes($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetMemberSubscriptionByID.
 * @return mixed
 */
function drush_rmets_crm_get_member_subscription_by_id() {
  $cmd = 'GetMemberSubscriptionByID';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $subscriptionId = drush_get_option('subscriptionId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, subscriptionId: $subscriptionId");

  try {
    $request = new GetMemberSubscriptionByIdRequest();
    $request->setGuid($guid);
    $request->setSubscriptionId($subscriptionId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getMemberSubscriptionByID($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetMemberSubscriptionJournals.
 * @return mixed
 */
function drush_rmets_crm_get_member_subscription_journals() {
  $cmd = 'GetMemberSubscriptionJournals';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $subscriptionId = drush_get_option('subscriptionId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, subscriptionId: $subscriptionId");

  try {
    $request = new GetMemberSubscriptionJournalsRequest();
    $request->setGuid($guid);
    $request->setSubscriptionId($subscriptionId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getMemberSubscriptionJournals($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetContactDonations.
 * @return mixed
 */
function drush_rmets_crm_get_contact_donations() {
  $cmd = 'GetContactDonations';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $contactId = drush_get_option('contactId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, contactId: $contactId");

  try {
    $request = new GetContactDonationsRequest();
    $request->setGuid($guid);
    $request->setContactId($contactId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getContactDonations($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetContactInterests.
 * @return mixed
 */
function drush_rmets_crm_get_contact_interests() {
  $cmd = 'GetContactInterests';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $contactId = drush_get_option('contactId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount, contactId: $contactId");

  try {
    $request = new GetContactInterestsRequest();
    $request->setGuid($guid);
    $request->setContactId($contactId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getContactInterests($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAllReciprocalOrganisations.
 * @return mixed
 */
function drush_rmets_crm_get_all_reciprocal_organisations() {
  $cmd = 'GetAllReciprocalOrganisations';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount");

  try {
    $request = new GetAllReciprocalOrganisationsRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllReciprocalOrganisations($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAllAwardsCategories.
 * @return mixed
 */
function drush_rmets_crm_get_all_award_categories() {
  $cmd = 'GetAllAwardsCategories';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount");

  try {
    $request = new GetAllAwardsCategoriesRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllAwardsCategories($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAwardsWinners.
 * @return mixed
 */
function drush_rmets_crm_get_award_winners() {
  $cmd = 'GetAwardsWinners';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $awardId = drush_get_option('awardId', 1);
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for awardId: $awardId, page: $page, recordcount: $recordcount");

  try {
    $request = new GetAwardsWinnersRequest();
    $request->setGuid($guid);
    $request->setAwardId($awardId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAwardsWinners($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAllAccreditationCategories.
 * @return mixed
 */
function drush_rmets_crm_get_all_accredditation_categories() {
  $cmd = 'GetAllAccreditationCategories';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount");

  try {
    $request = new GetAllAccreditationCategoriesRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllAccreditationCategories($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAllAccreditatedContacts.
 * @return mixed
 */
function drush_rmets_crm_get_all_accredditated_contacts() {
  $cmd = 'GetAllAccreditatedContacts';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $accreditationId = drush_get_option('accreditationId', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for accreditationId: $accreditationId, page: $page, recordcount: $recordcount");

  try {
    $request = new GetAllAccreditatedContactsRequest();
    $request->setGuid($guid);
    $request->setAccreditationId($accreditationId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllAccreditatedContacts($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}


/**
 * Drush callback to make a request for the API command GetAllFRMetSContacts.
 * @return mixed
 */
function drush_rmets_crm_get_all_frmets_contacts() {
  $cmd = 'GetAllAccreditatedContacts';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount");

  try {
    $request = new GetAllFrmetsContactsRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllFRMetSContacts($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetAllCommittees.
 * @return mixed
 */
function drush_rmets_crm_get_all_committees() {
  $cmd = 'GetAllCommittees';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for page: $page, recordcount: $recordcount");

  try {
    $request = new GetAllCommitteesRequest();
    $request->setGuid($guid);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllCommittees($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command GetContactCommittees.
 * @return mixed
 */
function drush_rmets_crm_get_contact_committees() {
  $cmd = 'GetContactCommittees';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $contactId = drush_get_option('contactId', '');
  $page = drush_get_option('page', 1);
  $recordcount = drush_get_option('recordcount', 100);
  drush_print("process command: $cmd for contactId: $contactId, page: $page, recordcount: $recordcount");

  try {
    $request = new GetContactCommitteesRequest();
    $request->setGuid($guid);
    $request->setContactId($contactId);
    $request->setPage($page);
    $request->setRecordCount($recordcount);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getContactCommittees($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command CreateAccreditationApplication.
 * @return mixed
 */
function drush_rmets_crm_create_accreditation_application() {
  $cmd = 'CreateAccreditationApplication';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $contactId = drush_get_option('contactId', '');
  $accreditationItemId = drush_get_option('accreditationItemId', '');
  $url = drush_get_option('url', '');
  drush_print("process command: $cmd for contactId: $contactId, accreditationItemId: $accreditationItemId, url: $url");

  try {
    $request = new CreateAccreditationApplicationRequest();
    $request->setGuid($guid);
    $request->setContactId($contactId);
    $request->setAccreditationItemId($accreditationItemId);

    if (!empty($url)) {
      $request->setUrl($url);
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->createAccreditationApplication($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command CompleteAccreditationApplication.
 * @return mixed
 */
function drush_rmets_crm_complete_accreditation_application() {
  $cmd = 'CompleteAccreditationApplication';
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  $accreditationApplicationId = drush_get_option('accreditationApplicationId', '');
  drush_print("process command: $cmd for accreditationApplicationId: $accreditationApplicationId");

  try {
    $request = new CompleteAccreditationApplicationRequest();
    $request->setGuid($guid);
    $request->setAccreditationApplicationId($accreditationApplicationId);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->completeAccreditationApplication($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

/**
 * Drush callback to make a request for the API command OptionsetAbstractsTypes.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_abstracts_types() {
  _drush_rmets_crm_get_optionset('OptionsetAbstractsTypes');
}

/**
 * Drush callback to make a request for the API command OptionsetDietaryRequirements.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_dietary_requirements() {
  _drush_rmets_crm_get_optionset('OptionsetDietaryRequirements');
}

/**
 * Drush callback to make a request for the API command OptionsetPreferredContactMethod.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_prefferred_contact_method() {
  _drush_rmets_crm_get_optionset('OptionsetPreferredContactMethod');
}

/**
 * Drush callback to make a request for the API command OptionsetPaymentMethod.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_payment_method() {
  _drush_rmets_crm_get_optionset('OptionsetPaymentMethod');
}

/**
 * Drush callback to make a request for the API command OptionsetPaymentFrequency.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_payment_frequency() {
  _drush_rmets_crm_get_optionset('OptionsetPaymentFrequency');
}

/**
 * Drush callback to make a request for the API command OptionsetSubscriptionPaymentStatus.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_subscription_payment_status() {
  _drush_rmets_crm_get_optionset('OptionsetSubscriptionPaymentStatus');
}

/**
 * Drush callback to make a request for the API command OptionsetSpecialRequirements.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_special_requirements() {
  _drush_rmets_crm_get_optionset('OptionsetSpecialRequirements');
}

/**
 * Drush callback to make a request for the API command OptionsetGender.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_gender() {
  _drush_rmets_crm_get_optionset('OptionsetGender');
}

/**
 * Drush callback to make a request for the API command OptionsetHeardAboutRMetS.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_heard_about_rmets() {
  _drush_rmets_crm_get_optionset('OptionsetHeardAboutRMetS');
}

/**
 * Drush callback to make a request for the API command OptionsetMembershipStatus.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_membership_status() {
  _drush_rmets_crm_get_optionset('OptionsetMembershipStatus');
}

/**
 * Drush callback to make a request for the API command OptionsetEventsTypes.
 * @return mixed
 */
function drush_rmets_crm_get_optionset_events_types() {
  _drush_rmets_crm_get_optionset('OptionsetEventsTypes');
}

/**
 * Callback for handling the Optionset API calls.
 *
 * @param string $optionsetCmd
 */
function _drush_rmets_crm_get_optionset($optionsetCmd) {
  $guid = drush_get_option('guid', variable_get('rmets_crm_api_guid', ''));
  drush_print("process command: $optionsetCmd");
  $cmd = lcfirst($optionsetCmd);

  try {
    $request = new OptionsetRequest();
    $request->setGuid($guid);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->$cmd($request);
    print_r($response);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}
