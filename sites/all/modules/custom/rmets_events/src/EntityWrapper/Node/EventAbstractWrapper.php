<?php

namespace Drupal\rmets_events\EntityWrapper\Node;


use Drupal\rmets_crm\Api\Request\GetEventAbstractsAuthorsRequest;
use Drupal\rmets_crm\Api\Request\GetEventAbstractsSpeakersRequest;
use Drupal\rmets_crm\Api\Request\UpdateAbstractRequest;
use Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper;
use \EntityDrupalWrapper;
use Drupal\rmets_crm\Api\Request\CreateAbstractRequest;
use Drupal\rmets_crm\Api\Request\GetContactByEmailRequest;
use Drupal\rmets_crm\Api\Request\GetEventAbstractRequest;


use \EntityFieldQuery;
use \DateTime;
use Drupal\rmets_crm\Api\Request\GetEventSessionsRequest;


/**
 * Wraps nodes of type firm_profile with additional functionality.
 */
class EventAbstractWrapper extends EntityDrupalWrapper {
  protected $event_id;

  public function __construct($data) {
    parent::__construct('node', $data);
    if (is_numeric($this->field_event->getIdentifier())) {
      $wrapper = entity_metadata_wrapper('node', $this->field_event->getIdentifier());
      $this->event_id = $wrapper->field_event_id->value();
    }
  }

  /**
   * Add or update an abstract in CRM.
   *
   * @throws \Drupal\rmets_crm\Api\ApiServerException
   */
  public function addAbstractToCrm() {
    if ($this->author->getIdentifier()) {
      $account = $this->author->value();
    }
    else {
      global $user;
      $account = $user;
    }
    $user_wrapper = rmets_membership_user_get_user_wrapper($account);
    $user_wrapper->updateFromCrm();

    // Get some info for the event abstract.
    $guid = variable_get('rmets_crm_api_guid', '');
    $eventId = $this->event_id;
    $title = $this->title->value();
    $body = $this->body->value();
    $summary = isset($body['value']) ? $body['value'] : '';
    if (!empty($this->field_event_abstract_theme->getIdentifier())) {
      $theme = $this->field_event_abstract_theme->name->value();
    }
    else {
      $theme = '';
    }
    if (isset($this->field_new_abstract_type)) {
      $type = $this->field_new_abstract_type->value();
    }

    // The main author is the currently logged in user.
    $mainAuthorId = $user_wrapper->getCrmContactId();
    // Get additional authors.
    $additionalAuthors = $this->getAdditionalAuthors();

    // We set everything up to send.
    if ($this->isAbstractUpdate()) {
      $request = new UpdateAbstractRequest();
    }
    else {
      $request = new CreateAbstractRequest();
    }
    $request->setGuid($guid);
    $request->setEventId($eventId);

    if (!empty($mainAuthorId)) {
      $request->setMainAuthorId($mainAuthorId);
    }

    if (!empty($title)) {
      $request->setTitle($title);
    }

    if (!empty($type)) {
      $request->setType($type);
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

    if (!empty($additionalAuthors)) {
      foreach ($additionalAuthors as $additionalAuthor) {
        $request->addContactId($additionalAuthor);
      }
    }
    $api = rmets_crm_get_api();

    if ($this->isAbstractUpdate()) {
      try {
        // If we're updating all is well.
        $request->setAbstractId($this->field_event_abstract_id->value());
        $response = $api->updateAbstract($request);
      } catch (InvalidRequestException $e) {
        drupal_set_message('FATAL: ' . $e->getMessage());
      } catch (ApiServerException $apie) {
        drupal_set_message('FATAL: ' . 'Unable to communicate with the CRM API: ' . $apie->getMessage());
      }
      $this->sendNotifications($user_wrapper, 'update');
    }
    else {
      try {
        // Otherwise we need to save the abstract id
        // back to the node.
        /** @var \Drupal\rmets_crm\Api\CrmService $api */
        $response = $api->createAbstract($request);
        $this->field_event_abstract_id = $response->getId();
      } catch (InvalidRequestException $e) {
        drupal_set_message('FATAL: ' . $e->getMessage(), 'error');
      } catch (ApiServerException $apie) {
        drupal_set_message('FATAL: ' . 'Unable to communicate with the CRM API: ' . $apie->getMessage(), 'error');
      }
      $this->sendNotifications($user_wrapper, 'create');
    }
  }

  /**
   * Used by addAbstractToCrm() to send emails.
   *
   * @param $user_wrapper
   * @param $type
   */
  function sendNotifications($user_wrapper, $type) {
    // @todo : this
    $body = 'Thank you for submitting your abstract for ' . check_plain($this->field_event->title->value()) . ', the Programme Organising Committee will contact you once the abstracts have been reviewed.';
    $subject = 'Thank you for your abstract submission';
    drupal_mail('rmets_events', 'rmets_events_' . $type, $user_wrapper->getEmail(), LANGUAGE_NONE, array('subject' => $subject, 'body' => $body));

    $body = 'An abstract has been submitted for ' . check_plain($this->field_event->title->value()) . '.
You can find it here: ' . url('node/' . $this->getIdentifier(), array('absolute' => TRUE));
    $subject = 'Thank you for your abstract';
    drupal_mail('rmets_events', 'rmets_events_' . $type, "administrator@rmets.org, conferences@rmets.org", LANGUAGE_NONE, array('subject' => $subject, 'body' => $body));
    drupal_set_message('Thank you for submitting your abstract the Programme Organising Committee will contact you once the abstracts have been reviewed.');
  }

  /**
   * Whether or nor we are updating an abstract.
   *
   * @return bool
   */
  public function isAbstractUpdate() {
    return (!empty($this->field_event_abstract_id->value())) ? TRUE : FALSE;
  }

  /**
   * Get additional authors when creating or updating an abstract.
   *
   * @return array
   */
  protected function getAdditionalAuthors() {
    $additionalAuthors = array();
    // Additional authors faff begins.
    $abstract_authors = $this->field_fc_abstract_authors->value();
    foreach ($abstract_authors AS $id => $abstract_author) {
      $fc_wrapper = entity_metadata_wrapper('field_collection_item', $abstract_author);
      if (empty($fc_wrapper->field_author_surname->value()) && empty($fc_wrapper->field_author_first_name->value())) {
        continue;
      }

      // Try to get the email.
      $email = $fc_wrapper->field_author_email_address->value();

      // If we can't use the default name.surname.timestamp@rmetstest.org.uk
      if (empty($email)) {
        $email = $fc_wrapper->field_author_first_name->value() . '.' . $fc_wrapper->field_author_surname->value() . '.' . time() . '@noemail.rms';
      }

      // Either they have an account, or we make them a wrapperable thing.
      if (!$account = user_load_by_mail($email)) {
        $account = UserWrapper::createNewUserAccount($email);
      }

      // Try to find them in CRM.
      $member = new UserWrapper($account);
      $member->updateFromCrm();
      if (!$member->getCrmContactId()) {
        // If we can't make them a minimal profile.
        $member->setForename($fc_wrapper->field_author_first_name->value());
        $member->setSurname($fc_wrapper->field_author_surname->value());
        $org = $fc_wrapper->field_author_company_name->value();
        if (!empty($org)) {
          $member->setOrganisationName($org);
        }
        $title = $fc_wrapper->field_author_title->value();
        if (!empty($title)) {
          $member->setTitle($title);
        }
        $member->setGiftAid(1);
        $member->setMarketingMaterials(1);
        $member->updateCrmContactNoDrupalSave();
        $post_nominals = $fc_wrapper->field_author_post_nominals->value();
        if (empty($post_nominals)) {
          $member->updateContactSuffixes($post_nominals);
        }
      }

      $contact_id = $member->getCrmContactId();
      if (!empty($contact_id)) {
        $additionalAuthors[] = $contact_id;
      }
      else {
        drupal_set_message('An additional author was not saved', 'error');
      }
    }
    return $additionalAuthors;
  }

  /**
   * Change some fields in the wrapper.
   *
   * This is used when preparing the node edit form.
   */
  public function updateAbstractFromCRM() {
    $crm_abstract = $this->getAbstractFromCRM();
    if (empty($crm_abstract)) {
      return;
    }
    $abstract = $crm_abstract->getIterator()->current();

    $this->title = $abstract->getTitle();
    $this->body->set(array('value' => $abstract->getSummary()));
    $this->field_presentation_number_2 = $abstract->getNumber();
    $this->field_new_abstract_type = $abstract->getType();
  }

  /**
   * Get the abstract from CRM. Used to update Drupal.
   *
   * @return bool|\Drupal\rmets_crm\Api\Response\EventAbstractResponse
   * @throws \Drupal\rmets_crm\Api\ApiServerException
   */
  public function getAbstractFromCRM() {
    $abstract_id = $this->field_event_abstract_id->value();
    if (empty($abstract_id)) {
      return FALSE;
    }
    try {
      $request = new GetEventAbstractRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setAbstractId($abstract_id);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getEventAbstract($request);
      return $response;
    } catch (InvalidRequestException $e) {
      print drush_set_error('FATAL', $e->getMessage());
    } catch (ApiServerException $apie) {
      print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
    }
  }

  public static function getAbstractSpeakersFromCRM($abstractId) {
    try {
      $request = new GetEventAbstractsSpeakersRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setAbstractId($abstractId);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getEventAbstractsSpeakers($request);
      return $response;
    } catch (InvalidRequestException $e) {
      print drush_set_error('FATAL', $e->getMessage());
    } catch (ApiServerException $apie) {
      print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
    }
  }

  public static function getAbstractAuthorsFromCRM($abstractId) {
    try {
      $request = new GetEventAbstractsAuthorsRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setAbstractId($abstractId);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getEventAbstractsAuthors($request);
      return $response;
    } catch (InvalidRequestException $e) {
      print drush_set_error('FATAL', $e->getMessage());
    } catch (ApiServerException $apie) {
      print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
    }
  }
}
