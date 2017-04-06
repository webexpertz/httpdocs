<?php
use Drupal\rmets_events\EntityWrapper\Node\EventWrapper;
use Drupal\rmets_crm\Model\EventAbstract;
use Drupal\rmets_crm\Model\EventSpeaker;
use Drupal\rmets_crm\Model\EventSessionItem;
use Drupal\rmets_events\EntityWrapper\Node\EventAbstractWrapper;
use Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper;

/**
 * The menu callback for registering for an event.
 *
 * @param $node
 * @return array|mixed
 */
function rmets_events_register_page($node) {
  if (!isset($node->type) || $node->type != 'event') {
    drupal_not_found();
  }
  drupal_set_title(drupal_get_title() . ': ' . check_plain($node->title));

  $path_alias = drupal_get_path_alias('node/' . $node->nid);

  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Events & Meetings', 'events');
  $breadcrumb[] = l(check_plain($node->title), $path_alias);
  $breadcrumb[] = t('Register');
  drupal_set_breadcrumb($breadcrumb);

  return drupal_get_form('rmets_events_registration_form', $node);
}

/**
 * Foo.
 */
function rmets_events_registration_form($form, &$form_state, $event_node) {
  $account = $GLOBALS['user'];
  $form = array();
  $wrapper = new EventWrapper($event_node);
  $crm_event_id = $wrapper->field_event_id->value();

  // Fees
  $fees = $wrapper->getEventRegistrationFees();
  $fees_options = array();
  $js = array();
  //$fees_options[] = ' - select - ';
  foreach ($fees AS $fee) {
    $fees_options[$fee->getFeeId()] = $fee->getName() . ' (' . '£' . number_format($fee->getRate(), 2) . ')';
    $js[$fee->getFeeId()] = $fee->getRate();
  }
  drupal_add_js(array('rmets_events' => array('fees_prices' => $js)), 'setting');

  // Optionals
  $js = array();
  if (empty($form_state['values']['fees'])) {
    $optional_options = array('' => 'Select a package first');
  }
  else {
    $options = $wrapper->getEventRegistrationFeesOptionals();
    $optional_options = array();
    foreach ($options AS $option) {
      if ($option->getFeeId() == $form_state['values']['fees']) {
        $optional_options[$option->getOptionalId()] = $option->getName() . ' (' . '£' . number_format($option->getRate(), 2) . ')';
      }
      $js[$option->getOptionalId()] = $option->getRate();
    }
    if (empty($optional_options)) {
      //$optional_options[''] = 'This event has no optional items'; // @todo test
    }
  }
  drupal_add_js(array('rmets_events' => array('options_prices' => $js)), 'setting');

  $form['markup'] = array(
    '#markup' => 'Your cost is &pound;<span id="your-price">0</span> ',
  );
  $form['event_id'] = array(
    '#value' => $wrapper->getIdentifier(),
  );
  $form['crm_event_id'] = array(
    '#value' => $crm_event_id,
  );

  $form['event_name'] = array(
    '#value' => $wrapper->title->value(),
  );

  $user_wrapper = rmets_membership_user_get_user_wrapper($account);

  if ($account->uid) {
    $user_wrapper->updateFromCrm();
    $contact_id = $user_wrapper->getCrmContactId();
  }
  else {
    $contact_id = FALSE;

    $form['your_details'] = array(
      '#type' => 'fieldset',
      '#title' => 'Delegate\'s Details',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['your_details']['email'] = array(
      '#type' => 'textfield',
      '#title' => 'Email Address',
      '#required' => '1',
    );
    $form['your_details']['title'] = array (
      '#title' => 'Title',
      '#title_display' => 'before',
      '#required' => '1',
      '#description' => '',
      '#options' => $user_wrapper->getTitleOptions(),
      '#default_value' => 'Mr',
      '#type' => 'select',
    );
    $form['your_details']['forenames'] = array (
      '#type' => 'textfield',
      '#title' => 'Forenames',
      '#title_display' => 'before',
      '#required' => '1',
      '#description' => '',
    );
    $form['your_details']['surname'] = array (
      '#type' => 'textfield',
      '#title' => 'Surname',
      '#title_display' => 'before',
      '#required' => '1',
      '#description' => '',
    );
    $form['your_details']['suffix'] = array (
      '#type' => 'select',
      '#title' => 'Suffix',
      '#multiple' => TRUE,
      '#options' => rmets_events_get_event_suffix_type_options_from_crm(),
      '#title_display' => 'before',
      '#description' => '',
    );
    $form['your_details']['date_of_birth'] = array (
      '#type' => 'date_popup',
      '#date_format' => 'd/m/Y',
      '#title' => 'Date of Birth',
      '#title_display' => 'before',
      '#description' => 'Their date of birth',
      '#date_year_range' => '-110:+1',
      '#year_textfield' => 0,
      '#default_value' => '',
      '#timezone' => 'site',
    );

  }
  $form['contact_id'] = array(
    '#value' => $contact_id,
  );

  if ($wrapper->field_allow_affiliate_name->value()) {
    $form['affiliate_name'] = array(
      '#type' => 'textfield',
      '#title' => 'Affiliation',
      '#title_display' => 'before',
      '#description' => 'Please enter your affiliation as you would like it to appear on your name badge',
      '#default_value' => $user_wrapper->getOrganisationName(),
    );
  }

  $form['fees'] = array(
    '#title' => 'Package',
    '#type' => 'select',
    '#required' => TRUE,
    '#options' => $fees_options,
    '#ajax' => array(
      'callback' => 'rmets_events_dependent_dropdown_callback',
      'wrapper' => 'dropdown-second-replace',
    ),
  );
  $form['optional_extras'] = array(
    '#title' => 'Optional Extras',
    '#type' => 'checkboxes',
    '#multiple' => TRUE,
    '#options' => $optional_options,
    '#prefix' => '<div id="dropdown-second-replace">',
    '#suffix' => '</div>',
  );
  if ($wrapper->field_allow_dietary_requirements->value()) {
    $form['dietary_requirements'] = array(
      '#title' => 'Dietary requirements',
      '#type' => 'select',
      '#options' => $wrapper->getDietaryOptions(),
      '#multiple' => TRUE,
      '#chosen' => TRUE,
    );
    $form['dietary_requirements_other'] = array(
      '#title' => 'Dietary requirements - Details',
      '#type' => 'textarea',
    );
  }
  $form['special_requirements'] = array(
    '#title' => 'Special requirements',
    '#type' => 'select',
    '#options' => $wrapper->getSpecialOptions(),
    '#multiple' => TRUE,
    '#chosen' => TRUE,
  );
  $form['special_requirements_other'] = array(
    '#title' => 'Special requirements - Details',
    '#type' => 'textarea',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Register',
  );
  $form['#attached'] = array(
    'js' => array(
      drupal_get_path('module', 'rmets_events') . '/assets/js/calculate_price.js'
    ),
  );
  $form['price_to_pay'] = array(
    '#type' => 'hidden',
  );

  return $form;
}

/**
 * Validate callback for Foo.
 */
function rmets_events_registration_form_validate(&$form, &$form_state) {
  //die(kpr($form_state));
}

/**
 * Submit callback for Foo.
 */
function rmets_events_registration_form_submit(&$form, &$form_state){
  $data = $form_state['values'];
  $data['complete form'] = $form_state['complete form'];
  $data['event_id'] = $form_state['complete form']['event_id']['#value'];
  $data['crm_event_id'] = $form_state['complete form']['crm_event_id']['#value'];

  // Start of Title
  $data['title_of_item'] = 'Event: ' . $form_state['complete form']['event_name']['#value'];

  $price_to_pay = 0;
  if (isset($form_state['values']['fees'])) {
    $data['title_of_item'] .= ' (With Fees: ' . preg_replace('/\(.*\)/', '', $form_state['complete form']['fees']['#options'][$form_state['values']['fees']]) . ')';
    preg_match_all('/(£[0-9.]+)/', $form_state['complete form']['fees']['#options'][$form_state['values']['fees']], $matches);
    $last_match = end($matches);
    $price_to_pay += str_replace('£', '', end($last_match));
  }

  $optionals = array();
  foreach ($form_state['values']['optional_extras'] AS $id => $value) {
    if ($value !== 0) {
      $optional_extra = $form_state['complete form']['optional_extras']['#options'][$value];
      $optionals[] = preg_replace('/\(.*\)/', '', $optional_extra);
      preg_match_all('/(£[0-9.]+)/', $optional_extra, $matches);
      $last_match = end($matches);
      $price_to_pay += str_replace('£', '', end($last_match));
    }
  }

  // Reset the price to pay to be the value based upon what has been selected.
  $data['price_to_pay'] = $price_to_pay;

  $optionals_text = empty($optionals) ? 'None' : implode(', ', $optionals);

  $data['title_of_item'] .= ' (With optional extras: ' . $optionals_text . ')';
  // End of Title

  $data['contact_id'] = $form_state['complete form']['contact_id']['#value'];
  if ($data['contact_id'] == FALSE) {
    // Either they have an account, or we make them a wrapperable thing.
    if (!$account = user_load_by_mail($form_state['values']['email'])) {
      $account = UserWrapper::createNewUserAccount($form_state['values']['email']);
    }

    // Try to find them in CRM.
    $member = new UserWrapper($account);
    $member->updateFromCrm();
    if (!$member->getCrmContactId()) {
      // If we can't make them a minimal profile.
      $member->setForename($form_state['values']['forenames']);
      $member->setSurname($form_state['values']['surname']);
      $member->setTitle($form_state['values']['title']);
      if (!empty($form_state['values']['date_of_birth'])) {
        $member->setDateOfBirth($form_state['values']['date_of_birth']);
      }
      $member->setGiftAid(1);
      $member->setMarketingMaterials(1);
      if (!empty($data['affiliate_name'])) {
        $member->setOrganisationName($data['affiliate_name']);
      }
      try {
        $member->save();
      }
      catch (Exception $e) {
        drupal_set_message('There was a problem creating your contact. Please check and try again or contact the membership department', 'error');
        return;
      }
      if (empty($data['suffix'])) {
        $member->updateContactSuffixes($data['suffix']);
      }
    }
    $data['contact_id'] = $member->getCrmContactId();
    if (empty($data['contact_id'])) {
      drupal_set_message('There was a problem finding your CRM contact. Please check and try again or contact the membership department', 'error');
      return;
    }
    $data['crm_member'] = $member;
  }
  elseif ($GLOBALS['user']->uid) {
    $user = user_load($GLOBALS['user']->uid);
    $member = new UserWrapper($user);
    $member->updateFromCrm();
    $data['crm_member'] = $member;
    if (isset($data['affiliate_name']) && !empty($data['affiliate_name']) && $data['affiliate_name'] != $member->getOrganisationName()) {
      $member->setOrganisationName($data['affiliate_name']);
      $member->save();
    }
  }

  if ($price_to_pay > 0) {
    // We need to fire up commerce.
    rmets_events_send_event_to_commerce($data);
  }
  else {
    // We can add them already.
    rmets_events_create_event_registration($data);
  }
}

function rmets_events_dependent_dropdown_callback(&$form, &$form_state) {
  return $form['optional_extras'];
}

/**
 * @param EventAbstract $abstract
 *
 * @return array
 */
function rmets_events_abstract_page($abstract) {
  if (empty($abstract)) {
    return '';
  }

  // Get the event by CRM id.
  $event_wrapper = EventWrapper::getEventByCrmId($abstract->getEventID());
  $path_alias = drupal_get_path_alias('node/' . $event_wrapper->getIdentifier());

  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Events & Meetings', 'events');
  $breadcrumb[] = l($event_wrapper->title->value(), $path_alias);
  $breadcrumb[] = t($abstract->getTitle());
  drupal_set_breadcrumb($breadcrumb);

  $crm_event_speakers = $event_wrapper->getCrmEventSpeakers();
  $event_speakers = array();
  foreach ($crm_event_speakers as $speaker) {
    /** @var EventSpeaker $speaker */
    if ($speaker->getAbstractID() !== $abstract->getAbstractID()) {
      continue;
    }
    if (empty($speaker->getBiography())) {
      continue;
    }
    $event_speakers[$speaker->getMembershipNumber()] = $speaker;
  }

  $abstract_speakers_crm = EventAbstractWrapper::getAbstractSpeakersFromCRM($abstract->getAbstractID());
  $abstract_speakers = array();
  foreach ($abstract_speakers_crm as $speaker) {
    /** @var EventSpeaker $speaker */
    $abstract_speaker = $speaker->getSalutation();
    if (!empty($speaker->getAffiliationName())) {
      $abstract_speaker .= ' (' . $speaker->getAffiliationName() . ')';
    }
    $abstract_speakers[] = $abstract_speaker;
  }

  $abstract_authors_crm = EventAbstractWrapper::getAbstractAuthorsFromCRM($abstract->getAbstractID());
  $abstract_authors = array();
  foreach ($abstract_authors_crm as $speaker) {
    /** @var EventSpeaker $speaker */
    $abstract_author = $speaker->getSalutation();
    if (!empty($speaker->getAffiliationName())) {
      $abstract_author .= ' (' . $speaker->getAffiliationName() . ')';
    }
    $member_award = _rmets_events_get_member_awards($speaker->getMembershipNumber());
    if ($member_award) {
      $award_names = array();
      foreach ($member_award as $award) {
        $variables = array(
          'path' => 'sites/all/themes/rmets/assets/images/award.png',
          'alt' => $award->name,
          'title' => $award->name,
          'height' => '16px',
          'attributes' => array('style' => 'display:inline'),
        );
        $award_names[] = theme('image', $variables);
      }
      $abstract_author .= ' ' . implode(' ', $award_names);
    }
    $abstract_authors[] = $abstract_author;
  }

  $crm_event_session_items = $event_wrapper->getCrmEventSessionItems();
  $abstract_session_item = NULL;
  foreach ($crm_event_session_items as $session_item) {
    /** @var EventSessionItem $session_item */
    if ($session_item->getAbstractID() == $abstract->getAbstractID()) {
      $abstract_session_item = $session_item;
      break;
    }
  }

  $abstract_date = date('jS F Y', $abstract_session_item->getStartDateTimeAsTimestamp());
  $abstract_time = date('H:i', $abstract_session_item->getStartDateTimeAsTimestamp());
  $venue = $event_wrapper->field_summary_location->value();

  return theme('rmets_events_abstract', array(
    'event_name' => $event_wrapper->title->value(),
    'date' => $abstract_date,
    'time' => $abstract_time,
    'venue' => $venue['value'],
    'number' => $abstract->getNumber(),
    'theme' => $abstract->getTheme(),
    'speakers' => implode(', ', $abstract_speakers),
    'event_speakers' => $event_speakers,
    'authors' => implode(', ', $abstract_authors),
    'summary' => $abstract->getSummary(),
  ));
}

/**
 * Helper function to get at award information for a membership number.
 *
 * @param string $membership_number
 *
 * @return array
 *   Returns an array of the awards for a membership number.
 */
function _rmets_events_get_member_awards($membership_number) {
  $query = db_select('node', 'n');
  $query->join('field_data_field_membership_number', 'mn', 'mn.entity_id = n.nid');
  $query->join('field_data_field_award_type', 'at', 'at.entity_id = n.nid');
  $query->join('taxonomy_term_data', 't', 't.tid = at.field_award_type_tid');
  $query->fields('n', array('nid'))
    ->fields('t', array('name'))
    ->condition('n.type', 'award')
    ->condition('at.bundle', 'award')
    ->condition('mn.field_membership_number_value', $membership_number);

  $result = $query->execute();
  if (empty($result)) {
    return array();
  }

  $awards = array();
  foreach ($result as $record) {
    $awards[] = $record;
  }

  return $awards;
}
