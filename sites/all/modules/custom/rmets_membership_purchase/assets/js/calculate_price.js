(function ($) {
    var rmets_membership_purchase_calculate_price = function () {
        var price = Number(Drupal.settings.rmets_membership_purchase.subscription_prices[$('#edit-product').val()]);
        if (isNaN(price)) {
            price = 0;
        }
        var donation = $('input#edit-donation');
        if (donation.length) {
            var donation_value = Number(donation.val());
            if (!isNaN(donation_value)) {
                price += donation_value;
            }
        }
        var accred = $('#accred-amount');
        if (accred.length) {
            var accred_value = Number(accred.text());
            if (!isNaN(accred_value)) {
                price += accred_value;
            }
        }
        $('.form-item-journal .form-checkbox:checked').each(function () { price += Number(Drupal.settings.rmets_membership_purchase.journal_prices[$(this).val()]); } );
        $('input[name="price_to_pay"]').val(price.toFixed(2));
        return price.toFixed(2);
    }

    // JavaScript Closure to map your jQuery to '$'.

    Drupal.behaviors.rmets_membership_purchase = {
        attach: function (context, settings) {
            $('input.form-checkbox, #edit-product, #edit-donation').change(function () {
                $('#your-price, #your-price2').html(rmets_membership_purchase_calculate_price());
            });
            $('#edit-product').change(function () {
                if (Drupal.settings.rmets_membership_purchase.students_and_fellows.fellows[$(this).children('option:selected').val()]) {
                    $('.show-to-fellow').removeClass('hidden').show();
                }
                else {
                    $('.show-to-fellow').hide();
                }

                if (Drupal.settings.rmets_membership_purchase.students_and_fellows.students[$(this).children('option:selected').val()]) {
                    $('.show-to-students').removeClass('hidden').show();
                    $('.hide-from-students').hide();
                }
                else {
                    $('.show-to-students').hide();
                    $('.hide-from-students').show();
                }

                if (Drupal.settings.rmets_membership_purchase.students_and_fellows.corporates[$(this).children('option:selected').val()]) {
                    $('.hide-from-corporates').hide();
                    $('.show-to-corporates').removeClass('hidden').show();
                }
                else {
                    $('.hide-from-corporates').show();
                    $('.show-to-corporates').show();
                }

                if (Drupal.settings.rmets_membership_purchase.students_and_fellows.reciprocals[$(this).children('option:selected').val()]) {
                    $('.show-to-reciprocals').removeClass('hidden').show();
                }
                else {
                    $('.show-to-reciprocals').hide();
                }


            });

            if ($('#edit-product').children('option:selected').val().length) {
                $('#edit-product').trigger('change');
            }
        }
    }

    $(function() {
        if ($('input[name="price_to_pay"]').val().length) {
            $('#your-price').html($('input[name="price_to_pay"]').val());
        }
    });



})(jQuery)
