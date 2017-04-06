<?php
/**
 * @file
 */

use Drupal\rmets_membership_user\EntityWrapper\User\UserWrapper;
use Drupal\rmets_crm\Api\ApiServerException;
use Drupal\rmets_crm\Model\Donation;

/**
 * Callback function for rendering 'my details' form to edit CRM details.
 */
function rmets_membership_user_mydetails_form($form, &$form_state) {
  try {
    rmets_crm_get_api();
  }
  catch (ApiServerException $e) {
    drupal_set_message(t('Unable to connect to our membership database.'), 'error');
    return array();
  }

  $account = $form_state['build_info']['args'][0];
  $user_wrapper = new UserWrapper($account);
  $user_wrapper->updateFromCrm();

  // If the user has no crm contact id, then they are no a user in CRM.
  $is_valid_crm_user = $user_wrapper->isValidCrmContact();

  // Show an error message to a CRM admin person.
  if ($user_wrapper->hasMultipleMatchingContacts() && (user_access('administer crm') || user_access('edit other users crm membership details'))) {
    drupal_set_message(t('There were multiple records found in CRM for this users email address - unable to link this user.'), 'error');
  }

  if ($is_valid_crm_user) {
    $form['crm_contact_id'] = array(
      '#type' => 'markup',
      '#markup' => '<label>CRM Contact ID</label>' . $user_wrapper->getCrmContactId(),
      '#prefix' => '<div>',
      '#suffix' => '</div>',
      '#access' => user_access('rmets membership user1 access only'),
    );

    $access_membership_number = user_access('edit crm membership numbers') || user_access('edit other users crm membership details');
    if ($access_membership_number) {
      $form['membership_number'] = array(
        '#type' => 'textfield',
        '#title' => t('Membership Number'),
        //'#description' => t('.'),
        '#default_value' => $user_wrapper->getMembershipNumber(),
        '#size' => 60,
        '#maxlength' => 10,
      );
    }
    else {
      $form['membership_number'] = array(
        '#type' => 'markup',
        '#markup' => '<label>Membership Number</label>' . $user_wrapper->getMembershipNumber(),
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
    }
  }

  $form['title'] = array(
    '#type' => 'select',
    '#title' => t('Title'),
    //'#description' => $user_wrapper->getTitle(),
    '#options' => $user_wrapper->getTitleOptions(),
    '#default_value' => $user_wrapper->getTitle(),
  );

  $form['forename'] = array(
    '#type' => 'textfield',
    '#title' => t('Forename'),
    //'#description' => t('.'),
    '#default_value' => $user_wrapper->getForename(),
    '#size' => 60,
    '#maxlength' => 40,
  );

  $form['surname'] = array(
    '#type' => 'textfield',
    '#title' => t('Surname'),
    //'#description' => t('.'),
    '#default_value' => $user_wrapper->getSurname(),
    '#size' => 60,
    '#maxlength' => 40,
  );

  $user_dob = $user_wrapper->getDateOfBirth();
  $date_of_birth = array(
    'year' => date('Y', $user_dob),
    'month' => date('n', $user_dob),
    'day' => date('j', $user_dob)
  );

  $form['date_of_birth'] = array(
    '#type' => 'date',
    '#title' => t('Date of Birth'),
    //'#description' => $user_wrapper->getDateOfBirth(),
    '#default_value' => $date_of_birth,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => $user_wrapper->getEmail(),
    '#size' => 60,
    '#maxlength' => 100,
  );

  $form['mobile_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Number'),
    //'#description' => t('.'),
    '#default_value' => $user_wrapper->getMobileNumber(),
    '#size' => 60,
    '#maxlength' => 40,
  );

  if ($is_valid_crm_user) {
    $form['home_number'] = array(
      '#type' => 'textfield',
      '#title' => t('Home Number'),
      //'#description' => t('.'),
      '#default_value' => $user_wrapper->getHomePhone(),
      '#size' => 60,
      '#maxlength' => 40,
    );
    $form['business_number'] = array(
      '#type' => 'textfield',
      '#title' => t('Business Number'),
      //'#description' => t('.'),
      '#default_value' => $user_wrapper->getBusinessPhone(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['occupation'] = array(
      '#type' => 'textfield',
      '#title' => t('Occupation'),
      //'#description' => t('.'),
      '#default_value' => $user_wrapper->getOccupation(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['gender'] = array(
      '#type' => 'select',
      '#title' => t('Gender'),
      //'#description' => $user_wrapper->getGender(),
      '#options' => $user_wrapper->getGenderOptions(),
      '#default_value' => $user_wrapper->getGender(),
    );

    /*$form['hear_about_rmets'] = array(
      '#type' => 'select',
      '#title' => t('How did you hear about RMetS?'),
      //'#description' => $user_wrapper->getHearAboutRMetS(),
      '#options' => $user_wrapper->getHearAboutRmetsOptions(),
      '#default_value' => $user_wrapper->getHearAboutRMetS(),
    );*/

    $form['interest_types'] = array (
      '#type' => 'select',
      '#title' => t('Please select your interests'),
      '#title_display' => 'before',
      '#multiple' => TRUE,
      '#description' => t('Hold down the control key to select multiple entries.'),
      '#empty_value' => '',
      '#size' => 8,
      '#options' => $user_wrapper->getInterestTypeOptions(),
      '#default_value' => $user_wrapper->getCrmContactInterestTypes(),
    );

    $form['marketing_materials'] = array(
      '#type' => 'checkbox',
      '#title' => t('Do you want to receive marketing materials?'),
      //'#description' => $user_wrapper->getMarketingMaterials(),
      '#default_value' => drupal_strtolower($user_wrapper->getMarketingMaterials()) == 'true',
    );

    // hide gift aid is not needed to be set on the mydetails form.
    $form['gift_aid'] = array(
      //'#type' => 'textfield',
      //'#title' => t('Gift Aid?'),
      '#type' => 'hidden',
      '#default_value' => $user_wrapper->getGiftAid(),
    );

    $form['addresses'] = array(
      '#type' => 'fieldset',
    );

    $form['addresses']['add1'] = array(
      '#type' => 'fieldset',
      '#title' => t('Address'),
    );

    $form['addresses']['add1']['add1_address1'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 1'),
      //'#description' => $user_wrapper->getAddress1(),
      '#default_value' => $user_wrapper->getAddress1(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add1']['add1_address2'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 2'),
      //'#description' => $user_wrapper->getAddress2(),
      '#default_value' => $user_wrapper->getAddress2(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add1']['add1_address3'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 3'),
      //'#description' => $user_wrapper->getAddress3(),
      '#default_value' => $user_wrapper->getAddress3(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add1']['add1_city'] = array(
      '#type' => 'textfield',
      '#title' => t('City'),
      //'#description' => $user_wrapper->getCity(),
      '#default_value' => $user_wrapper->getCity(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add1']['add1_county'] = array(
      '#type' => 'textfield',
      '#title' => t('County'),
      //'#description' => $user_wrapper->getStateProvince(),
      '#default_value' => $user_wrapper->getStateProvince(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add1']['add1_postcode'] = array(
      '#type' => 'textfield',
      '#title' => t('Postcode'),
      //'#description' => $user_wrapper->getPostCode(),
      '#default_value' => $user_wrapper->getPostCode(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $country_options = $user_wrapper->getCountryOptions();
    $form['addresses']['add1']['add1_country'] = array(
      '#type' => 'select',
      '#title' => t('Country'),
      //'#description' => $user_wrapper->getCountry(),
      '#options' => $country_options,
      '#default_value' => $user_wrapper->getCountry(),
    );

    $form['addresses']['add2'] = array(
      '#type' => 'fieldset',
      '#title' => t('2nd Address'),
    );

    $form['addresses']['add2']['add2_address1'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 1'),
      //'#description' => t('.'),
      '#default_value' => $user_wrapper->get2ndAddress1(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add2']['add2_address2'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 2'),
      //'#description' => $user_wrapper->get2ndAddress2(),
      '#default_value' => $user_wrapper->get2ndAddress2(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add2']['add2_address3'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 3'),
      //'#description' => $user_wrapper->get2ndAddress3(),
      '#default_value' => $user_wrapper->get2ndAddress3(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add2']['add2_city'] = array(
      '#type' => 'textfield',
      '#title' => t('City'),
      //'#description' => $user_wrapper->get2ndCity(),
      '#default_value' => $user_wrapper->get2ndCity(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add2']['add2_county'] = array(
      '#type' => 'textfield',
      '#title' => t('County'),
      //'#description' => $user_wrapper->get2ndStateProvince(),
      '#default_value' => $user_wrapper->get2ndStateProvince(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add2']['add2_postcode'] = array(
      '#type' => 'textfield',
      '#title' => t('Postcode'),
      //'#description' => $user_wrapper->get2ndPostCode(),
      '#default_value' => $user_wrapper->get2ndPostCode(),
      '#size' => 60,
      '#maxlength' => 40,
    );

    $form['addresses']['add2']['add2_country'] = array(
      '#type' => 'select',
      '#title' => t('Country'),
      //'#description' => $user_wrapper->get2ndCountry(),
      '#options' => $country_options,
      '#default_value' => $user_wrapper->get2ndCountry(),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  return $form;
}

/**
 * Submit handler/function to the form.
 */
function rmets_membership_user_mydetails_form_submit($form, &$form_state) {
  $account = $form_state['build_info']['args'][0];
  $values = $form_state['values'];

  $user_wrapper = new UserWrapper($account);
  $user_wrapper->updateFromCrm();

  $user_wrapper->setEmail($values['email']);
  $user_wrapper->setTitle($values['title']);
  $user_wrapper->setForename($values['forename']);
  $user_wrapper->setSurname($values['surname']);
  $user_wrapper->setDateOfBirth($values['date_of_birth']);
  $user_wrapper->setMobileNumber($values['mobile_number']);

  if ($user_wrapper->isValidCrmContact()) {
    $old_address = $user_wrapper->getFullAddress1();

    $user_wrapper->setMembershipNumber($values['membership_number']);
    $user_wrapper->setHomePhone($values['home_number']);
    $user_wrapper->setBusinessPhone($values['business_number']);
    $user_wrapper->setOccupation($values['occupation']);
    $user_wrapper->setGender($values['gender']);
    //$user_wrapper->setHearAboutRMetS($values['hear_about_rmets']);
    $user_wrapper->setMarketingMaterials($values['marketing_materials']);
    $user_wrapper->setGiftAid($values['gift_aid']);

    $user_wrapper->setAddress1($values['add1_address1']);
    $user_wrapper->setAddress2($values['add1_address2']);
    $user_wrapper->setAddress3($values['add1_address3']);
    $user_wrapper->setCity($values['add1_city']);
    $user_wrapper->setStateProvince($values['add1_county']);
    $user_wrapper->setPostCode($values['add1_postcode']);
    $user_wrapper->setCountry($values['add1_country']);

    $user_wrapper->set2ndAddress1($values['add2_address1']);
    $user_wrapper->set2ndAddress2($values['add2_address2']);
    $user_wrapper->set2ndAddress3($values['add2_address3']);
    $user_wrapper->set2ndCity($values['add2_city']);
    $user_wrapper->set2ndStateProvince($values['add2_county']);
    $user_wrapper->set2ndPostCode($values['add2_postcode']);
    $user_wrapper->set2ndCountry($values['add2_country']);

    $user_wrapper->setInterestTypes($values['interest_types']);

    $new_address = $user_wrapper->getFullAddress1();
    if ($old_address !== $new_address) {
      $account->changed_address_details = array(
        'old-address' => $old_address,
        'new-address' => $new_address,
        'type' => 'address1',
      );
      rules_invoke_all('rmets_membership_user_address_updated', $account, $old_address, $new_address, 'address1');
    }
  }

  $user_wrapper->save();

  drupal_set_message(t('Your details have been updated successfully.'));
}

/**
 * Callback function to get the users donations.
 */
function rmets_membership_user_donations($account) {
  try {
    rmets_crm_get_api();
  }
  catch (ApiServerException $e) {
    drupal_set_message(t('Unable to connect to our membership database.'), 'error');
    return '';
  }

  $user_wrapper = new UserWrapper($account);
  $donations = array();
  if ($user_wrapper->isValidCrmContact()) {
    $donations = $user_wrapper->getDonationsList();
  }

  $table_data = array();
  $table_data['header'] = array(
    'Name',
    'Date',
    'Amount (£)'
  );

  $activity_list = array();
  if (!empty($donations)) {
    foreach ($donations as $donation) {
      /** @var Donation $donation */
      $activity_list[] = array(
        'type' => $donation->getName(),
        'date' => $donation->getDate(),
        'amount' => number_format($donation->getAmount(), 2),
      );
    }
  }

  if (empty($activity_list)) {
    $activity_list[] = array(
      array(
        'data' => 'No donations details available.',
        'colspan' => 3,
      )
    );
  }
  $table_data['rows'] = $activity_list;

  return theme('table', $table_data);
}
