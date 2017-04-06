<?php

/**
 * @file
 * Template overrides for rmets theme
 */

/**
 * Preprocess the page.
 */
function rmets_preprocess_page(&$variables) {
  // Ensure a sidebar_first and sodebar_second variable exists for the template files.
  $variables['sidebar_first'] = isset($variables['sidebar_first']) ? $variables['sidebar_first'] : FALSE;
  $variables['sidebar_second'] = isset($variables['sidebar_second']) ? $variables['sidebar_second'] : FALSE;

  // Set the classes on the middle div.
  $variables['middle_classes'] = array('left', 'block', 'clearfix');

  // Set the myaccount link details.
  $variables['my_account_link'] = FALSE;
  if (user_is_logged_in()) {
    global $user;
    $variables['my_account_link'] = l(t('My account'), 'user/' . $user->uid . '/edit');
  }

  // Set the basket_items variable which holds the total amount
  // (money) in the current order.
  $order = commerce_cart_get_properties(FALSE, array(), 'current_cart_order');
  $variables['basket_items'] = '&pound;0.00';
  if (!empty($order->commerce_line_items)) {
    $price = entity_metadata_wrapper('commerce_order', $order)->commerce_order_total->value();
    $variables['basket_items'] = commerce_currency_format($price['amount'], $price['currency_code']);
  }

  $variables['checkout_link'] = FALSE;
  if (!empty($order->commerce_line_items)) {
    $variables['checkout_link'] = l(t('Checkout'), 'checkout');
  }
}

/**
 * Add body classes if certain regions have content.
 */
function rmets_preprocess_html(&$variables) {

  if (!empty($variables['page']['sidebar_first'])) {
    $variables['classes_array'][] = 'sidebar-first';
  }

  if (!empty($variables['page']['featured'])) {
    $variables['classes_array'][] = 'featured';
  }

  if (!empty($variables['page']['triptych_first'])
    || !empty($variables['page']['triptych_middle'])
  || !empty($variables['page']['triptych_last'])) {
    $variables['classes_array'][] = 'triptych';
  }

  if (!empty($variables['page']['footer_firstcolumn'])
    || !empty($variables['page']['footer_secondcolumn'])
    || !empty($variables['page']['footer_thirdcolumn'])
    || !empty($variables['page']['footer_fourthcolumn'])) {
    $variables['classes_array'][] = 'footer-columns';
    }

  $variables['http'] = function_exists('rmets_system_get_protocol') ? rmets_system_get_protocol() : 'http';

}

/**
 * Override or insert variables into the page template for HTML output.
 */
function rmets_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

/**
 * Override or insert variables into the page template.
 */
function rmets_process_page(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
function rmets_preprocess_maintenance_page(&$variables) {
  // Some errors occur after the page has started rendering.
  // Clean the object buffer.
  ob_clean();
  if (!$variables['db_is_active']) {
    unset($variables['site_name']);
  }
  drupal_add_css(drupal_get_path('theme', 'rmets') . '/css/maintenance-page.css');
}

/**
 * Override or insert variables into the maintenance page template.
 */
function rmets_process_maintenance_page(&$variables) {
  // Some errors occur after the page has started rendering.
  // Clean the object buffer.
  ob_clean();
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
}

/**
 * Override or insert variables into the node template.
 */
function rmets_preprocess_node(&$variables) {
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full' && node_is_page($node)) {
    $variables['classes_array'][] = 'node-full';
  }

  $node_type_preprocess = 'rmets_preprocess_node_' . $node->type;
  if (function_exists($node_type_preprocess)) {
    $node_type_preprocess($variables);
  }
}

/**
 * Override or insert variables into the block template.
 */
function rmets_preprocess_block(&$variables) {
  // In the header region visually hide block titles.
  if ($variables['block']->region == 'header') {
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }
}

function rmets_preprocess_field(&$variables, $hook) {
  //kpr($variables['element']);
  if ($variables['element']['#field_name'] == 'field_landing_page_bottom') {
    //debug('this');
    $variables['classes_array'][] = 'clearfix';
  }
}

/**
 * Implements theme_menu_tree().
 */
function rmets_menu_tree($variables) {
  return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_field__field_type().
 */
function rmets_field__taxonomy_term_reference($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
  }

  // Render the items.
  $output .= ($variables['element']['#label_display'] == 'inline') ? '<ul class="links inline">' : '<ul class="links">';
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
  }
  $output .= '</ul>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . (!in_array('clearfix', $variables['classes_array']) ? ' clearfix' : '') . '">' . $output . '</div>';

  return $output;
}

/**
 * Theme the system main menu - here we add the
 * megamenu and absolute links for doc-lib and events
 */
function rmets_links__system_main_menu($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);
      $link['absolute'] = TRUE;

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
           && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l(check_plain($link['title']), $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      if ($link['title'] != 'Home') {
        $key_class = explode(' ', $key);
        $mlid = explode('-', $key_class[0]);
        $output .= '<div class="sub">' . rmets_menu_get_megamenu($mlid[1]) . '</div>';
      }
      $output .= "</li>\n";

    }
    $output .= '</ul>';
  }

  return $output;
}

/**
 * Override the template to add the link title as a description
 */
function rmets_link_formatter_link_default($vars) {
  $link_options = $vars['element'];
  unset($link_options['element']['title']);
  unset($link_options['element']['url']);

  // Issue #1199806 by ss81: Fixes fatal error when the link URl is equal to page URL
  if (isset($link_options['attributes']['class'])) {
    $link_options['attributes']['class'] = array($link_options['attributes']['class']);
  }

  // Display a normal link if both title and URL are available.
  if (!empty($vars['element']['title']) && !empty($vars['element']['url'])) {
    $help = isset($link_options['attributes']['title']) ? '<p class="help">' . check_plain($link_options['attributes']['title']) . '</p>' : '';
    return l(check_plain($vars['element']['title']), $vars['element']['url'], $link_options) . $help;
  }
  // If only a title, display the title.
  elseif (!empty($vars['element']['title'])) {
    return check_plain($vars['element']['title']);
  }
  elseif (!empty($vars['element']['url'])) {
    return l(check_plain($vars['element']['title']), $vars['element']['url'], $link_options);
  }
}

function rmets_field__field_image__news($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  $dir = arg(0) == 'news' || drupal_is_front_page() ? 'left' : 'right';
  $output .= '<div class="field-items rounded ' . $dir . ' image-wrapper"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

function rmets_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
//  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  return '<span class="file">' . l($link_text, $url, $options) .
    '<span class="type"> ' . strtoupper(preg_replace(':application/:' , '', $file->filemime)) . ' ' . format_size($file->filesize) . '</span>
    </span>';
/*
  return '<span class="file">' . l(check_plain($link_text), $url, $options) .
    '<span class="type"> ' . strtoupper(preg_replace(':application/:' , '', $file->filemime)) . ' ' . format_size($file->filesize) . '</span>
    <br />' . (isset($file->description) ? check_plain($file->description) : '') . '
    </span>';
*/
}

/**
 * Override theme_form_element to get rid of some drupal rubbish
 */
function rmets_form_element($variables) {
  $element = &$variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  if (isset($element['#noprefix']) && $element['#noprefix']) {
    $output = '';
  }
  else {
    $output = '<div' . drupal_attributes($attributes) . '>' . "\n";
  }

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  if (isset($element['#noprefix']) && $element['#noprefix']) {
    $output .= "\n";
  }
  else {
    $output .= "</div>\n";
  }

  return $output;
}

function rmets_menu_link__menu_block__1(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  $element['#attributes']['class'][] = 'collapsed';
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function rmets_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    $args = arg();

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= implode('', $breadcrumb);

    if (!context_isset('context', 'events') && !_apachesolr_is_search_page()) {
      // The event_map module handles all the event type breadcrumbs
      // as the title of a page is often the event, but that's not
      // the last item in the breadcrumb trail.
      $output .= drupal_get_title();
    }

    return $output;
  }
}

/**
 * surely this should be in apachesolr
 */


/**
 * Preprocess stock control display.
 * If stock control is disabled, we just want to say "In stock".
 */
function rmets_field__expert__commerce_stock(&$vars) {
  $product = $vars['element']['#object'];
  if (isset($product->commerce_stock_override) && entity_metadata_wrapper('commerce_product', $product)->commerce_stock_override->value()) {
    foreach ($vars['items'] as $id => $item) {
      $vars['items'][$id]['#markup'] = '<span class="green">In stock</a>';
    }
  }
  return theme_ds_field_expert($vars);
}

/**
 * Hide the abstract id from non admins.
 */
function rmets_field__expert__event_map_nid(&$vars) {
  if (!user_access('administer rmets events')) {
    $vars['label_hidden'] = TRUE;
    $vars['items'][0]['#markup'] = '';
  }
  return theme_ds_field_expert($vars);
}

/**
 * Preprocess name field for accreditations.
 */
function rmets_field__expert__field_surname(&$vars) {
  $vars['items'][0]['#markup'] = ' ' . $vars['items'][0]['#markup'];
  return theme_ds_field_expert($vars);
}

/**
 * Preprocess name field for accreditations.
 */
function rmets_field__expert__field_suffix(&$vars) {
  $vars['items'][0]['#markup'] = ' ' . $vars['items'][0]['#markup'];
  return theme_ds_field_expert($vars);
}

/**
 * Preprocess name field for event date and time.
 */
function rmets_field__expert__field_event_date(&$vars) {
  //$vars['items'][0]['#markup'] = ' ' . $vars['items'][0]['#markup'];
  $timestamps = explode(' to ', $vars['items'][0]['#markup']);

  $vars['items'][0]['#markup'] = date('l j F Y', $timestamps[0]);
  $vars['label'] = t('Date');

  if (isset($timestamps[1])) {
    $date2 = date('l j F Y', $timestamps[1]);
    if ($date2 != $vars['items'][0]['#markup']) {
      $vars['items'][0]['#markup'] .= ' - ' . $date2;
    }
  }

  $output = theme_ds_field_expert($vars);

  $vars['items'][0]['#markup'] = date('H:i', $timestamps[0]);
  $start_date = date('Ymd', $timestamps[0]);
  $end_date =(isset($timestamps[1])) ? date('Ymd', $timestamps[1]) : 0;
  if ($vars['items'][0]['#markup'] != '00:00' && $start_date === $end_date) {
    // Also show the time if past midnight on the same day.
    $vars['label'] = t('Time');

    if (isset($timestamps[1])) {
      $time2 = date('H:i', $timestamps[1]);
      if ($time2 != '00:00' && $time2 != $vars['items'][0]['#markup']) {
        $vars['items'][0]['#markup'] .= ' - ' . $time2;
      }
    }

    $output .= theme_ds_field_expert($vars);
  }

  return $output;
}

/**
 * Preprocess name field for event abstract date and time.
 */
function rmets_field__expert__field_abstract_time_and_date(&$vars) {
  $timestamps = explode(' to ', $vars['items'][0]['#markup']);

  $vars['items'][0]['#markup'] = date('l j F Y', $timestamps[0]);
  $vars['label'] = t('Date');
  $output = theme_ds_field_expert($vars);

  // Also show the time if past midnight.
  $time = date('H:i', $timestamps[0]);
  if ($time != '00:00') {
    $time = count($timestamps) == 2 ? $time . ' - ' . date('H:i', $timestamps[1]) : $time;
    $vars['label'] = t('Time');
    $vars['items'][0]['#markup'] = $time;
    $output .= theme_ds_field_expert($vars);
  }

  return $output;
}

/**
 * DS Preprocess function.
 */
function rmets_field__expert__field_accreditation_address(&$vars) {
  return _rmets_ds_field_remove_if_empty($vars);
}

function rmets_field__expert__field_current_employment(&$vars) {
  return _rmets_ds_field_remove_if_empty($vars);
}

function rmets_field__expert__field_employment_history(&$vars) {
  return _rmets_ds_field_remove_if_empty($vars);
}

function rmets_field__expert__field_expertise(&$vars) {
  return _rmets_ds_field_remove_if_empty($vars);
}

function rmets_field__expert__field_countries(&$vars) {
  return _rmets_ds_field_remove_if_empty($vars);
}

function rmets_field__expert__field_languages(&$vars) {
  return _rmets_ds_field_remove_if_empty($vars);
}

/**
 * Helper function.
 * If the markup field is empty do not include the field.
 */
function _rmets_ds_field_remove_if_empty(&$vars) {
  if (empty($vars['items'][0]['#markup'])) {
    return '';
  }
  return theme_ds_field_expert($vars);
}

/**
 * Theme image field.
 */
function rmets_field__field_image($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  if (!drupal_is_front_page()) {
    $output .= '<div class="image-wrapper rounded right">';
  }
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= drupal_render($item);
  }
  if (!drupal_is_front_page()) {
    $output .= '</div>';
  }

  return $output;
}

/**
 * Theme the feed icon.
 */
function rmets_feed_icon($variables) {
  $text = t('Subscribe to @feed-title', array('@feed-title' => $variables['title']));
  if ($image = theme('image', array('path' => 'misc/feed.png', 'width' => 16, 'height' => 16, 'alt' => $text))) {
    return l(t('RSS feed'), $variables['url'], array('html' => TRUE, 'attributes' => array('class' => array('feed-icon rss right'), 'title' => $text)));
  }
}

/**
 * Theme the pager controls.
 */
function rmets_pager_link(&$variables) {
  if (!is_numeric($variables['text'])) {
    $variables['attributes']['class'][] = 'button-link-small';
  }
  return theme_pager_link($variables);
}

/**
 * Preprocess search results.
 */
function rmets_preprocess_search_result(&$vars) {
  $vars['teaser'] = FALSE;
  if (arg(1) == 'image-gallery' || arg(0) == 'events') {
    $node = node_load($vars['result']['fields']['entity_id']);
    $node_view = node_view($node, 'teaser');
    $vars['teaser'] = empty($node) ? '' : render($node_view);
  }
}

/**
 * Extra preprocess for event nodes.
 */
function rmets_preprocess_node_event(&$vars) {
  $node = $vars['node'];
  $vars['abstract_available'] = _event_map_event_has_abstracts($node->nid) ? t('Abstract/Presentation available') : FALSE;
  if ($vars['view_mode'] == 'teaser') {
    $vars['types'] = drupal_render($vars['content']['field_event_type']);
  }
}

/**
 * Brief message to display when no results match the query.
 *
 * @see search_help()
 */

/**
 * Date override so that the title is set correctly.
 */
function rmets_date_part_label_date() {
  return '';
}

/**
 * Theme a feed link.
 *
 * This theme function uses the theme pattern system to allow it to be
 * overidden in a more specific manner. The options for overiding this include
 * providing per display id; per type; per display id and per type.
 *
 * e.g.
 * For the view "export_test" with the display "page_1" and the type "csv" you
 * would have the following options.
 *   views_data_export_feed_icon__export_test__page_1__csv
 *   views_data_export_feed_icon__export_test__page_1
 *   views_data_export_feed_icon__export_test__csv
 *   views_data_export_feed_icon__page_1__csv
 *   views_data_export_feed_icon__page_1
 *   views_data_export_feed_icon__csv
 *   views_data_export_feed_icon
 *
 * @ingroup themeable
 */
function rmets_views_data_export_feed_icon__cpd_records_embedded__csv($variables) {
  extract($variables, EXTR_SKIP);
  $url_options = array('html' => TRUE);
  $url_options['attributes']['class'][] = 'button-link';
  if ($query) {
    $url_options['query'] = $query;
  }
  return l($text, $url, $url_options);
}
