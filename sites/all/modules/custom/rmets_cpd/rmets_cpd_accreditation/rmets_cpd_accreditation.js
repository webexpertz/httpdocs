
(function($) {
  Drupal.behaviors.rmets_cpd_accreditation = {
    attach: function(context, settings) {
      var education = $('fieldset.horizontal-tabs-pane.group-education-prof-training');
      if (education.length > 0) {
        education.data('horizontalTab').link.find('strong:first').parent().find('span').remove();
        education.data('horizontalTab').link.find('strong:first').after($('.form-required').eq(0).clone()).after(' ');
      }

      var work_experience = $('fieldset.horizontal-tabs-pane.group-relevant-work-experience');
      if (work_experience.length > 0) {
        work_experience.data('horizontalTab').link.find('strong:first').parent().find('span').remove();
        work_experience.data('horizontalTab').link.find('strong:first').after($('.form-required').eq(0).clone()).after(' ');
      }
    }
  };
})(jQuery);
