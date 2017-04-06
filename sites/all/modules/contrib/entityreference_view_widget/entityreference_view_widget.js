(function($) {
Drupal.behaviors.entityreferenceViewWidget = {
  get_widget_settings : function () {
    var settings_selector = '#' + $('#entityreference-view-widget-settings-selector').val();
    return JSON.parse($(settings_selector).val());
  },
  get_base_query_string : function () {
    var widget_settings = this.get_widget_settings();
    return 'element=' + widget_settings.element + '&langcode=' + widget_settings.langcode + '&target_type=' + widget_settings.target_type + '&cardinality=' + widget_settings.cardinality;
  },
  disable_checkboxes : function(disable) {
    var checkboxes = '#modal-content input[name="entity_ids[]"]';
    $(checkboxes).each(function() {
      $(this).attr('disabled', disable);
    });
  },
  ajax_submit_data : function (query_string) {
    var widget_settings = Drupal.behaviors.entityreferenceViewWidget.get_widget_settings();
    $.ajax({
      url: Drupal.settings.basePath + '?q=entityreference_view_widget/ajax',
      type: 'POST',
      dataType: 'html',
      data: query_string,
      success: function(data) {
        data && $('#' + widget_settings.table_id + ' tbody').html(data);
        $('#' + widget_settings.table_id + ' tbody tr').each(function(){
          var el = $(this);
          if (widget_settings.cardinality !== '1') {
            Drupal.tableDrag[widget_settings.table_id].makeDraggable(el.get(0));
            el.find('td:last').addClass('tabledrag-hide');
            if ($.cookie('Drupal.tableDrag.showWeight') == 1) {
              el.find('.tabledrag-handle').hide();
            }
            else {
              el.find('td:last').hide();
            }
          }
        });
        Drupal.behaviors.entityreferenceViewWidget.disable_checkboxes(false);
        widget_settings.close_modal && Drupal.CTools.Modal.dismiss();

        /*$('#modal-content').prepend('<div class="messages status">Updated your selection list.</div>');
        setTimeout(function() {
          $('#modal-content .status').remove();
        }, 2000);*/
      }
    });
  },
  select_all_clicked : function (is_entity_selected) {
    Drupal.behaviors.entityreferenceViewWidget.disable_checkboxes(true);

    var widget_settings = Drupal.behaviors.entityreferenceViewWidget.get_widget_settings();
    var query_string = Drupal.behaviors.entityreferenceViewWidget.get_base_query_string();

    var selected_checkboxes = [];
    var checkboxes = '#modal-content input[name="entity_ids[]"]';
    $(checkboxes).each(function() {
      selected_checkboxes.push($(this).val());
    });

    var select_index = 0;
    $('#' + widget_settings.table_id + ' input[type=checkbox]:checked').each(function(){
      var entity_id = $(this).val();
      if ($.inArray(entity_id, selected_checkboxes) > -1 && !is_entity_selected) {
        return;
      }
      if ($.inArray(entity_id, selected_checkboxes) > -1) {
        selected_checkboxes.splice($.inArray(entity_id, selected_checkboxes), 1);
      }
      query_string += '&entity_ids[' + select_index + ']=' + entity_id;
      select_index++;
    });

    if (is_entity_selected) {
      $.each(selected_checkboxes, function(index, entity_id) {
        query_string += '&entity_ids[' + select_index + ']=' + entity_id;
        select_index++;
      });
    }

    Drupal.behaviors.entityreferenceViewWidget.ajax_submit_data(query_string);
  },
  attach: function(context, settings) {
    $('.ervw-add-items').bind('click',
      function() {
        if (typeof Drupal.settings['views'] != 'undefined') {
          Drupal.settings['views']['ajaxViews'] = null;
        }
      }
    );
    var checkboxes = '#modal-content input[name="entity_ids[]"]';
    var select_all_link = $('.entityreference-view-widget-select-all');
    select_all_link.unbind('click').text('Select all displayed CPD Records').data('unselect', 0).click(function(){
      if ($(this).data('unselect')) {
        $(checkboxes).removeAttr('checked');
        select_all_link.data('unselect', 0).text('Select all displayed CPD Records');
      }
      else {
        $(checkboxes).attr('checked', 'checked');
        select_all_link.data('unselect', 1).text('Unselect all displayed CPD Records');
      }
      Drupal.behaviors.entityreferenceViewWidget.select_all_clicked($(this).data('unselect'));
      return false;
    });
    $('#entityreference-view-widget-modal-submit .button_close').click(function(){
      Drupal.CTools.Modal.dismiss();
    });
    $('#entityreference-view-widget-modal-submit .button_add').click(function(){
      $('#modal-content .error').remove();

      var selected_amount = $(checkboxes + ':checked').length;
      var widget_settings = Drupal.behaviors.entityreferenceViewWidget.get_widget_settings();
      var entity_ids = $(checkboxes).serialize();
      var query_string = entity_ids + '&' + Drupal.behaviors.entityreferenceViewWidget.get_base_query_string();

      $('#' + widget_settings.table_id + ' input[type=checkbox]:checked').each(function(){
        query_string += '&default_entity_ids[' + $(this).data('delta') + ']=' + $(this).val();
        selected_amount++;
      });

      if (widget_settings.cardinality > 0 && widget_settings.cardinality < selected_amount) {
        $('#modal-content').prepend('<div class="messages error">Please select no more than ' + widget_settings.cardinality + ' values.</div>');
      }
      else {
        Drupal.behaviors.entityreferenceViewWidget.ajax_submit_data(query_string);
      }
    });
    $('#modal-content .submit_on_click').unbind('click').click(function() {
      //$('#modal-content .status').remove();

      var widget_settings = Drupal.behaviors.entityreferenceViewWidget.get_widget_settings();
      var query_string = Drupal.behaviors.entityreferenceViewWidget.get_base_query_string();
      var selected_entity_id = $(this).val();
      var is_entity_selected = $(this).attr('checked');

      $('#' + widget_settings.table_id + ' input[type=checkbox]:checked').each(function(){
        var entity_id = $(this).val();
        if (entity_id == selected_entity_id && !is_entity_selected) {
          return;
        }
        query_string += '&entity_ids[' + $(this).data('delta') + ']=' + entity_id;
      });

      if (is_entity_selected) {
        query_string += '&entity_ids[' + $('#' + widget_settings.table_id + ' input[type=checkbox]:checked').length + ']=' + selected_entity_id;
      }

      Drupal.behaviors.entityreferenceViewWidget.ajax_submit_data(query_string);
    });
  }
}
})(jQuery);
