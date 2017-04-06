<?php
/**
 * @file
 * rmets_news.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rmets_news_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'news',
    'menu' => 'news',
  );
  $context->condition_mode = 0;
  $export['news'] = $context;

  return $export;
}
