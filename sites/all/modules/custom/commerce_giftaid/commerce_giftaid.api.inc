<?php

/**
 * @file
 * API details for the commerce_giftaid module.
 */

/**
 * Implements hook_commerce_giftaid_user_default().
 *
 * Allow a module to set the default giftaid status on a
 * giftaid declaration. Useful if you have an external
 * membership system which stores this information.
 *
 * @param int $uid
 *   The Drupal user uid.
 *
 * @return int|NULL
 *   Return 1 if the specified user has already accepted a
 *   giftaid declaration or 0 if they have declined.
 *   Otherwise, return NULL to ignore.
 */
function hook_commerce_giftaid_user_default($uid) {
  $membership_number = enterprise_connector_get_membership_number($uid);
  if ($membership_number) {
    $status = enterprise()->getMemberGiftAidStatus($membership_number);
    return !empty($status);
  }
}
