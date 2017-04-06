<?php

/**
 * @file
 * Some replacement tokens for enterprise connector.
 */

/**
 * Implements hook_token_info().
 */
function rmets_membership_user_token_info() {
  return array(
    'tokens' => array(
      'user' => array(
        'changed-address-type' => array(
          'name' => t('Changed address type'),
          'description' => t('If set the user has just changed the address of this type. There will also be old-address and new-address tokens on the user object. This is only available in rules after a user has updated their address.'),
        ),
        'old-address' => array(
          'name' => t('Old address'),
          'description' => t('The users old address'),
        ),
        'new-address' => array(
          'name' => t('New address'),
          'description' => t('The users new address'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_token().
 */
function rmets_membership_user_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'user' && !empty($data['user'])) {
    $account = $data['user'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'old-address' :
          $replacements[$original] = $account->changed_address_details['old-address'];
          break;
        case 'new-address' :
          $replacements[$original] = $account->changed_address_details['new-address'];
          break;
        case 'changed-address-type' :
          $replacements[$original] = $account->changed_address_details['type'];
          break;
      }
    }
  }

  return $replacements;
}
