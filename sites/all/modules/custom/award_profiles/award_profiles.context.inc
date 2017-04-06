<?php
/**
 * @file
 * award_profiles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function award_profiles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'award_profiles_people';
  $context->description = 'Context which fires when viewing an accreditations and awards person';
  $context->tag = 'award_profiles';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'award_profile' => 'award_profile',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'node/3419',
    'menu' => 'node/3419',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context which fires when viewing an accreditations and awards person');
  t('award_profiles');
  $export['award_profiles_people'] = $context;

  return $export;
}
