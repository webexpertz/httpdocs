
(function ($) {

/**
 * Provide summary information for vertical tabs.
 */
Drupal.behaviors.schedule_review_settings = {
  attach: function (context) {
	// Provide summary when editting a node.
	$('fieldset#edit-schedule-review-settings', context).drupalSetSummary(function(context) {
      var vals = [];
      if ($('#edit-review-on').val() || $('#edit-review-on-datepicker-popup-0').val()) {
        vals.push(Drupal.t('Scheduled for review'));
      }
      if (!vals.length) {
        vals.push(Drupal.t('Not scheduled'));
      }
      return vals.join('<br/>');
    });

    // Provide summary during content type configuration.
    $('fieldset#edit-schedule-review', context).drupalSetSummary(function(context) {
      var vals = [];
      if ($('#edit-schedule-review-enable', context).is(':checked')) {
        vals.push(Drupal.t('Review enabled'));
      }
      return vals.join('<br/>');
    });

  }
};

})(jQuery);
