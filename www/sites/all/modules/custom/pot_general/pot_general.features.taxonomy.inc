<?php
/**
 * @file
 * pot_general.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pot_general_taxonomy_default_vocabularies() {
  return array(
    'pottery_type' => array(
      'name' => 'Pottery type',
      'machine_name' => 'pottery_type',
      'description' => 'Type of pottery being sold, ex. "plate"',
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
