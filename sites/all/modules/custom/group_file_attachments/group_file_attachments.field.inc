<?php

/**
 * @file
 * Implement an image field, based on the file module's file field.
 */

/**
 * Implements hook_field_info().
 */
function group_file_attachments_field_info() {
  return array(
    'group_file_attachments' => array(
      'label' => t('Grouped Files'),
      'description' => t('This field stores the ID of an image file as an integer value.'),
      'settings' => array(
        'display_field' => 0,
        'display_default' => 0,
        'uri_scheme' => variable_get('file_default_scheme', 'public'),
      ),
      'instance_settings' => array(
        'file_extensions' => 'pdf docx doc xls xlsx ppt pptx mp3 pot potx',
        'file_directory' => '',
        'max_filesize' => '',
        'description_field' => 0,
        'group_field' => 0,
      ),
      'default_widget' => 'group_file_attachments',
      'default_formatter' => 'group_file_attachments',
    ),
  );
}

/**
 * Implements hook_field_settings_form().
 */
function group_file_attachments_field_settings_form($field, $instance, $has_data) {
  return file_field_settings_form($field, $instance, $has_data);
}

/**
 * Implements hook_field_instance_settings_form().
 */
function group_file_attachments_field_instance_settings_form($field, $instance) {
  $settings = $instance['settings'];
  $form = file_field_instance_settings_form($field, $instance);

  $form['group_field'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable <em>Group</em> field'),
    '#default_value' => isset($settings['group_field']) ? $settings['group_field'] : '',
    '#description' => t('The group field allows users to group files together on the display.'),
    '#parents' => array('instance', 'settings', 'group_field'),
    '#weight' => 12,
  );

  return $form;
}

/**
 * Implements hook_field_load().
 */
function group_file_attachments_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  file_field_load($entity_type, $entities, $field, $instances, $langcode, $items, $age);
}

/**
 * Implements hook_field_prepare_view().
 */
function group_file_attachments_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items) {
   //file_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, $items);
}

/**
 * Implements hook_field_presave().
 */
function group_file_attachments_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_presave($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_insert().
 */
function group_file_attachments_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_insert($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_update().
 */
function group_file_attachments_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_update($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_delete().
 */
function group_file_attachments_field_delete($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_delete($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_delete_revision().
 */
function group_file_attachments_field_delete_revision($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_delete_revision($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_is_empty().
 */
function group_file_attachments_field_is_empty($item, $field) {
  return file_field_is_empty($item, $field);
}

/**
 * Determine whether a file should be displayed when outputting field content.
 *
 * @param $item
 *   A field item array.
 * @param $field
 *   A field array.
 * @return
 *   Boolean TRUE if the file will be displayed, FALSE if the file is hidden.
 */
function group_file_attachments_field_displayed($item, $field) {
  return file_field_displayed($item, $field);
}

/**
 * Implementation of hook_field_formatter_info().
 */
function group_file_attachments_field_formatter_info() {
  return array(
    'group_file_attachments' => array(
      'label' => t('Files arranged in groups'),
      'field types' => array('group_file_attachments'),
    ),
  );
}

/**
 * Implements hook_field_widget_info().
 */
function group_file_attachments_field_widget_info() {
  return array(
    'group_file_attachments' => array(
      'label' => t('Grouped files'),
      'field types' => array('group_file_attachments'),
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
  );
}


/**
 * Implements hook_field_widget_settings_form().
 */
function group_file_attachments_field_widget_settings_form($field, $instance) {
  $widget = $instance['widget'];
  $settings = $widget['settings'];

  // Use the file widget settings form.
  $form = file_field_widget_settings_form($field, $instance);

  return $form;
}


/**
 * Implements hook_field_widget_form().
 */
function group_file_attachments_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {

  // Add display_field setting to field because file_field_widget_form() assumes it is set.
  $field['settings']['display_field'] = 0;

  $elements = file_field_widget_form($form, $form_state, $field, $instance, $langcode, $items, $delta, $element);
  $settings = $instance['settings'];

  foreach (element_children($elements) as $delta) {
    $elements[$delta]['#columns'][] = 'group';
    $elements[$delta]['#process'][] = 'group_file_attachments_field_widget_process';
  }

  if ($field['cardinality'] == 1) {
    if (empty($elements[0]['#default_value']['fid'])) {
      $elements[0]['#description'] = theme('file_upload_help', array('description' => $instance['description'], 'upload_validators' => $elements[0]['#upload_validators']));
    }
  }
  else {
    $elements['#file_upload_description'] = theme('file_upload_help', array('upload_validators' => $elements[0]['#upload_validators']));
  }

  return $elements;
}

/**
 * An element #process callback for the group_file_attachments_image field type.
 *
 * Expands the group_file_attachments_image type to include the group field.
 */
function group_file_attachments_field_widget_process($element, &$form_state, $form) {
  $item = $element['#value'];
  $item['fid'] = $element['fid']['#value'];

  $element['group'] = array(
    '#type' => 'textfield',
    '#title' => t('Group'),
    '#default_value' => isset($item['group']) ? $item['group'] : '',
    '#maxlength' => 128,
    '#description' => t('The group this file belongs in'),
  );
  //PJB reinstate the description
  $element['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#default_value' => isset($item['description']) ? $item['description'] : '',
    '#maxlength' => 128,
    '#description' => t('The description of the file'),
  );

  return $element;
}

/**
 * Returns HTML for an image field widget.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element representing the image field widget.
 *
 * @ingroup themeable
 */
function theme_group_file_attachments_widget($variables) {
  $element = $variables['element'];
  $output = '';

  // The "form-managed-file" class is required for proper Ajax functionality.
  $output .= '<div class="file-widget form-managed-file clearfix">';
  if ($element['fid']['#value'] != 0) {
    // Add the file size after the file name.
    $element['filename']['#markup'] .= ' <span class="file-size">(' . format_size($element['#file']->filesize) . ')</span> ';
  }
  $output .= drupal_render_children($element);
  $output .= '</div>';

  return $output;
}

/**
 * Implements hook_field_formatter_view().
 */
function group_file_attachments_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $items['entity'] = $entity;
  $element = array();
  $element[0] = array(
    '#theme' => 'file_formatter_group_file_attachments',
    '#items' => $items,
  );
  return $element;
}

/**
 * Returns HTML for a grouped file attachments table.
 *
 * @param $variables
 *   An associative array containing:
 *   - items: An array of file attachments.
 *
 * @ingroup themeable
 */
function theme_file_formatter_group_file_attachments($variables) {
  $items = $variables['items'];
  $entity = $items['entity'];
  unset($items['entity']);
  $groups = array();
  $groups_output = array();

  foreach ($items as $delta => $item) {
    $mime = explode('.', $item['filemime']);
    $mime = $mime[count($mime) - 1];
    $groups[check_plain($item['group'])][] = array(
      'link' => theme('file_link', array('file' => (object) $item)),
      'mime' => str_replace('application/', '', $mime),
    );
  }

  foreach ($groups as $group => $rows) {
    if (!empty($rows)) {
      $groups_output[] = array('title' => ($group && count($groups)) ? $group : '', 'content' => theme('group_file_attachments_group', array('group' => $rows)));
    }
  }

  return empty($groups_output) ? '' : theme('group_file_attachments', array('groups' => $groups_output, 'entity' => $entity));
}
