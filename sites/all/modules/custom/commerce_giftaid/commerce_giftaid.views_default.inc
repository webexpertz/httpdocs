<?php

/**
 * @file
 * Views exports.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_giftaid_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'gift_aid_report';
  $view->description = 'A view listing line item sales where the user agreed to the gift aid declaration';
  $view->tag = 'default';
  $view->base_table = 'commerce_line_item';
  $view->human_name = 'Gift aid report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Gift aid report';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Commerce Line Item: Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['required'] = 1;
  /* Field: Commerce Line Item: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['path'] = 'admin/commerce/orders/[order_id]/view';
  $handler->display->display_options['fields']['order_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['order_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['order_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['order_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['order_id']['hide_alter_empty'] = 1;
  /* Field: Commerce Line item: Product */
  $handler->display->display_options['fields']['commerce_product']['id'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['fields']['commerce_product']['field'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_product']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_product']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_product']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_product']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['commerce_product']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_product']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_product']['empty_zero'] = 0;
  $handler->display->display_options['fields']['commerce_product']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['commerce_product']['type'] = 'commerce_product_reference_title_link';
  $handler->display->display_options['fields']['commerce_product']['settings'] = array(
    'show_quantity' => 0,
    'default_quantity' => '1',
    'combine' => 1,
    'line_item_type' => 0,
  );
  $handler->display->display_options['fields']['commerce_product']['field_api_classes'] = 0;
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['quantity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['quantity']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['quantity']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['quantity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['quantity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['quantity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['quantity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['quantity']['set_precision'] = 0;
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  $handler->display->display_options['fields']['quantity']['format_plural'] = 0;
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['commerce_unit_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_unit_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['commerce_unit_price']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_unit_price']['field_api_classes'] = 0;
  /* Sort criterion: Commerce Line Item: Order ID */
  $handler->display->display_options['sorts']['order_id']['id'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['order_id']['field'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['order'] = 'DESC';
  /* Filter criterion: Field: Giftaid (commerce_product_giftaid) */
  $handler->display->display_options['filters']['commerce_product_giftaid_value']['id'] = 'commerce_product_giftaid_value';
  $handler->display->display_options['filters']['commerce_product_giftaid_value']['table'] = 'field_data_commerce_product_giftaid';
  $handler->display->display_options['filters']['commerce_product_giftaid_value']['field'] = 'commerce_product_giftaid_value';
  $handler->display->display_options['filters']['commerce_product_giftaid_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['state']['value'] = array(
    'completed' => 'completed',
  );

  /* Display: Gift aid report page */
  $handler = $view->new_display('page', 'Gift aid report page', 'gift_aid_report_page');
  $handler->display->display_options['display_description'] = 'The main gift aid report page';
  $handler->display->display_options['path'] = 'admin/commerce/orders/gift-aid-report';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Gift aid report';
  $handler->display->display_options['menu']['description'] = 'The gift aid report';
  $handler->display->display_options['menu']['weight'] = '0';

  $views[$view->name] = $view;
  return $views;
}
