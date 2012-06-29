<?php
/**
 * @file
 * fff_content_type_facts.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function fff_content_type_facts_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'facts_importer';
  $feeds_importer->config = array(
    'name' => 'Facts',
    'description' => 'Import facts from XML file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'Facts',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'fact',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'body',
            'target' => 'field_fact_content',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'source',
            'target' => 'field_fact_source:title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'sourcelink',
            'target' => 'field_fact_source:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'inspirename',
            'target' => 'field_fact_inspiration:title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'author',
            'target' => 'field_fact_author',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'unixtime',
            'target' => 'created',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'tags',
            'target' => 'field_fact_tags',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'inspirelink',
            'target' => 'field_fact_inspiration:url',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'orgnization',
            'target' => 'field_fact_organization',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'editor_html',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['facts_importer'] = $feeds_importer;

  return $export;
}
