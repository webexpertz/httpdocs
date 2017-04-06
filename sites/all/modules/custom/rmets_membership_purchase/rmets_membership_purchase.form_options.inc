<?php

use Drupal\rmets_crm\Api\Request\GetAllReciprocalOrganisationsRequest;
use Drupal\rmets_crm\Model\MembershipPackagePrice;
use Drupal\rmets_crm\Model\JournalItem;
use Drupal\rmets_crm\Model\JournalSubscriptionItem;

/**
 * @file
 * Hide away options for the membership form.
 */

function rmets_membership_purchase_subscription_options($wrapper = NULL, $show_gifts = NULL) {
  if (empty($wrapper)) {
    $wrapper = rmets_membership_purchase_get_commerce_wrapper();
  }
  $items = $wrapper->getAllMembershipPackagePrices();
  $options = array();
  $js_options = array();
  foreach ($items AS $item) {
    /** @var MembershipPackagePrice $item */
    if (!empty($show_gifts)) {
      if ($show_gifts) {
        if (!$item->getGiftMembership()) {
          continue;
        }
      }
      else {
        if ($item->getGiftMembership()) {
          continue;
        }
      }
    }
    $options[$item->getMembershipPackagePriceID()] = $item->getName() . ' (£' . $item->getAmountFormatted() . ')';
    $js_options[$item->getMembershipPackagePriceID()] = $item->getAmount();
  }
  drupal_add_js(array('rmets_membership_purchase' => array('subscription_prices' => $js_options)), 'setting');

  return $options;
}

function rmets_membership_purchase_journal_options($wrapper = NULL, $user_wrapper = NULL, $form_state = NULL) {
  $selected_membership = isset($form_state['values']['product']) ? $form_state['values']['product'] : NULL;
  $package_id = empty($selected_membership) ? NULL : $wrapper->getMembershipPackageIdFromId($selected_membership);
  $package_id = (empty($package_id) && isset($form_state['values']['package_id'])) ? $form_state['values']['package_id'] : $package_id;
  $subscription_id = (!empty($form_state['values']['subscription_id'])) ? $form_state['values']['subscription_id'] : $user_wrapper->getActiveSubscriptionID();

  if (empty($wrapper)) {
    $wrapper = rmets_membership_purchase_get_commerce_wrapper();
  }
  if (empty($package_id)) {
    return array('options' => array('' => 'Select a membership first.'), 'defaults' => array());
  }
  $options = array();
  $js_options = array();
  $defaults = array();
  $items = $wrapper->getAllMembershipPackageJournals($package_id);
  $is_renewal = rmets_membership_purchase_is_renewal_form($form_state);
  $current_membership_journals = NULL;
  if ($is_renewal) {
    $current_membership_journals = rmets_membership_subscriptions_get_current_journals($user_wrapper, $subscription_id);
  }

  // Show all the journals that this subscription currently has set on it.
  $duplicate_options = array();
  if ($is_renewal && !is_null($current_membership_journals) && $current_membership_journals->getIterator()->count() > 0) {
    foreach ($current_membership_journals AS $item) {
      /** @var JournalSubscriptionItem $item */
      $journal_name = rmets_membership_purchase_journal_options_get_name($item->getName());
      $duplicate_options[] = $journal_name;
      $item_name = rmets_membership_purchase_journal_options_is_weather($journal_name) ? trim($journal_name) : $item->getName();
      $options[$item->getJournalItemID()] = $item_name . ' (£' . $item->getAmountFormatted() . ')';
      $js_options[$item->getJournalItemID()] = $item->getAmount();
      $defaults[$item->getJournalItemID()] = $item->getJournalItemID();
    }
  }

  // Show all the journals for this subscriptions package id.
  foreach ($items AS $item) {
    /** @var JournalItem $item */
    //if (($is_renewal && !$item->getRenewOnline()) || (!$is_renewal && !$item->getJoinOnline())) {
    if (!$item->getJoinOnline()) {
      continue;
    }
    // If this journal name matches a journal that is already part of the subscription, then don't show this one.
    if (in_array(rmets_membership_purchase_journal_options_get_name($item->getName()), $duplicate_options)) {
      continue;
    }
    $journal_name = rmets_membership_purchase_journal_options_get_name($item->getName());
    $item_name = rmets_membership_purchase_journal_options_is_weather($journal_name) ? trim($journal_name) : $item->getName();
    $options[$item->getJournalItemID()] = $item_name . ' (£' . $item->getAmountFormatted() . ')';
    $js_options[$item->getJournalItemID()] = $item->getAmount();
    if (strtolower($item->getDefaulted()) == 'true') {
      $defaults[$item->getJournalItemID()] = $item->getJournalItemID();
    }
  }

  if (empty($options)) {
    $options = array('None' => 'Sorry, nothing available');
  }
  drupal_add_js(array('rmets_membership_purchase' => array('journal_prices' => $js_options)), 'setting');
  return array('options' => $options, 'defaults' => $defaults);
}

/**
 * Gets the Journal name from the formatted name returned by CRM.
 *
 * @param string $name
 *
 * @return string
 *   The journal name.
 */
function rmets_membership_purchase_journal_options_get_name($name) {
  return substr($name, 0, strpos($name, '('));
}

/**
 * Returns TRUE if the provided journal name starts with the word weather.
 *
 * This is a bit of a hack due to the journal names being incorrect within CRM
 * for all the renewals which can't be changes for 2015.
 *
 * @deprecated This should be fixed for 2016 renewals!
 *
 * @param string $name
 *   The journal name.
 *
 * @return bool
 */
function rmets_membership_purchase_journal_options_is_weather($name) {
  return FALSE;
  //return substr(drupal_strtolower($name), 0, strlen('weather')) == 'weather';
}

function rmets_membership_purchase_add_defaults_for_renewal(&$form, $form_state, $user_wrapper) {
  /** @var \Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper $user_wrapper */
  $user_wrapper->updateFromCrm();
  $graduation_date = (int) $user_wrapper->getGraduationDate(TRUE);
  if ($graduation_date > 0) {
    $form['enterprise_connector_userdef_GraduationDt']['#default_value'] = format_date($graduation_date, 'custom', 'Y-m-d');
  }
  if (isset($form['enterprise_connector_userdef_HeardofRMetSby'])) {
    $form['enterprise_connector_userdef_HeardofRMetSby']['#default_value'] = $user_wrapper->getHearAboutRMetS();
  }
  $form['enterprise_connector_attribute_2']['#default_value'] = $user_wrapper->getCrmContactInterestTypes();
  $form['Title']['#default_value'] = $user_wrapper->getTitle();
  $form['Forenames']['#default_value'] = $user_wrapper->getForename();
  $form['Surname']['#default_value'] = $user_wrapper->getSurname();
  $form['DateOfBirth']['#default_value'] = format_date((int) $user_wrapper->getDateOfBirth(), 'custom', 'Y-m-d');
  $form['address']['Address1']['#default_value'] = $user_wrapper->getAddress1();
  $form['address']['Address2']['#default_value'] = $user_wrapper->getAddress2();
  $form['address']['Town']['#default_value'] = $user_wrapper->getCity();
  $form['address']['County']['#default_value'] = $user_wrapper->getStateProvince();
  $form['address']['PostCode']['#default_value'] = $user_wrapper->getPostCode();
  $form['address']['CountryCode']['#default_value'] = $user_wrapper->getCountry();
  $form['address']['Telephone1']['#default_value'] = $user_wrapper->getBusinessPhone();
  $form['address']['MobileTelephone']['#default_value'] = $user_wrapper->getMobileNumber();
  $form['giftaid']['#default_value'] = drupal_strtolower($user_wrapper->getGiftAid()) == 'true';
  $form['enterprise_connector_userdef_Receiveemails']['#default_value'] = drupal_strtolower($user_wrapper->getMarketingMaterials()) == 'true';
}

function rmets_membership_purchase_get_special_types($wrapper) {
  $items = $wrapper->getAllMembershipPackagePrices();
  $students = array();
  $fellows = array();
  $reciprocals = array();
  $corporates = array();
  foreach ($items AS $item) {
    if (strtolower($item->getGrade()) == 'student') {
      $students[$item->getMembershipPackagePriceID()] = TRUE;
    }
    elseif (strtolower($item->getGrade()) == 'reciprocal') {
      $reciprocals[$item->getMembershipPackagePriceID()] = TRUE;
    }
    if (strtolower($item->getClass()) == 'fellow') {
      $fellows[$item->getMembershipPackagePriceID()] = TRUE;
    }
    elseif (strtolower($item->getClass()) == 'corporate member') {
      $corporates[$item->getMembershipPackagePriceID()] = TRUE;
    }
  }
  $return = array('students' => $students, 'fellows' => $fellows, 'reciprocals' => $reciprocals, 'corporates' => $corporates);
  drupal_add_js(array('rmets_membership_purchase' => array('students_and_fellows' => $return)), 'setting');
  return $return;
}

function rmets_membership_purchase_get_reciprocal_organisation_options() {
  $options = array();
  try {
    $request = new GetAllReciprocalOrganisationsRequest();
    $request->setGuid(variable_get('rmets_crm_api_guid', ''));
    $request->setPage(1);
    $request->setRecordCount(100);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->getAllReciprocalOrganisations($request);
    $options[''] = '- Select -';
    foreach ($response AS $organisation) {
      $options[$organisation->getOrganisationId()] = $organisation->getName();
    }
    return $options;
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}
