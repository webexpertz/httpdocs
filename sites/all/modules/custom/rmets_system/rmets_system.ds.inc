<?php
/**
 * @file
 * rmets_system.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function rmets_system_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'commerce_product|product|node_teaser';
  $ds_fieldsetting->entity_type = 'commerce_product';
  $ds_fieldsetting->bundle = 'product';
  $ds_fieldsetting->view_mode = 'node_teaser';
  $ds_fieldsetting->settings = array(
    'commerce_price' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'price',
      ),
    ),
    'commerce_stock' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'price',
      ),
    ),
  );
  $export['commerce_product|product|node_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|corporate_member|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'corporate_member';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_company_contact_name' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Contact',
      ),
    ),
    'field_company_contact_email' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'span',
        'ow-cl' => 'padded-left',
      ),
    ),
  );
  $export['node|corporate_member|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event_abstract|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event_abstract';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
    'event_map_abstract_session_title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'h2',
        'ow-cl' => '',
      ),
    ),
    'event_map_nid' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'default',
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Abstract ID',
        'lb-el' => 'strong',
        'ow' => TRUE,
        'ow-el' => 'p',
        'ow-cl' => '',
      ),
    ),
    'field_abstract_time_and_date' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'strong',
        'ow' => TRUE,
        'ow-el' => 'p',
        'ow-cl' => '',
      ),
    ),
    'field_abstract_type' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Type',
        'lb-el' => 'strong',
        'ow' => TRUE,
        'ow-el' => 'p',
        'ow-cl' => '',
      ),
    ),
  );
  $export['node|event_abstract|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event_session|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event_session';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'event_map_session_subsessions' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event_session|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'event_add_cpd_record_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'event_registration' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'event_map_programme' => array(
      'weight' => '9',
      'label' => 'above',
      'format' => 'default',
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Programme',
        'lb-el' => 'h2',
      ),
    ),
    'event_map_map' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_event_date' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'strong',
        'ow' => TRUE,
        'ow-el' => 'p',
        'ow-cl' => '',
      ),
    ),
    'field_summary_location' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Location',
        'lb-el' => 'strong',
      ),
    ),
    'field_event_email' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Email',
        'lb-el' => 'strong',
        'ow' => TRUE,
        'ow-el' => 'p',
        'ow-cl' => '',
      ),
    ),
  );
  $export['node|event|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|image_gallery|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'image_gallery';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'body' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-type-text-with-summary',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => '',
      ),
    ),
    'field_gallery_image' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-name-field-gallery-image',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'image-wrapper rounded',
      ),
    ),
  );
  $export['node|image_gallery|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|product_display|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'product_display';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'body' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
    'field_product_references' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
    'field_product_image' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'image-wrapper rounded right',
      ),
    ),
    'product:commerce_stock' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
  );
  $export['node|product_display|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|product_display|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'product_display';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
    'field_product_image' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'image-wrapper rounded',
      ),
    ),
  );
  $export['node|product_display|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|webform_product|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'webform_product';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'body' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
    'field_product_image' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'image-wrapper rounded right',
      ),
    ),
  );
  $export['node|webform_product|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|webform_product|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'webform_product';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
    'field_product_image' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'image-wrapper rounded',
      ),
    ),
    'rmets_system_webform_default_price' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'price',
      ),
    ),
  );
  $export['node|webform_product|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function rmets_system_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_registration';
  $ds_field->label = 'Event Registration';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php if (isset($entity->field_allow_registration[\'und\'][0][\'value\']) && $entity->field_allow_registration[\'und\'][0][\'value\'] == 1): ?>
<a class="button-link" href="/event/register/<?php print $entity->nid; ?>">Register for this event</a>
<?php endif; ?>
',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['event_registration'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function rmets_system_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'commerce_product|product|default';
  $ds_layout->entity_type = 'commerce_product';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'commerce_stock',
        1 => 'commerce_price',
      ),
    ),
    'fields' => array(
      'commerce_stock' => 'ds_content',
      'commerce_price' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['commerce_product|product|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'commerce_product|product|node_teaser';
  $ds_layout->entity_type = 'commerce_product';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'node_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'commerce_stock',
        1 => 'commerce_price',
      ),
    ),
    'fields' => array(
      'commerce_stock' => 'ds_content',
      'commerce_price' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['commerce_product|product|node_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|corporate_member|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'corporate_member';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_company_logo',
        1 => 'body',
        2 => 'field_website',
      ),
    ),
    'fields' => array(
      'field_company_logo' => 'ds_content',
      'body' => 'ds_content',
      'field_website' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|corporate_member|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|corporate_member|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'corporate_member';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_company_logo',
        2 => 'body',
        3 => 'field_website',
        4 => 'field_company_contact_name',
        5 => 'field_company_contact_email',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_company_logo' => 'ds_content',
      'body' => 'ds_content',
      'field_website' => 'ds_content',
      'field_company_contact_name' => 'ds_content',
      'field_company_contact_email' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|corporate_member|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event_abstract|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event_abstract';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'event_map_abstract_session_title',
        1 => 'title',
        2 => 'field_abstract_time_and_date',
        3 => 'event_map_nid',
        4 => 'field_abstract_type',
        5 => 'field_presenting_author',
        6 => 'field_event_abstract_theme',
        7 => 'field_abstract_authors',
        8 => 'body',
        9 => 'field_grouped_files',
        10 => 'field_resources_link',
      ),
    ),
    'fields' => array(
      'event_map_abstract_session_title' => 'ds_content',
      'title' => 'ds_content',
      'field_abstract_time_and_date' => 'ds_content',
      'event_map_nid' => 'ds_content',
      'field_abstract_type' => 'ds_content',
      'field_presenting_author' => 'ds_content',
      'field_event_abstract_theme' => 'ds_content',
      'field_abstract_authors' => 'ds_content',
      'body' => 'ds_content',
      'field_grouped_files' => 'ds_content',
      'field_resources_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|event_abstract|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event_session|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event_session';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_event_session_start_time',
        2 => 'event_map_session_subsessions',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_event_session_start_time' => 'ds_content',
      'event_map_session_subsessions' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|event_session|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_3col_equal_width';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_event_type',
      ),
      'middle' => array(
        0 => 'field_event_date',
        1 => 'field_summary_location',
        2 => 'field_event_email',
        3 => 'event_add_cpd_record_link',
      ),
      'right' => array(
        0 => 'body',
        1 => 'field_further_information',
        2 => 'field_allow_abstract_submissions',
        3 => 'group_buttons',
        4 => 'field_grouped_files',
        5 => 'event_registration',
        6 => 'event_map_programme',
        7 => 'event_schedule',
        8 => 'event_map_map',
        9 => 'links',
      ),
    ),
    'fields' => array(
      'field_event_type' => 'left',
      'field_event_date' => 'middle',
      'field_summary_location' => 'middle',
      'field_event_email' => 'middle',
      'event_add_cpd_record_link' => 'middle',
      'body' => 'right',
      'field_further_information' => 'right',
      'field_allow_abstract_submissions' => 'right',
      'group_buttons' => 'right',
      'field_grouped_files' => 'right',
      'event_registration' => 'right',
      'event_map_programme' => 'right',
      'event_schedule' => 'right',
      'event_map_map' => 'right',
      'links' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|event|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|image_gallery|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'image_gallery';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_gallery_image',
        2 => 'field_copyright',
        3 => 'field_photographer',
        4 => 'field_location',
        5 => 'field_image_date',
        6 => 'field_weather_type',
        7 => 'field_id',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_gallery_image' => 'ds_content',
      'field_copyright' => 'ds_content',
      'field_photographer' => 'ds_content',
      'field_location' => 'ds_content',
      'field_image_date' => 'ds_content',
      'field_weather_type' => 'ds_content',
      'field_id' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|image_gallery|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product_display|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product_display';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_product_image',
        1 => 'body',
        2 => 'product:commerce_stock',
        3 => 'product:commerce_price',
        4 => 'field_product_references',
      ),
    ),
    'fields' => array(
      'field_product_image' => 'ds_content',
      'body' => 'ds_content',
      'product:commerce_stock' => 'ds_content',
      'product:commerce_price' => 'ds_content',
      'field_product_references' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|product_display|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product_display|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product_display';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_product_image',
        2 => 'product:commerce_price',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_product_image' => 'ds_content',
      'product:commerce_price' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|product_display|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform_product|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform_product';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_product_image',
        1 => 'body',
        2 => 'webform',
      ),
    ),
    'fields' => array(
      'field_product_image' => 'ds_content',
      'body' => 'ds_content',
      'webform' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|webform_product|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform_product|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform_product';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_product_image',
        2 => 'rmets_system_webform_default_price',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_product_image' => 'ds_content',
      'rmets_system_webform_default_price' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|webform_product|teaser'] = $ds_layout;

  return $export;
}
