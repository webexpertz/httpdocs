/**
 * Abstract submissions
 * Hide all the group name boxes for normal users.
 */

// Using the closure to map jQuery to $.
(function ($) {

// Store our function as a property of Drupal.behaviors.
Drupal.behaviors.event_map_abstract_form = {
  attach: function (context, settings) {
    var found_all = false;
    var i = 0;
    while (!found_all && i < 20) {
      if ($('.form-item-field-grouped-files-und-' + i + '-group').length) {
        $('.form-item-field-grouped-files-und-' + i + '-group').hide();
        i++;
      }
      else {
        found_all = true;
      }
    }
  }
};

}(jQuery));
