<?php

/**
 * @file
 */

$plugin = array(
  'title' => t('Event Abstract Sub Session selection'),
  'class' => 'EntityReference_SelectionHandler_EventSubSession',
);

/**
 * A generic Entity handler.
 *
 * The generic base implementation has a variety of overrides to workaround
 * core's largely deficient entity handling.
 */
class EntityReference_SelectionHandler_EventSubSession extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new EntityReference_SelectionHandler_EventSubSession($field, $instance);
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    return array();
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    // We want to list sub sessions for the current event only.
    // The event can be specified either via the $_GET['field_event']
    // superglobal or by checking the field_event connected to the
    // current node.
    $event = NULL;
    if (isset($_GET['field_event']) && is_numeric($_GET['field_event'])) {
      $event = node_load($_GET['field_event']);
      if (!empty($event) && isset($event->type) && $event->type != 'event') {
        $event = NULL;
      }
    }

    if (empty($event)) {
      try {
        $abstract = menu_get_object();
        $event = entity_metadata_wrapper('node', $abstract)->field_event->value();
      }
      catch (Exception $e) {
        watchdog_exception('event_map', $e);
      }
    }

    if (empty($event)) {
      // Finally try and get the event from the session.
      // This is required as some functions will be making
      // this call without any session reference.
      if (isset($_SESSION['field_event']) && is_numeric($_SESSION['field_event'])) {
        $event = node_load($_SESSION['field_event']);
        if (!empty($event) && isset($event->type) && $event->type != 'event') {
          $event = NULL;
        }
      }
    }

    if (!empty($event)) {
      // Save the current event in the session.
      $_SESSION['field_event'] = $event->nid;
    }

    $sessions = array();

    if (!empty($event)) {
      $session_query = new EntityFieldQuery();
      $result = $session_query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'event_session')
        ->fieldCondition('field_event', 'target_id', $event->nid, '=')
        ->execute();

      if (!empty($result['node'])) {
        $sessions = array_keys($result['node']);
      }
    }

    $options = array();

    if ($sessions) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'event_subsession');

      if (!empty($sessions)) {
        $query->fieldCondition('field_event_session', 'target_id', $sessions, 'IN');
      }

      $query->addMetaData('field', $this->field);

      if ($limit > 0) {
        $query->range(0, $limit);
      }

      $results = $query->execute();

      if (!empty($results['node'])) {
        $entities = entity_load('node', array_keys($results['node']));
        foreach ($entities as $entity_id => $entity) {
          $options[$entity_id] = $this->getLabel($entity);
        }
      }
    }

    return $options;
  }

  /**
   * Implements EntityReferenceHandler::countReferencableEntities().
   */
  public function countReferencableEntities($match = NULL, $match_operator = 'CONTAINS') {
    $results = $this->getReferencableEntities($match, $match_operator);
    return count($results);
  }

}
