/**
 * @file
 * Rmets committee documents javascript
 */

// Using the closure to map jQuery to $.
(function ($) {

// Store our function as a property of Drupal.behaviors.
Drupal.behaviors.rmets_subscription = {
  attach: function (context, settings) {
    if ($('#rmets-committee-document-create-form').length) {
      if ($('.error').length == 0) {
        $('#rmets-committee-document-create-form').hide();
      }
      $('#rmets-committee-document-create-form').before('<a id="rmets-committee-document-add-new-meeting-link">Add a new meeting</a>');
      $('#rmets-committee-document-add-new-meeting-link').click(function() {
        if ($('#rmets-committee-document-create-form').is(":visible")) {
          $('#rmets-committee-document-add-new-meeting-link').html('Add a new meeting');
          $('#rmets-committee-document-create-form').hide('slow');
        }
        else {
          $('#rmets-committee-document-add-new-meeting-link').html('Close');
          $('#rmets-committee-document-create-form').show('slow');
        }
      });
    }
  }
};

}(jQuery));
