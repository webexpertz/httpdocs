<?php

/**
 * @file
 * Rules descriptions for the enterprise connector module.
 */

/**
 * Implements hook_rules_event_info().
 */
function rmets_membership_user_rules_event_info() {
  return array(
    'rmets_membership_user_address_updated' => array(
      'label' => t('After a member updates their address details'),
      'group' => t('RMetS Membership'),
      'variables' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('The user whose address has been updated'),
        ),
        'old_address' => array(
          'type' => 'text',
          'label' => t('The old address'),
        ),
        'new_address' => array(
          'type' => 'text',
          'label' => t('The new address.'),
        ),
        'address_type' => array(
          'type' => 'text',
          'label' => t('The type of the address e.g. Main'),
        ),
      ),
    ),
  );
}
