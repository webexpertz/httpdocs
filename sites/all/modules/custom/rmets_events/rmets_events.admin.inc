<?php

/**
 * Menu callback: confirm syncing awards.
 */
function rmets_events_crm_sync_confirm() {
  return confirm_form(array(), t('Are you sure you want to sync events from CRM?'),
    'admin/reports/status', t('This action synchronises events with CRM and may be a lengthy process.'), t('Begin synchronisation'), t('Cancel'));
}

/**
 * Handler for wipe confirmation
 */
function rmets_events_crm_sync_confirm_submit($form, &$form_state) {
  rmets_events_update_nodes_from_crm();
  $form_state['redirect'] = 'admin/reports/status';
}