<?php

/**
 * @file
 */

/**
 * Implements hook_view_pre_render().
 */
function rmets_committee_document_views_pre_render(&$view) {
  if ($view->name == 'committee_meetings') {
    // Add a create new meeting form to the list of meetings.
    global $user;
    $breadcrumb = drupal_get_breadcrumb();
    $breadcrumb[] = l(t('Committees'), 'committee-papers');

    $argument = $view->argument['tid'];
    $tid = isset($argument->value) && isset($argument->value[0]) && is_numeric($argument->value[0]) ? $argument->value[0] : FALSE;

    if ($tid && (user_access('administer committee meetings'))) {
      // Add a create new meeting form.
      $view->attachment_before = drupal_render(drupal_get_form('rmets_committee_document_create_form', $tid));
      // $breadcrumb[] = t('@committee Meetings', array('@committee' => taxonomy_term_load($tid)->name));
    }

    ctools_add_js('rmets_committee_document', 'rmets_committee_document');
    drupal_set_breadcrumb($breadcrumb);
  }
  elseif ($view->name == 'committee_meeting_papers') {
    // Add a link to add a document to the top of the list of papers
    // for a meeting.
    global $user;
    $argument = $view->argument['field_meeting_reference_target_id'];
    $nid = isset($argument->value) && isset($argument->value[0]) && is_numeric($argument->value[0]) ? $argument->value[0] : FALSE;
    $node = node_load($nid);
    if ($nid) {
      $node_wrapper = entity_metadata_wrapper('node', node_load($nid));
      if (user_access('administer committee meetings')) {
        $view->attachment_before = l(t('Upload a new document'), 'node/add/committee-document', array('query' => drupal_get_destination() + array('field_meeting_reference' => $nid)));
      }
    }
  }
  elseif ($view->name == 'committees') {
    global $user;
    if (!_rmets_committee_document_user_can_access_committees($user)) {
      unset($view->result);
      $view->attachment_before = t('This area is for Royal Meteorological Society committee members only.'); 
    }
  }
}

/**
 * Drupal form.
 */
function rmets_committee_document_create_form($form, $form_state) {
  $tid = $form_state['build_info']['args'][0];

  $form = array();

  $form['meeting_date'] = array(
    '#type' => 'date',
    '#title' => t('Date of meeting'),
  );

  $form['committee'] = array(
    '#type' => 'value',
    '#value' => $tid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create new meeting'),
  );

  return $form;
}

/**
 * Drupal form validation.
 */
function rmets_committee_document_create_form_validate($form, &$form_state) {
  // Check there isn't already a meeting on this date.
  $tid = $form_state['values']['committee'];
  if (!is_numeric($tid)) {
    form_set_error('committee', 'There is a problem creating a new meeting. Please contact the site administrator.');
  }
  $date = &$form_state['values']['meeting_date'];
  $date['month'] = ($date['month'] < 10 ? '0' : '') . $date['month'];
  $date['day'] = ($date['day'] < 10 ? '0' : '') . $date['day'];
  $date_check = "{$date['year']}-{$date['month']}-{$date['day']}%";
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'committee_meeting')
    ->fieldCondition('field_committee', 'tid', $tid, '=')
    ->fieldCondition('field_meeting_date', 'value', $date_check, 'like');
  $result = $query->execute();
  if (!empty($result)) {
    form_set_error('meeting_date', 'There is already a meeting on this date.');
  }
}

/**
 * Drupal form submission.
 * Create a new meeting node.
 */
function rmets_committee_document_create_form_submit($form, &$form_state) {
  global $user;
  $tid = $form_state['values']['committee'];
  $date = $form_state['values']['meeting_date'];

  $committee_term = taxonomy_term_load($tid);
  $node = (object) array(
    'is_new' => TRUE,
    'title' => "{$committee_term->name} {$date['day']}-{$date['month']}-{$date['year']}",
    'log' => t('Created new meeting from the meeting form'),
    'status' => 1,
    'comment' => 0,
    'promote' => 0,
    'sticky' => 0,
    'type' => 'committee_meeting',
    'language' => LANGUAGE_NONE,
    'uid' => $user->uid,
  );
  node_save($node);

  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->field_committee->set($tid);
  $wrapper->field_meeting_date->set(strtotime("{$date['year']}-{$date['month']}-{$date['day']} 00:00:00"));
  node_save($node);

  drupal_set_message(t('Created new meeting %meeting', array('%meeting' => $node->title)));
}
