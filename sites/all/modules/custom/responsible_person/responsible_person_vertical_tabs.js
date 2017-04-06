
(function ($) {

/**
 * Provide summary information for vertical tabs.
 */
Drupal.behaviors.responsible_person_settings = {
  attach: function (context) {
	// Provide summary when editting a node.
	$('fieldset#edit-responsible-person-settings', context).drupalSetSummary(function(context) {
      var vals = [];
      if ($('#edit-rp-uid').val()) {
        vals.push(Drupal.t('Responsible person set'));
      }
      if (!vals.length) {
        vals.push(Drupal.t('No responsible person'));
      }
      return vals.join('<br/>');
    });

    // Provide summary during content type configuration.
    $('fieldset#edit-responsible-person', context).drupalSetSummary(function(context) {
      var vals = [];
      if ($('#edit-responsible-person-enable', context).is(':checked')) {
        vals.push(Drupal.t('Responsible person enabled'));
      }
      return vals.join('<br/>');
    });

  }
};

})(jQuery);
