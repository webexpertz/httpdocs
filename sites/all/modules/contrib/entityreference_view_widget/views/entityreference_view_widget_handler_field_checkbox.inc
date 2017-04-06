<?php

/**
 * Provides the checkbox field to tick the view rows and set them as field values.
 */
class entityreference_view_widget_handler_field_checkbox extends views_handler_field {
  var $revision = FALSE;

  function render($values) {
    $entity_id = $values->{$this->view->base_field};
    if (empty($entity_id)) {
      return;
    }

    $submit_on_selection = $this->options['ervw']['submit_on_selection'];
    if (in_array($entity_id, _entityreference_view_widget_modal__get_submitted_eids())) {
      $checked = ' checked="checked"';
      if (!$submit_on_selection) {
        $checked .= ' disabled="disabled"';
      }
    }
    else {
      $checked = '';
    }
    $class = ($submit_on_selection) ? ' class="submit_on_click"' : '';

    return '<input name="entity_ids[]" type="checkbox" value="' . $entity_id . '"' . $checked . $class . ' />';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['ervw'] = array(
      'contains' => array(
        'force_single' => array('default' => FALSE),
        'submit_on_selection' => array('default' => FALSE),
      ),
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['ervw'] = array(
      '#type' => 'fieldset',
      '#title' => t('Entity Reference Views Widget'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['ervw']['force_single'] = array(
      '#type' => 'checkbox',
      '#title' => t('Force single'),
      '#default_value' => $this->options['ervw']['force_single'],
      '#description' => t('Check this box to restrict selection to a single value.'),
    );

    // @todo move to the config on the form instead?
    $form['ervw']['submit_on_selection'] = array(
      '#type' => 'checkbox',
      '#title' => t('Submit values on selection'),
      '#default_value' => $this->options['ervw']['submit_on_selection'],
      '#description' => t('Check this box to submit the values of the selection whenever the checkbox is checked/unchecked.'),
    );
  }
}
