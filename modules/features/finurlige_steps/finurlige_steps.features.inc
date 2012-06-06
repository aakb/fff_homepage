<?php
/**
 * @file
 * finurlige_steps.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function finurlige_steps_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function finurlige_steps_node_info() {
  $items = array(
    'step' => array(
      'name' => t('Step'),
      'base' => 'node_content',
      'description' => t('A frontpage step, which will be added to sites frontpage'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
