<?php

/**
 * @file
 * TaxonomyTermWrapper
 */

namespace Drupal\rmets_wrapper\EntityWrapper\TaxonomyTerm;

use Drupal\rmets_wrapper\EntityWrapper\EntityWrapper;

class TaxonomyTermWrapper extends EntityWrapper {

  /**
   * @param int|object $data
   *   A tid or taxonomy_term object.
   *
   * @return TaxonomyTermWrapper
   */
  public static function GetObject($data) {
    $term = $data;
    if (is_numeric($data)) {
      $term = taxonomy_term_load($data);
    }

    if (!is_object($term) || !isset($term->vocabulary_machine_name)) {
      return FALSE;
    }

    $objectMap = [
      'accreditation_type' => '\Drupal\rmets_wrapper\EntityWrapper\TaxonomyTerm\AccreditationTypeTermWrapper',
    ];

    $taxonomyTermWrapper = array_key_exists($term->vocabulary_machine_name, $objectMap) ? $objectMap[$term->vocabulary_machine_name]::GetObject($term) : new TaxonomyTermWrapper($term);
    return $taxonomyTermWrapper;
  }

  /**
   * Get a wrapped taxonomy term by its name.
   *
   * @param string $termName
   *   A taxonomy name
   *
   * @return TaxonomyTermWrapper
   */
  public static function GetObjectByName($termName) {
    $term = taxonomy_get_term_by_name($termName, static::getTaxonomyMachineName());
    if (!is_array($term) || count($term) < 1) {
      return NULL;
    }

    $term = reset($term);
    return static::GetObject($term);
  }

  /**
   * Get the machine name of this taxonomy.
   *
   * @return string|NULL
   */
  public static function getTaxonomyMachineName() {
    return NULL;
  }

  /**
   * Get a list of taxonomy terms by their names.
   *
   * @param string[] $termNames
   *   A list of term names.
   *
   * @return TaxonomyTermWrapper[]
   *   A list of TaxonomyTermWrapper objects.
   */
  public static function GetObjectsByNames(array $termNames) {
    $terms = array();
    foreach ($termNames as $termName) {
      $term = static::GetObjectByName($termName);
      if (!is_object($term)) {
        continue;
      }

      $terms[] = $term;
    }

    return $terms;
  }

  /**
   * Wrap a Taxonomy Term object.
   *
   * @param int|object $data
   *   A tid or taxonomy object.
   */
  public function __construct($data) {
    parent::__construct('taxonomy_term', $data);
  }

  /**
   * Get the name of this term.
   *
   * @return string
   *   The name of the term (its label).
   *
   * @throws \EntityMetadataWrapperException
   */
  public function getName() {
    return $this->label();
  }

  /**
   * Get the canonical url for this term.
   *
   * @return string
   */
  public function getCanonicalUrl() {
    return url('taxonomy/term/' . $this->getIdentifier(), ['absolute' => TRUE]);
  }

}
