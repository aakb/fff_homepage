<?php
/**
 * @file
 * fff_content_type_facts.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function fff_content_type_facts_taxonomy_default_vocabularies() {
  return array(
    'workflow' => array(
      'name' => 'workflow',
      'machine_name' => 'workflow',
      'description' => 'The current workflow state of a Fact',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
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
