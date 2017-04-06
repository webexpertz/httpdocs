<?php
/**
 * @file
 * rmets_system.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rmets_system_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'checkout';
  $context->description = 'In the checkout process';
  $context->tag = 'rmets_system';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'cart' => 'cart',
        'cart/*' => 'cart/*',
        'checkout' => 'checkout',
        'checkout/*' => 'checkout/*',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'no-sidebar',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('In the checkout process');
  t('rmets_system');
  $export['checkout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'corporate_members';
  $context->description = 'Corporate member pages';
  $context->tag = 'corproate_members';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'corporate_member' => 'corporate_member',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'node/4609',
    'menu' => 'node/4609',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Corporate member pages');
  t('corproate_members');
  $export['corporate_members'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event_node';
  $context->description = 'Set body tag on event nodes';
  $context->tag = 'event_map';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'event-node',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Set body tag on event nodes');
  t('event_map');
  $export['event_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events';
  $context->description = 'Set the events context when inside any level of an event';
  $context->tag = 'event_map';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
        'event_abstract' => 'event_abstract',
        'event_session' => 'event_session',
        'event_subsession' => 'event_subsession',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'abstracts/*' => 'abstracts/*',
        'abstracts/*/*' => 'abstracts/*/*',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Set the events context when inside any level of an event');
  t('event_map');
  $export['events'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'image_gallery';
  $context->description = 'Event that occurs on image gallery nodes';
  $context->tag = 'image_gallery';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'image_gallery' => 'image_gallery',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'weather-and-climate/image-gallery',
    'menu' => 'weather-and-climate/image-gallery',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Event that occurs on image gallery nodes');
  t('image_gallery');
  $export['image_gallery'] = $context;

  return $export;
}
