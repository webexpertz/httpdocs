<?php

namespace Drupal\rmets_events\EntityWrapper\Node;


use Drupal\rmets_crm\Api\ApiServerException;
use Drupal\rmets_crm\Api\Request\GetEventSessionItemsRequest;
use Drupal\rmets_crm\Api\Request\GetEventSpeakersRequest;
use Drupal\rmets_crm\Api\Request\InvalidRequestException;
use Drupal\rmets_crm\Model\Event;
use \EntityDrupalWrapper;
use \EntityFieldQuery;
use \DateTime;
use Drupal\rmets_crm\Api\Request\GetEventSessionsRequest;
use Drupal\rmets_crm\Api\Request\GetEventThemesRequest;
use Drupal\rmets_crm\Api\Request\OptionsetRequest;
use Drupal\rmets_crm\Api\Request\GetEventRegistrationFeesRequest;
use Drupal\rmets_crm\Api\Request\GetEventRegistrationFeesOptionalsRequest;



/**
 * Wraps nodes of type firm_profile with additional functionality.
 */
class EventWrapper extends EntityDrupalWrapper {

  protected $event_id;
  protected $crm_event_sessions = array();

  /**
   * @var Event
   */
  protected $crm_event;

  public function __construct($data, $crm_event = NULL) {
    parent::__construct('node', $data);

    if ($crm_event) {
      $this->event_id = $crm_event->getEventId();
    }
    else {
      $this->event_id = $this->field_event_id->value();
    }

    $this->crm_event_sessions = '';
    if (!empty($this->event_id)) {
      try {
        $this->crm_event_sessions = $this->getEventSessionsFromCrm();
      }
      catch (\Exception $e) {
      }
      $this->crm_event = $crm_event;
    }
  }

  /**
   * @return mixed
   */
  public function getEventId() {
    return $this->event_id;
  }

  /**
   * @return mixed
   */
  public function getCrmEventSessions() {
    return $this->crm_event_sessions;
  }

  public function updateEventFromCrm() {
    if (empty($this->crm_event)) {
      return FALSE;
    }
    // Set some values we need.
    $this->title = $this->crm_event->getTitle();
    $this->field_summary_location->set(array('value' => $this->crm_event->getVenueName() . "\n" . $this->crm_event->getVenueAddress()));
    $this->field_event_email->set(array('value' => $this->crm_event->getRMetSContactEmail()));
    $this->field_event_id =  $this->crm_event->getEventId();

    // Only set the summary when creating this event.
    //if (empty($this->body->value())) {
      $this->body->set(array(
        'value' => '<p>' . str_replace("\n", '<br/>', $this->crm_event->getSummary()) . '</p>',
        'format' => 'full_html',
        ));
    //}

    $crmEventType = $this->crm_event->getEventType();
    $eventTypeTids = $this->getEventTypeTaxonomy($crmEventType);
    if (!empty($eventTypeTids)) {
      $this->field_event_type->set($eventTypeTids);
    }

    //$theme_name = $this->crm_event->getTheme();
    $themes = $this->getCrmEventThemes();
    $theme_terms = array();
    foreach ($themes AS $theme) {
      $theme_name = $theme->getName();
      if (!empty($theme_name)) {
        $theme_term = taxonomy_get_term_by_name($theme_name, 'event_themes');
        if (empty($theme_term)) {
          $vocab = taxonomy_vocabulary_machine_name_load('event_themes');
          $theme_term = new \stdClass();
          $theme_term->name = $theme_name;
          $theme_term->vid = $vocab->vid;
          taxonomy_term_save($theme_term);
        }
        else {
          $theme_term = current($theme_term);
        }
        $theme_terms[] = $theme_term->tid;
      }
    }
    $this->field_themes = $theme_terms;


    $groupnames = taxonomy_get_term_by_name($this->crm_event->getGroupName(), 'event_type');
    $groupname = reset($groupnames);
    if (isset($groupname->tid) && is_numeric($groupname->tid)) {
      $this->field_event_type = array($groupname->tid);
    }


    $unix_start = $unix_end = NULL;
    if (!empty($this->crm_event->getStartDate())) {
      $unix_start = \DateTime::createFromFormat('!d/m/Y H:i:s', $this->crm_event->getStartDate())
        ->getTimestamp();
    }
    if (!empty($this->crm_event->getEndDate())) {
      $unix_end = \DateTime::createFromFormat('!d/m/Y H:i:s', $this->crm_event->getEndDate())
        ->getTimestamp();
    }
    $this->field_event_date->set(
      array(
        'value' => $unix_start,
        'value2' => $unix_end,
      )
    );

    // Update field collections from CRM
    $crm_event_session_ids = $this->updateEventSessions();
    $this->save();

    $this->deleteEventSessionsNoLongerFoundInCrm($crm_event_session_ids);
  }

  protected function getEventTypeTaxonomy($eventType) {
    $query = db_select('field_data_field_crm_event_type', 'et');
    $query->join('taxonomy_term_data', 'term', 'term.tid = et.entity_id');
    $query->fields('term', array('tid'))
      ->condition('et.bundle', 'event_type')
      ->condition('et.field_crm_event_type_value', $eventType);

    $result = $query->execute();

    if (empty($result)) {
      return NULL;
    }

    $tids = array();
    foreach ($result as $record) {
      $tids[] = $record->tid;
    }

    return $tids;
  }

  public function updateEventSessions() {
    $crm_event_session_ids = array();
    foreach ($this->crm_event_sessions AS $session) {
      $crm_event_session_ids[$session->getSessionID()] = $session->getSessionID();
      $query = new \EntityFieldQuery();
      $query->entityCondition("entity_type", "field_collection_item");
      $query->propertyCondition("field_name", "field_sessions");
      $query->fieldCondition("field_session_id", "value", $session->getSessionID());
      $result = $query->execute();

      if (!empty($result['field_collection_item'])) {
        foreach ($result['field_collection_item'] AS $nid => $nid) {
          $collections = entity_load('field_collection_item', array_keys($result['field_collection_item']));
        }
        if (!empty($collections)) {
          $collection = current($collections);
        }
      }
      else {
        $collection = entity_create('field_collection_item', array('field_name' => 'field_sessions'));
        $collection->setHostEntity('node', $this->value());
      }

      $fc_wrapper = entity_metadata_wrapper('field_collection_item', $collection);
      $fc_wrapper->field_session_id = $session->getSessionID();
      $fc_wrapper->field_session_name = $session->getName();

      $unix_start = $unix_end = NULL;
      if (!empty($session->getStartDate())) {
        $unix_start = \DateTime::createFromFormat('!d/m/Y H:i:s', $session->getStartDate())
          ->getTimestamp();
      }
      if (!empty($session->getEndDate())) {
        $unix_end = \DateTime::createFromFormat('!d/m/Y H:i:s', $session->getEndDate())
          ->getTimestamp();
      }
      $fc_wrapper->field_session_date->set(
        array(
          'value' => $unix_start,
          'value2' => $unix_end,
        )
      );
      $fc_wrapper->field_session_room = $session->getRoom();
      $fc_wrapper->field_session_capacity = $session->getCapacity();
      $fc_wrapper->save();
    }
    return $crm_event_session_ids;
  }

  public function deleteEventSessionsNoLongerFoundInCrm($crm_event_session_ids) {
    $drupal_event_session_ids = array();

    foreach ($this->field_sessions AS $id => $drupal_session) {
      $drupal_event_session_ids[$drupal_session->field_session_id->value()] = $id;
    }
    if (!empty($drupal_event_session_ids) && !empty($crm_event_session_ids)) {
      $delete_fc_from_drupal = array_diff_key($drupal_event_session_ids, $crm_event_session_ids);
      if (!empty($delete_fc_from_drupal)) {
        foreach ($delete_fc_from_drupal AS $crm_session_id => $delete_id) {
          $field_collection_to_delete = entity_load('field_collection_item', array($this->field_sessions[$delete_id]->getIdentifier()));
          if (is_array($field_collection_to_delete)) {
            $field_collection_to_delete = current($field_collection_to_delete);
            $field_collection_to_delete->delete();
          }
        }
      }
    }
  }

  /**
   * @return \Drupal\rmets_crm\Api\Response\EventResponse
   */
  public function getEventSessionsFromCrm() {
    try {
      $request = new GetEventSessionsRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setEventId($this->event_id);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      return $api->getEventSessions($request);
    }
    catch (InvalidRequestException $e) {
      drupal_set_message('FATAL: ' . $e->getMessage(), 'error');
    }
    catch (ApiServerException $apie) {
      drupal_set_message('FATAL: Unable to communicate with the CRM API: ' . $apie->getMessage(), 'error');
    }
  }

  /**
   * @return \Drupal\rmets_crm\Api\Response\EventSessionItemResponse
   * @throws \Drupal\rmets_crm\Api\ApiServerException
   */
  public function getCrmEventSessionItems() {
    try {
      $request = new GetEventSessionItemsRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setEventId($this->event_id);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      return $api->getEventSessionItems($request);
    }
    catch (InvalidRequestException $e) {
      drupal_set_message('FATAL: ' . $e->getMessage(), 'error');
    }
    catch (ApiServerException $apie) {
      drupal_set_message('FATAL: Unable to communicate with the CRM API: ' . $apie->getMessage(), 'error');
    }
  }

  /**
   * @return \Drupal\rmets_crm\Api\Response\EventSessionItemResponse
   */
  public function getCrmEventSpeakers() {
    try {
      $request = new GetEventSpeakersRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setEventId($this->event_id);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      return $api->getEventSpeakers($request);
    }
    catch (InvalidRequestException $e) {
      drupal_set_message('FATAL: ' . $e->getMessage(), 'error');
    }
    catch (ApiServerException $apie) {
      drupal_set_message('FATAL: Unable to communicate with the CRM API: ' . $apie->getMessage(), 'error');
    }
  }

  public function getCrmEventThemes() {
    try {
      $request = new GetEventThemesRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setEventId($this->event_id);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      return $api->getEventThemes($request);
    }
    catch (InvalidRequestException $e) {
      drupal_set_message('FATAL: ' . $e->getMessage(), 'error');
    }
    catch (ApiServerException $apie) {
      drupal_set_message('FATAL: Unable to communicate with the CRM API: ' . $apie->getMessage(), 'error');
    }
  }

  public function getEventRegistrationFeesOptionals() {
    try {
      $request = new GetEventRegistrationFeesOptionalsRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setEventId($this->event_id);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getEventRegistrationFeesOptionals($request);
      return $response;
    }
    catch (InvalidRequestException $e) {
      drupal_set_message('FATAL', $e->getMessage());
    }
    catch (ApiServerException $apie) {
      drupal_set_message('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
    }
  }

  public function getEventRegistrationFees() {
    try {
      $request = new GetEventRegistrationFeesRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));
      $request->setPage(1);
      $request->setRecordCount(100);
      $request->setEventId($this->event_id);

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->getEventRegistrationFees($request);
      return $response;
    }
    catch (InvalidRequestException $e) {
      drupal_set_message('FATAL', $e->getMessage());
    }
    catch (ApiServerException $apie) {
      drupal_set_message('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
    }
  }

  public function getDietaryOptions() {
    return $this->getOptions('optionsetDietaryRequirements');
  }

  public function getSpecialOptions() {
    return $this->getOptions('optionsetSpecialRequirements');
  }

  public function getOptions($cmd) {
    try {
      $request = new OptionsetRequest();
      $request->setGuid(variable_get('rmets_crm_api_guid', ''));

      /** @var \Drupal\rmets_crm\Api\CrmService $api */
      $api = rmets_crm_get_api();
      $response = $api->$cmd($request);
      $option = array('', ' - select - ');
      foreach ($response AS $r) {
        $option[$r->getValue()] = $r->getValue();
      }
      return $option;
    }
    catch (InvalidRequestException $e) {
      drupal_set_message('FATAL', $e->getMessage());
    }
    catch (ApiServerException $apie) {
      drupal_set_message('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
    }
  }

  /**
   * Get the event by the CRM event id.
   *
   * @param string $crmEventId
   *   The CRM event id.
   *
   * @return \Drupal\rmets_events\EntityWrapper\Node\EventWrapper|null
   */
  public static function getEventByCrmId($crmEventId) {
    $query = new \EntityFieldQuery();
    $query->entityCondition("entity_type", "node");
    $query->fieldCondition("field_event_id", "value", $crmEventId);
    $result = $query->execute();

    if (empty($result)) {
      return NULL;
    }

    $nid = array_keys($result['node']);
    $node = node_load($nid[0]);
    return new EventWrapper($node);
  }

  /**
   * Get an instance of the node.
   *
   * @param $data
   *   Node id or loaded node object.
   *
   * @return \Drupal\rmets_events\EntityWrapper\Node\EventWrapper
   */
  public static function GetObject($data) {
    return new EventWrapper($data);
  }

}
