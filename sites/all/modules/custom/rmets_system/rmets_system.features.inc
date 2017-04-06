<?php
/**
 * @file
 * rmets_system.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function rmets_system_commerce_product_default_types() {
  $items = array(
    'rmets_events_smartimpact' => array(
      'type' => 'rmets_events_smartimpact',
      'name' => 'RMetS Events SmartImpact',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function rmets_system_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rmets_system_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function rmets_system_image_default_styles() {
  $styles = array();

  // Exported image style: 1024-wide.
  $styles['1024-wide'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1024,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => 0,
          'alpha' => 100,
          'path' => 'public://default_images/watermark.png',
        ),
        'weight' => 2,
      ),
    ),
    'label' => '1024-wide',
  );

  // Exported image style: 118-188.
  $styles['118-188'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 118,
          'height' => 118,
        ),
        'weight' => 1,
      ),
    ),
    'label' => '118-188',
  );

  // Exported image style: 210-137.
  $styles['210-137'] = array(
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 210,
          'height' => 137,
        ),
        'weight' => 1,
      ),
    ),
    'label' => '210-137',
  );

  // Exported image style: 284-wide.
  $styles['284-wide'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 284,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => '284-wide',
  );

  // Exported image style: 525-267.
  $styles['525-267'] = array(
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 525,
          'height' => 267,
        ),
        'weight' => 1,
      ),
    ),
    'label' => '525-267',
  );

  // Exported image style: 90-90.
  $styles['90-90'] = array(
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
    'label' => '90-90',
  );

  // Exported image style: colorbox.
  $styles['colorbox'] = array(
    'effects' => array(),
    'label' => 'colorbox',
  );

  // Exported image style: image_gallery_720.
  $styles['image_gallery_720'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 720,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => 0,
          'alpha' => 100,
          'path' => 'public://default_images/watermark.png',
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'image_gallery_720',
  );

  // Exported image style: large-product-720-250.
  $styles['large-product-720-250'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'large-product-720-250',
  );

  // Exported image style: news-450-width.
  $styles['news-450-width'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 450,
          'height' => 450,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'news-450-width',
  );

  // Exported image style: profile_picture.
  $styles['profile_picture'] = array(
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 102,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'profile_picture',
  );

  // Exported image style: section-landing-thumbnails-210-137.
  $styles['section-landing-thumbnails-210-137'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 210,
          'height' => 137,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'section-landing-thumbnails-210-137',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function rmets_system_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'carousel_item' => array(
      'name' => t('Carousel item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'corporate_member' => array(
      'name' => t('Corporate member'),
      'base' => 'node_content',
      'description' => t('The details of a corporate member to appear on the list of corporate members page.'),
      'has_title' => '1',
      'title_label' => t('Company name'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event_abstract' => array(
      'name' => t('Event abstract'),
      'base' => 'node_content',
      'description' => t('A abstract submission for an event'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event_session' => array(
      'name' => t('Event session'),
      'base' => 'node_content',
      'description' => t('A session is a part of an event'),
      'has_title' => '1',
      'title_label' => t('Session name'),
      'help' => '',
    ),
    'event_subsession' => array(
      'name' => t('Event subsession'),
      'base' => 'node_content',
      'description' => t('A sub session should normally be created via the event management block from within an event on the site.'),
      'has_title' => '1',
      'title_label' => t('Sub Session name'),
      'help' => '',
    ),
    'image_gallery' => array(
      'name' => t('Image gallery'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'landing_page' => array(
      'name' => t('Landing page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'local_area_groups' => array(
      'name' => t('Local area groups'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_display' => array(
      'name' => t('Product display'),
      'base' => 'node_content',
      'description' => t('This is a product display'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'special_interest_groups' => array(
      'name' => t('Special Interest Groups'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform_product' => array(
      'name' => t('Webform product'),
      'base' => 'node_content',
      'description' => t('Create a product for sale in the shop with an attached webform for selecting the product and specifying additional details.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
