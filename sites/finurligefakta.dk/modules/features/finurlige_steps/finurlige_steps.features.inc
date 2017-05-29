<?php
/**
 * @file
 * finurlige_steps.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function finurlige_steps_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function finurlige_steps_image_default_styles() {
  $styles = array();

  // Exported image style: screenshot.
  $styles['screenshot'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'screenshot',
  );

  return $styles;
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
  drupal_alter('node_info', $items);
  return $items;
}
