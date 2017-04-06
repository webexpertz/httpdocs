<?php

use Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper;
use Drupal\rmets_crm\Api\Request\CreateContactSubscriptionRequest;
use Drupal\rmets_crm\Api\Request\RemoveMemberSubscriptionJournalsRequest;
use Drupal\rmets_crm\Api\Request\AddMemberSubscriptionJournalsRequest;
use Drupal\rmets_crm\Api\Request\MarkSubscriptionPaymentsAsPaidRequest;




/**
 * Implements hook_rules_action_info().
 */
function rmets_membership_purchase_rules_action_info() {
  $actions = array();

  $actions['rmets_membership_purchase_pass_to_smartimpact'] = array(
    'label' => t('Pass membership to smartimpact'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
    ),
    'group' => t('RMetS Membership Purchase'),
  );


  return $actions;
}

/**
 * Takes an order and passes the details to smartimpact.
 *
 * @param $order - A commerce order
 */
function rmets_membership_purchase_pass_to_smartimpact($order) {
  watchdog('rmets_membership_purchase', 'here');
  module_invoke_all('commerce_smartimpact', $order);
}

/**
 * Helper function to update the user details.
 *
 * @param UserWrapper $user_wrapper
 */
function rmets_membership_purchase_create_or_update_membership($user_wrapper, $line_item, $is_gift_user = FALSE) {
  $key = ($is_gift_user) ? 'gift_for_' : '';
  $user_wrapper->updateFromCrm();
  $user_wrapper->setTitle($line_item->data[$key . 'Title']);
  $user_wrapper->setForename($line_item->data[$key . 'Forenames']);
  $user_wrapper->setSurname($line_item->data[$key . 'Surname']);
  if (isset($line_item->data[$key . 'DateOfBirth'])) {
    $user_wrapper->setDateOfBirth($line_item->data[$key . 'DateOfBirth']);
  }
  $user_wrapper->setMobileNumber($line_item->data[$key . 'MobileTelephone']);
  $user_wrapper->setHomePhone($line_item->data[$key . 'Telephone1']);

  if (isset($line_item->data['Occupation'])) {
    $user_wrapper->setOccupation($line_item->data['Occupation']);
  }
  if (isset($line_item->data['Company_name'])) {
    $user_wrapper->setOrganisationName($line_item->data['Company_name']);
  }

  $marketing_materials = (isset($line_item->data[$key . 'enterprise_connector_userdef_Receiveemails'])) ? $line_item->data[$key . 'enterprise_connector_userdef_Receiveemails'] : TRUE;
  $user_wrapper->setMarketingMaterials($marketing_materials);
  $gift_aid = (isset($line_item->data[$key . 'giftaid'])) ? $line_item->data[$key . 'giftaid'] : FALSE;
  $user_wrapper->setGiftAid($gift_aid);

  $user_wrapper->setAddress1($line_item->data[$key . 'Address1']);
  $user_wrapper->setAddress2($line_item->data[$key . 'Address2']);
  $user_wrapper->setCity($line_item->data[$key . 'Town']);
  $user_wrapper->setStateProvince($line_item->data[$key . 'County']);
  $user_wrapper->setPostCode($line_item->data[$key . 'PostCode']);
  $user_wrapper->setCountry($line_item->data[$key . 'CountryCode']);

  if (isset($line_item->data[$key . 'enterprise_connector_userdef_GraduationDt'])) {
    $user_wrapper->setGraduationDate($line_item->data[$key . 'enterprise_connector_userdef_GraduationDt']);
  }
  if (isset($line_item->data[$key . 'enterprise_connector_userdef_HeardofRMetSby'])) {
    $user_wrapper->setHearAboutRMetS($line_item->data[$key . 'enterprise_connector_userdef_HeardofRMetSby']);
  }
  if (isset($line_item->data[$key . 'enterprise_connector_attribute_2'])) {
    $user_wrapper->setInterestTypes($line_item->data[$key . 'enterprise_connector_attribute_2']);
  }

  $user_wrapper->save();
}

/**
 * Helper function to create the subscription.
 *
 * @param UserWrapper $user_wrapper
 * @param $line_item
 * @param $is_gift
 * @return \Drupal\rmets_crm\Api\Response\JournalSubscriptionItemResponse
 * @throws \Drupal\rmets_crm\Api\ApiServerException
 */
function rmets_membership_purchase_create_subscription_for_user($user_wrapper, $line_item, $is_gift = FALSE) {
  if ($is_gift) {
    // Create the gift for user.
    $gift_user = UserWrapper::createNewUserAccount($line_item->data['gift_for_email']);
    $gift_user_wrapper = new UserWrapper($gift_user);
    $gift_user_wrapper->addMemberRole();
    rmets_membership_purchase_create_or_update_membership($gift_user_wrapper, $line_item, TRUE);
    $contact_id = $gift_user_wrapper->getCrmContactId();

    // Get the user wrapper for the purchaser user.
    $gift_contact_id = $user_wrapper->getCrmContactId();
  }
  else {
    $contact_id = $user_wrapper->getCrmContactId();
    $gift_contact_id = NULL;
  }

  // Make the subscription.
  $request = new CreateContactSubscriptionRequest();
  $request->setGuid(variable_get('rmets_crm_api_guid', ''));
  $request->setContactId($contact_id);
  $request->setPackagePriceId($line_item->data['product']);

  if (!empty($gift_contact_id)) {
    $request->setGiftFrom($gift_contact_id);
  }

  if (!empty($line_item->data['donation']) && (float) $line_item->data['donation'] > 0) {
    $request->setDonation($line_item->data['donation']);
  }

  if (!empty($line_item->data['reciprocal_organisation'])) {
    $request->setReciprocalOrganisationID($line_item->data['reciprocal_organisation']);
  }

  if (!empty($line_item->data['reciprocal_membership_number'])) {
    $request->setReciprocalMembershipNumber($line_item->data['reciprocal_membership_number']);
  }

  if (!empty($line_item->data['sponsors1'])) {
    // Concatenate the sponsors.
    $sponsors = '';
    for ($i = 1; $i < 3; $i++) {
      $sponsors .= $line_item->data["sponsors$i"] . ', ' . $line_item->data["sponsorsemail$i"] . ', ' . $line_item->data["sponsorsmembernumber$i"];
      if ($i === 1) {
        $sponsors .= ', ';
      }
    }
    $request->setSponsors($sponsors);
  }

  if (!empty($line_item->data['journal'])) {
    foreach ($line_item->data['journal'] AS $id => $journal) {
      if ($journal !== 0) {
        $request->addJournal($id);
      }
    }
  }

  /** @var \Drupal\rmets_crm\Api\CrmService $api */
  $api = rmets_crm_get_api();
  $response = $api->createContactSubscription($request);
  return $response;
}

function rmets_membership_purchase_mark_subscription_paid($user_wrapper, $line_item) {
  $subscription_id = $line_item->data['subscription_id'];
  $donation = $line_item->data['donation'];

  try {
    $request = new MarkSubscriptionPaymentsAsPaidRequest();
    $request->setGuid(variable_get('rmets_crm_api_guid', ''));
    $request->setSubscriptionId($subscription_id);

    if (!empty($donation)) {
      $request->setDonation($donation);
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    $response = $api->markSubscriptionPaymentsAsPaid($request);
  }
  catch (InvalidRequestException $e) {
    print drupal_set_message('FATAL ' . $e->getMessage(), 'error');
  }
  catch (ApiServerException $apie) {
    print drupal_set_message('FATAL' . 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }

}

function rmets_membership_purchase_remove_journal_subscriptions($user_wrapper, $line_item) {
  try {
    $request = new RemoveMemberSubscriptionJournalsRequest();
    $request->setGuid(variable_get('rmets_crm_api_guid', ''));
    $request->setSubscriptionId($line_item->data['subscription_id']);

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    return $api->removeMemberSubscriptionJournals($request);
  } catch (InvalidRequestException $e) {
    print drupal_set_message('FATAL ' . $e->getMessage(), 'error');
  } catch (ApiServerException $apie) {
    print drupal_set_message('FATAL' . 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}

function rmets_membership_purchase_add_journal_subscriptions($user_wrapper, $line_item) {
  try {
    $request = new AddMemberSubscriptionJournalsRequest();
    $request->setGuid(variable_get('rmets_crm_api_guid', ''));
    $request->setSubscriptionId($line_item->data['subscription_id']);

    if (!empty($line_item->data['journal'])) {
      foreach ($line_item->data['journal'] AS $id => $journal) {
        if ($journal !== 0) {
          $request->addJournal($id);
        }
      }
    }

    /** @var \Drupal\rmets_crm\Api\CrmService $api */
    $api = rmets_crm_get_api();
    return $api->addMemberSubscriptionJournals($request);
  }
  catch (InvalidRequestException $e) {
    print drush_set_error('FATAL', $e->getMessage());
  }
  catch (ApiServerException $apie) {
    print drush_set_error('FATAL', 'Unable to communicate with the CRM API: ' . $apie->getMessage());
  }
}
