(function ($) {
    var rmets_events_calculate_price = function () {
        //console.log('here' + Math.random());
        var price = Number(Drupal.settings.rmets_events.fees_prices[$('#edit-fees').val()]);
        if (isNaN(price)) {
            price = 0;
        }
        $('.form-item-optional-extras .form-checkbox:checked').each(function () { price += Number(Drupal.settings.rmets_events.options_prices[$(this).val()]); } );
        $('input[name="price_to_pay"]').val(price);
        return price;
    };

    var changed = function () {
        $('#your-price').html(rmets_events_calculate_price());
    };

    // JavaScript Closure to map your jQuery to '$'.

    Drupal.behaviors.rmets_event = {
        attach: function (context, settings) {
            //console.log(context);
            $('#edit-fees').once('fees', function(context, settings) {
                $('#edit-fees').bind("change.rmets_events", changed);
                if ($('#edit-fees').children('option:selected').val().length) {
                    $('#edit-fees').trigger('change');
                }
            });
            $('#rmets-events-registration-form').ajaxComplete(function(event, xhr, settings) {
                if (event.target.id == 'rmets-events-registration-form') {
                    // Your code here
                    $('.form-item-optional-extras .form-checkbox').once('optionals', function () {
                        $('.form-item-optional-extras .form-checkbox').unbind("change.rmets_events_optional").bind("change.rmets_events_optional", changed );
                        $('.form-item-optional-extras .form-checkbox:first').trigger('change');
                    });
                    //console.log($('.form-item-optional-extras .form-checkbox').length);
                    if ($('.form-item-optional-extras .form-checkbox').length < 1) {
                        $('#dropdown-second-replace').hide();
                    } else {
                        $('#dropdown-second-replace').show();
                    }
                }
            });
        }
    };

    $(function() {
        if ($('input[name="price_to_pay"]').val().length) {
            $('#your-price').html($('input[name="price_to_pay"]').val());
        }
    });

})(jQuery)
