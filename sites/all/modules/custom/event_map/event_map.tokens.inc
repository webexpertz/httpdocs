<?php

/**
 * @file
 */

/**
 * Implements hook_token_info().
 */
function event_map_token_info() {
  return array(
    'tokens' => array(
      'node' => array(
        'event-session' => array(
          'name' => t('Node reference'),
          'description' => t('Node referenced via field_event_session'),
          'type' => 'node',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function event_map_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'event-session' :
          $default = '';
          if (isset($node->field_event_session)) {
             $event_session = entity_metadata_wrapper('node', $node)->field_event_session->value();
            $default = $event_session->title;
          }
          $replacements[$original] = $sanitize ? filter_xss($default) : $default;
          break;
      }
    }

    if (isset($node->field_event_session) && $event_session_tokens = token_find_with_prefix($tokens, 'event-session')) {
      $event_session = entity_metadata_wrapper('node', $node)->field_event_session->value();
      $replacements += token_generate('node', $event_session_tokens, array('node' => $event_session), $options);
    }
  }
  return $replacements;
}
