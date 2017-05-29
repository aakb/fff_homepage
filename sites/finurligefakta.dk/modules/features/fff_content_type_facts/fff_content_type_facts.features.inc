<?php
/**
 * @file
 * fff_content_type_facts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fff_content_type_facts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function fff_content_type_facts_node_info() {
  $items = array(
    'fact' => array(
      'name' => t('Fakta'),
      'base' => 'node_content',
      'description' => t('Add a fact to the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
