<?php
/**
 * @file
 * MS Dydamics API service wrapper.
 */

namespace Drupal\rmets_crm\Api;

use Drupal\rmets_crm\Api\Driver\DriverInterface;
use Drupal\rmets_crm\Api\Request\CreateEventRegistrationRequest;
use Drupal\rmets_crm\Api\Request\GetAllContactsRequest;
use Drupal\rmets_crm\Api\Request\GetContactByEmailRequest;
use Drupal\rmets_crm\Api\Request\GetContactByIdRequest;
use Drupal\rmets_crm\Api\Request\GetAllMembershipPackagePricesRequest;
use Drupal\rmets_crm\Api\Request\GetAllUnpaidSubscriptionPaymentsRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipPackageAccreditationsRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipPackageJournalsRequest;
use Drupal\rmets_crm\Api\Request\CreateContactSubscriptionRequest;
use Drupal\rmets_crm\Api\Request\ContactRequest;
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
use Drupal\rmets_crm\Api\Request\GetMemberSubscriptionJournalsRequest;
use Drupal\rmets_crm\Api\Request\GetMemberUnpaidSubscriptionPaymentsRequest;
use Drupal\rmets_crm\Api\Request\RemoveMemberSubscriptionJournalsRequest;
use Drupal\rmets_crm\Api\Request\AddMemberSubscriptionJournalsRequest;
use Drupal\rmets_crm\Api\Request\GetContactDonationsRequest;
use Drupal\rmets_crm\Api\Request\MarkSubscriptionPaymentsAsPaidRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipPackagePricesByIdRequest;
use Drupal\rmets_crm\Api\Request\GetMembershipAccreditationItemByIdRequest;
use Drupal\rmets_crm\Api\Request\GetAllReciprocalOrganisationsRequest;
use Drupal\rmets_crm\Api\Request\GetAllAccreditationCategoriesRequest;
use Drupal\rmets_crm\Api\Request\GetAllAccreditatedContactsRequest;
use Drupal\rmets_crm\Api\Request\GetAllAwardsCategoriesRequest;
use Drupal\rmets_crm\Api\Request\GetAwardsWinnersRequest;
use Drupal\rmets_crm\Api\Request\CreateAbstractRequest;
use Drupal\rmets_crm\Api\Request\UpdateAbstractRequest;
use Drupal\rmets_crm\Api\Request\GetAllCommitteesRequest;
use Drupal\rmets_crm\Api\Request\GetContactCommitteesRequest;
use Drupal\rmets_crm\Api\Request\CreateAccreditationApplicationRequest;
use Drupal\rmets_crm\Api\Request\CompleteAccreditationApplicationRequest;
use Drupal\rmets_crm\Api\Request\GetAllFrmetsContactsRequest;
use Drupal\rmets_crm\Api\Request\GetAllSuffixesRequest;
use Drupal\rmets_crm\Api\Request\OptionsetRequest;
use Drupal\rmets_crm\Api\Request\UpdateContactSuffixesRequest;
use Drupal\rmets_crm\Api\Response\BaseResponse;
use Drupal\rmets_crm\Api\Response\ContactsResponse;
use Drupal\rmets_crm\Api\Response\MembershipPackagePricesResponse;
use Drupal\rmets_crm\Api\Response\AccreditationItemResponse;
use Drupal\rmets_crm\Api\Response\PaymentScheduleResponse;
use Drupal\rmets_crm\Api\Response\JournalItemResponse;
use Drupal\rmets_crm\Api\Response\EventResponse;
use Drupal\rmets_crm\Api\Response\EventRegistrationFeesResponse;
use Drupal\rmets_crm\Api\Response\EventRegistrationFeesOptionalsResponse;
use Drupal\rmets_crm\Api\Response\EventSessionResponse;
use Drupal\rmets_crm\Api\Response\EventSessionItemResponse;
use Drupal\rmets_crm\Api\Response\EventSpeakerResponse;
use Drupal\rmets_crm\Api\Response\EventAbstractResponse;
use Drupal\rmets_crm\Api\Response\EventThemeResponse;
use Drupal\rmets_crm\Api\Response\JournalSubscriptionItemResponse;
use Drupal\rmets_crm\Api\Response\SubscriptionResponse;
use Drupal\rmets_crm\Api\Response\InterestTypesResponse;
use Drupal\rmets_crm\Api\Response\DonationResponse;
use Drupal\rmets_crm\Api\Response\AccountResponse;
use Drupal\rmets_crm\Api\Response\AccreditationResponse;
use Drupal\rmets_crm\Api\Response\AccreditatedContactsResponse;
use Drupal\rmets_crm\Api\Response\AwardCategoryResponse;
use Drupal\rmets_crm\Api\Response\AwardWinnerResponse;
use Drupal\rmets_crm\Api\Response\FrmetsContactsResponse;
use Drupal\rmets_crm\Api\Response\GroupResponse;
use Drupal\rmets_crm\Api\Response\OptionsetResponse;
use Drupal\rmets_crm\Api\Response\SuffixResponse;

use WSIFInterface;

/**
 * This class provides access to the various API functions.
 */
class CrmService implements WSIFInterface {

  const API_VERSION = 'v.1.0.0';
  const WSIF_API_NAME = 'rmets_crm';

  protected $driver;
  protected $endpointUrl;

  public function __construct(DriverInterface $driver) {
    $this->driver = $driver;
  }

  public function getDriver() {
    return $this->driver;
  }

  /** HTTP GET callbacks. */

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllContactsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\ContactsResponse
   */
  public function getAllContacts(GetAllContactsRequest $request) {
    return new ContactsResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetContactByEmailRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\ContactsResponse
   */
  public function getContactByEmail(GetContactByEmailRequest $request) {
    return new ContactsResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetContactByIdRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\ContactsResponse
   */
  public function getContactById(GetContactByIdRequest $request) {
    return new ContactsResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllMembershipPackagePricesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\MembershipPackagePricesResponse
   */
  public function getAllMembershipPackagePrices(GetAllMembershipPackagePricesRequest $request) {
    return new MembershipPackagePricesResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetMembershipPackagePricesByIdRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\MembershipPackagePricesResponse
   */
  public function getMembershipPackagePricesById(GetMembershipPackagePricesByIdRequest $request) {
    return new MembershipPackagePricesResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetMembershipAccreditationItemByIdRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\AccreditationItemResponse
   */
  public function getMembershipAccreditationItemById(GetMembershipAccreditationItemByIdRequest $request) {
    return new AccreditationItemResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetMembershipPackageJournalsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\JournalItemResponse
   */
  public function getMembershipPackageJournals(GetMembershipPackageJournalsRequest $request) {
    return new JournalItemResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllEventsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventResponse
   */
  public function getAllEvents(GetAllEventsRequest $request) {
    return new EventResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllSuffixesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\SuffixResponse
   */
  public function getAllSuffixes(GetAllSuffixesRequest $request) {
    return new SuffixResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventRegistrationFeesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventResponse
   */
  public function getEventRegistrationFees(GetEventRegistrationFeesRequest $request) {
    return new EventRegistrationFeesResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventRegistrationFeesOptionalsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventResponse
   */
  public function getEventRegistrationFeesOptionals(GetEventRegistrationFeesOptionalsRequest $request) {
    return new EventRegistrationFeesOptionalsResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventSessionsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventResponse
   */
  public function getEventSessions(GetEventSessionsRequest $request) {
    return new EventSessionResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventSessionItemsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventSessionItemResponse
   */
  public function getEventSessionItems(GetEventSessionItemsRequest $request) {
    return new EventSessionItemResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventSpeakersRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventSpeakerResponse
   */
  public function getEventSpeakers(GetEventSpeakersRequest $request) {
    return new EventSpeakerResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventAbstractRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventAbstractResponse
   */
  public function getEventAbstract(GetEventAbstractRequest $request) {
    return new EventAbstractResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventAbstractsAuthorsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventSpeakerResponse
   */
  public function GetEventAbstractsAuthors(GetEventAbstractsAuthorsRequest $request) {
    return new EventSpeakerResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventAbstractsSpeakersRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventSpeakerResponse
   */
  public function getEventAbstractsSpeakers(GetEventAbstractsSpeakersRequest $request) {
    return new EventSpeakerResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetEventThemesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventThemeResponse
   */
  public function getEventThemes(GetEventThemesRequest $request) {
    return new EventThemeResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllUnpaidSubscriptionPaymentsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\PaymentScheduleResponse
   */
  public function getAllUnpaidSubscriptionPayments(GetAllUnpaidSubscriptionPaymentsRequest $request) {
    return new PaymentScheduleResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetMemberUnpaidSubscriptionPaymentsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\PaymentScheduleResponse
   */
  public function getMemberUnpaidSubscriptionPayments(GetMemberUnpaidSubscriptionPaymentsRequest $request) {
    return new PaymentScheduleResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetMembershipPackageAccreditationsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\AccreditationItemResponse
   */
  public function getMembershipPackageAccreditations(GetMembershipPackageAccreditationsRequest $request) {
    return new AccreditationItemResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllInterestsTypesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\InterestTypesResponse
   */
  public function getAllInterestsTypes(GetAllInterestsTypesRequest $request) {
    return new InterestTypesResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetContactInterestsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\InterestTypesResponse
   */
  public function getContactInterests(GetContactInterestsRequest $request) {
    return new InterestTypesResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetMemberSubscriptionByIdRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\SubscriptionResponse
   */
  public function getMemberSubscriptionByID(GetMemberSubscriptionByIdRequest $request) {
    return new SubscriptionResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetMemberSubscriptionJournalsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\JournalSubscriptionItemResponse
   */
  public function getMemberSubscriptionJournals(GetMemberSubscriptionJournalsRequest $request) {
    return new JournalSubscriptionItemResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetContactDonationsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\DonationResponse
   */
  public function getContactDonations(GetContactDonationsRequest $request) {
    return new DonationResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllReciprocalOrganisationsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\AccountResponse
   */
  public function getAllReciprocalOrganisations(GetAllReciprocalOrganisationsRequest $request) {
    return new AccountResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllAwardsCategoriesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\AccountResponse
   */
  public function getAllAwardsCategories(GetAllAwardsCategoriesRequest $request) {
    return new AwardCategoryResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAwardsWinnersRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\AwardWinnerResponse
   */
  public function getAwardsWinners(GetAwardsWinnersRequest $request) {
    return new AwardWinnerResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllAccreditationCategoriesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\AccreditationResponse
   */
  public function getAllAccreditationCategories(GetAllAccreditationCategoriesRequest $request) {
    return new AccreditationResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllAccreditatedContactsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\AccreditatedContactsResponse
   */
  public function getAllAccreditatedContacts(GetAllAccreditatedContactsRequest $request) {
    return new AccreditatedContactsResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllFrmetsContactsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\FrmetsContactsResponse
   */
  public function getAllFRMetSContacts(GetAllFrmetsContactsRequest $request) {
    return new FrmetsContactsResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetAllCommitteesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\GroupResponse
   */
  public function getAllCommittees(GetAllCommitteesRequest $request) {
    return new GroupResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\GetContactCommitteesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\GroupResponse
   */
  public function getContactCommittees(GetContactCommitteesRequest $request) {
    return new GroupResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /** HTTP POST callbacks. */

  /**
   * @param \Drupal\rmets_crm\Api\Request\ContactRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\ContactsResponse
   */
  public function createContact(ContactRequest $request) {
    return new ContactsResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\ContactRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\ContactsResponse
   */
  public function updateContact(ContactRequest $request) {
    return new ContactsResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\CreateContactSubscriptionRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function createContactSubscription(CreateContactSubscriptionRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\RemoveMemberSubscriptionJournalsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function removeMemberSubscriptionJournals(RemoveMemberSubscriptionJournalsRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\AddMemberSubscriptionJournalsRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function addMemberSubscriptionJournals(AddMemberSubscriptionJournalsRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\MarkSubscriptionPaymentsAsPaidRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function markSubscriptionPaymentsAsPaid(MarkSubscriptionPaymentsAsPaidRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\CreateAbstractRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function createAbstract(CreateAbstractRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\UpdateAbstractRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function updateAbstract(UpdateAbstractRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\UpdateContactSuffixesRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function updateContactSuffixes(UpdateContactSuffixesRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\CreateAccreditationApplicationRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function createAccreditationApplication(CreateAccreditationApplicationRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\CompleteAccreditationApplicationRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\BaseResponse
   */
  public function completeAccreditationApplication(CompleteAccreditationApplicationRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\CreateEventRegistrationRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\EventResponse
   */
  public function createEventRegistration(CreateEventRegistrationRequest $request) {
    return new BaseResponse($this->getDriver()->post(__FUNCTION__, $request));
  }

  /** Optionset callbacks. */

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetPreferredContactMethod(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetPaymentMethod(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetPaymentFrequency(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetSubscriptionPaymentStatus(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetGender(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetHeardAboutRMetS(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetMembershipStatus(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetAbstractsTypes(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetDietaryRequirements(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetSpecialRequirements(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetContactSuffixes(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * @param \Drupal\rmets_crm\Api\Request\OptionsetRequest $request
   *
   * @return \Drupal\rmets_crm\Api\Response\OptionsetResponse
   */
  public function optionsetEventsTypes(OptionsetRequest $request) {
    return new OptionsetResponse($this->getDriver()->get(__FUNCTION__, $request));
  }

  /**
   * Check the connection to the api.
   *
   * @return bool
   *   FALSE if the connection failed, otherwise the service is assumed to be
   *   up. If this function throws a WSIFUnavailableException then FALSE is also
   *   assumed.
   *
   * @see wsif_cron()
   */
  public function wsifCheckConnection() {
    try {
      $request = new OptionsetRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $api->optionsetGender($request);
      return TRUE;
    }
    catch (\WSIFUnavailableException $e) {
      watchdog_exception('CRM', $e);
    }

    // We've been unable to receive data.
    return FALSE;
  }

  /**
   * Provide the current version of your API here.
   *
   * @return string
   *   Version information.
   */
  public function wsifGetVersion() {
    return self::API_VERSION;
  }

}
