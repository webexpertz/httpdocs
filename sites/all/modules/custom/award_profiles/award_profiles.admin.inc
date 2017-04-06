<?php

/**
 * @file
 */

/**
 * Menu callback: confirm syncing awards.
 */
function crm_sync_awards_confirm() {
  return confirm_form(array(), t('Are you sure you want to sync awards from CRM?'),
                  'admin/reports/status', t('This action synchronises awards with CRM and may be a lengthy process.'), t('Begin synchronisation'), t('Cancel'));
}

/**
 * Handler for wipe confirmation
 */
function crm_sync_awards_confirm_submit($form, &$form_state) {
  _award_profiles_sync_all(TRUE);
  $form_state['redirect'] = 'admin/reports/status';
}
