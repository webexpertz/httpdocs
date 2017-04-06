<?php
/**
 * @file
 * legacies_fund.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function legacies_fund_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'legacies_fund';
  $context->description = '';
  $context->tag = 'legacies_fund';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'legacies_fund' => 'legacies_fund',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'node/4541',
    'menu' => 'node/4536',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('legacies_fund');
  $export['legacies_fund'] = $context;

  return $export;
}
