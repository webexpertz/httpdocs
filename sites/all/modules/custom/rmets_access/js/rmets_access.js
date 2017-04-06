/**
 * Add some dynamic choices to the create new account form.
 */

// Using the closure to map jQuery to $.
(function ($) {

// Store our function as a property of Drupal.behaviors.
Drupal.behaviors.rmets_access = {
  attach: function (context, settings) {

    var update_form = function() {
      switch ($('input[name=membership_level]:checked', '#user-register-form').val()) {
        case '1' :
          // Existing member.
          $('#edit-field-membership-number').show();
          $('#edit-field-dateofbirth').show();
          break;
        case '2':
          // Corporate member.
          $('#edit-field-membership-number').show();
          $('#edit-field-dateofbirth').hide();
          break;
        case '3':
          // Non member.
          $('#edit-field-membership-number').hide();
          $('#edit-field-dateofbirth').show();
          break;
      }
    }

    update_form();

    $('input[name=membership_level]').change(update_form);
  }
};

}(jQuery));
