<?php
/**
 * @file
 * Generic entity base wrapper class.
 */

namespace Drupal\rmets_wrapper\EntityWrapper;

use \EntityDrupalWrapper;
use \EntityMetadataWrapperException;

/**
 * Generically wraps entities.
 */
class EntityWrapper extends EntityDrupalWrapper {

  /**
   * Converts a Drupal machine name to a entity wrapper class name.
   *
   * @param $machineName
   * @return mixed
   */
  public static function machineNameToClassName($machineName) {
    return str_replace(' ', '', ucwords(str_replace('_', ' ', $machineName)));
  }

  /**
   * @param int|object $data
   *   An entity id or loaded entity object.
   * @param string $entityType
   *   Entity type, 'node' or 'group'
   *
   * @return EntityWrapper|NULL
   */
  public static function GetEntity($data, $entityType = 'node') {
    $entity = $data;
    if (is_numeric($entity)) {
      $entity = entity_load_single($entityType, $entity);
    }

    if (!is_object($entity)) {
      return FALSE;
    }

    $objectMap = [
      'bean' => '\Drupal\rct_wrapper\EntityWrapper\Bean\BeanWrapper',
      'node' => '\Drupal\rct_wrapper\EntityWrapper\Node\NodeWrapper',
      'group' => '\Drupal\rct_wrapper\EntityWrapper\Group\GroupWrapper',
      'taxonomy_term' => '\Drupal\rct_wrapper\EntityWrapper\TaxonomyTerm\TaxonomyTermWrapper',
    ];

    if (array_key_exists($entityType, $objectMap)) {
      return $objectMap[$entityType]::GetObject($entity);
    }

    return NULL;
  }

  /**
   * Wrap an entity object.
   *
   * @param $entityType
   * @param int|object $data A entity id or entity object.
   */
  public function __construct($entityType, $data) {
    parent::__construct($entityType, $data);
  }

  /**
   * Gets the info about the given property.
   *
   * @param $name
   *   The name of the property. If not given, info about all properties will
   *   be returned.
   * @throws EntityMetadataWrapperException
   *   If there is no such property.
   * @return
   *   An array of info about the property.
   */
  public function getPropertyInfo($name = NULL) {
    try {
      return parent::getPropertyInfo($name);
    } catch (EntityMetadataWrapperException $e) {
      $this->raiseWatchdogException($e);
      $this->raiseKrumoException($e);
      throw $e;
    }
  }

  /**
   * Get the wrapper for a property.
   *
   * @return
   *   An instance of EntityMetadataWrapper.
   *
   * @throws \Exception
   */
  public function get($name) {
    try {
      return parent::get($name);
    } catch (EntityMetadataWrapperException $e) {
      $this->raiseWatchdogException($e);
      $this->raiseKrumoException($e);
      throw $e;
    }
  }

  /**
   * Raise an exception for logging.
   *
   * @param \Exception $exception
   */
  public function raiseException(\Exception $exception) {
    $this->raiseWatchdogException($exception);
    $this->raiseKrumoException($exception);
  }

  /**
   * Raise a Watchdog log entry for an exception.
   *
   * @param \Exception $exception
   */
  public function raiseWatchdogException(\Exception $exception) {
    if ($this->exceptionLoggingEnabled()) {
      $str = $this->exceptionToLogMessage($exception);
      watchdog_exception(get_class($this), $exception, nl2br($str));
    }
  }

  /**
   * Raise a Krumo for an exception.
   *
   * @param \Exception $exception
   */
  public function raiseKrumoException(\Exception $exception) {
    if ($this->exceptionDisplayEnabled()) {
      $str = $this->exceptionToLogMessage($exception);
      has_krumo();
      krumo($str);
    }
  }

  public function exceptionToLogMessage(\Exception $exception) {
    return "Entity Meta\n\n"
    . "Type: " . $this->getBundle() . "\n"
    . "Id: " . $this->getIdentifier() . "\n\n"
    . "Exception\n\n" .$exception->getMessage()
    . "\n\nTrace\n\n" . $exception->getTraceAsString();
  }

  /**
   * Returns a boolean indicating whether we are logging to Watchdog.
   *
   * @return bool
   */
  public function exceptionLoggingEnabled() {
    return variable_get('custom_entity_wrapper_exception_logging_enabled', FALSE);
  }

  /**
   * Returns a boolean indicating whether we are logging to Watchdog.
   *
   * @return bool
   */
  public function exceptionDisplayEnabled() {
    return variable_get('custom_entity_wrapper_exception_display_enabled', FALSE);
  }

  /**
   * Refreshes a wrapped entities data. Useful when you know the entity may have been modified in the database and you
   * want to load the up-to-date data values.
   *
   * @throws \EntityMetadataWrapperException
   */
  public function refresh() {
    if (NULL !== $this->getIdentifier()) {
      $this->set($this->getIdentifier());
    }
  }

  /**
   * Determine if the entity has the requested field.
   *
   * @param string $fieldName
   *   The name of the field (e.g. body)
   * @param bool $throwException
   *   Throw an exception if the field is missing rather than return FALSE.
   *
   * @return bool
   *   FALSE if missing
   *
   * @throws \EntityMetadataWrapperException
   *   Thrown if field is missing and you set throwException to TRUE
   */
  protected function fieldExists($fieldName, $throwException = FALSE) {
    if (isset($this->$fieldName)) {
      return TRUE;
    }

    if ($throwException) {
      throw new \EntityMetadataWrapperException('"' . $fieldName . '" field is missing');
    }

    return FALSE;
  }

  /**
   * Determine if the entity has the requested field and that field has a value.
   *
   * @param string $fieldName
   *   The name of the field (e.g. body)
   * @param bool $throwException
   *   Throw an exception if the field is missing rather than return FALSE.
   *
   * @return bool
   *   FALSE if missing
   *
   * @throws \EntityMetadataWrapperException
   *   Thrown if field is missing and you set throwException to TRUE
   */
  protected function hasField($fieldName, $throwException = FALSE) {
    if (!$this->fieldExists($fieldName, $throwException)) {
      return FALSE;
    }

    $val = $this->$fieldName->value();
    if (isset($val) && !empty($val)) {
      return TRUE;
    }

    if ($throwException) {
      throw new \EntityMetadataWrapperException('"' . $fieldName . '” value is not set');
    }

    return FALSE;
  }

  protected function getField($fieldName) {
    try {
      return $this->{$fieldName}->value();
    }
    catch (\EntityMetadataWrapperException $e) {
      $this->raiseWatchdogException($e);
      $this->raiseKrumoException($e);
      throw $e;
    }
  }

  /**
   * Get the image URLs based on the configured image styles.
   *
   * @param array $file_array
   *   The file array.
   * @param array $image_styles
   *   The list of image styles to use.
   *
   * @return array
   *   The input file array with an extra key for the image styles.
   */
  protected function getImageUris(array $file_array, $image_styles) {
    // Return early if there are no image styles.
    if (empty($image_styles)) {
      return $file_array;
    }
    // If $file_array is an array of file arrays. Then call recursively for each
    // item and return the result.
    if (static::isArrayNumeric($file_array)) {
      $output = array();
      foreach ($file_array as $item) {
        $output[] = $this->getImageUris($item, $image_styles);
      }
      return $output;
    }
    $file_array['image_styles'] = array();
    foreach ($image_styles as $style) {
      $file_array['image_styles'][$style] = image_style_url($style, $file_array['uri']);
    }
    return $file_array;
  }

  /**
   * Get the meta title for this entity.
   *
   * @param int $length
   *   The length of the title to return, default 65
   *
   * @return string
   *
   * @see rc_main_node_view().
   */
  public function getMetaTitle($length = 65) {
    $title = $this->label();
    if ($this->hasField('meta_meta_title')) {
      // Meta tags title is on this entity.
      $title = $this->meta_meta_title->value();
    }

    return $this->metaStringClean($title, $length);
  }

  /**
   * Get the meta description for this node.
   *
   * @param int $length
   *   The maximum length of the description.
   *
   * @return string
   */
  public function getMetaDescription($length = 160) {
    $raw_text = '';

    if ($this->hasField('field_description')) {
      // Meta tags description is on this entity.
      $raw_text = $this->field_description->value();
    }
    elseif ($this->hasField('description')) {
      // Meta tags description is on this entity.
      $raw_text = $this->description->value();
    }
    elseif ($this->hasField('body')) {
      $body_text = $this->body->value();
      $raw_text = $body_text['safe_value'];
    }

    return $this->metaStringClean($raw_text, $length);
  }

  /**
   * Get a list of image urls which should be included in the head of a page.
   *
   * @return string[]
   *   A list of image urls.
   *
   * @see rc_main_node_view().
   */
  public function getMetaImageUrls() {
    try {
      $lead_image = field_view_field($this->type, $this->value(), $this->getMainImageFieldName() , 'teaser');
      if (isset($lead_image[0])) {
        $lead_image[0]['#theme'] = 'image_url_formatter';
        return [trim(strip_tags(render($lead_image)))];
      }
    }
    catch (\Exception $e) {}

    return [];
  }

  /**
   * Get the main image field name on this entity.
   *
   * @return string
   *   The name of the lead image field.
   *
   * @throws \Exception
   *   If there is no lead image field that is known.
   */
  protected function getMainImageFieldName() {
    if ($this->hasField('field_lead_image')) {
      return 'field_lead_image';
    }

    if ($this->hasField('field_image')) {
      return 'field_image';
    }

    throw new \Exception('Cannot determine the lead image field on this node.');
  }


  /**
   * Clean a string which is going to go into the meta data.
   *
   * @param $string
   * @param $length
   * @return mixed|string
   */
  protected function metaStringClean($string, $length) {
    $string = html_entity_decode($string, ENT_QUOTES);
    $string = strip_tags($string);
    $string = str_replace(["'", '"', "\n"], '', $string);

    return views_trim_text([
      'max_length' => $length,
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'html' => TRUE,
    ], $string);
  }

  /**
   * Get the canonical url for this entity.
   *
   * @return string
   */
  public function getCanonicalUrl() {
    return '/';
  }

  /**
   * If the entity type uses MetaTags module this should return FALSE.
   *
   * @return bool
   */
  public function hasAutomaticMetaTags() {
    return !$this->hasField('meta_meta_title');
  }

  /**
   * Return the label for this content type.
   *
   * @return string
   */
  public function getContentTypeLabel() {
    $bundleMachinename = $this->getBundle();
    $entityInfo = $this->entityInfo();
    if (isset($entityInfo['bundles'][$bundleMachinename]['label'])) {
      return $entityInfo['bundles'][$bundleMachinename]['label'];
    }

    return ucfirst(str_replace('_', ' ', $bundleMachinename));
  }

  /**
   * Set the pathauto automatic url alias flag on the entity.
   *
   * On the next save the URL will be reset to the pathauto default.
   *
   * @return $this
   */
  public function setAutomaticUrlAlias() {
    $this->data->path = ['pathauto' => '1'];
    return $this;
  }

}