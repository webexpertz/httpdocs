<?php
/**
 * @file
 * rmets_committee_document.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function rmets_committee_document_taxonomy_default_vocabularies() {
  return array(
    'committees' => array(
      'name' => 'Committees',
      'machine_name' => 'committees',
      'description' => 'The different committee groups',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
