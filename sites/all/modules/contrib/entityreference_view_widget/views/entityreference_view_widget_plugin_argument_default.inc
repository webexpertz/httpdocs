<?php
/**
 * @file entityreference_view_widget_plugin_argument_default.inc
 */

/**
 * Default argument plugin to the provide the selected entity ids.
 *
 * @ingroup views_argument_default_plugins
 */
class entityreference_view_widget_plugin_argument_default extends views_plugin_argument_default {

  /**
   * @return string.
   */
  function get_argument() {
    $eids = _entityreference_view_widget_modal__get_submitted_eids();
    return implode(',', $eids);
  }
}
