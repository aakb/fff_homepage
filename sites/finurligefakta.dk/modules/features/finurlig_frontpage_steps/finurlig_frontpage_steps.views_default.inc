<?php
/**
 * @file
 * finurlig_frontpage_steps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function finurlig_frontpage_steps_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'frontpage_steps';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Frontpage steps';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'step';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'frontpage_steps' => 'frontpage_steps',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Custom: Step text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Custom: Step text';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Step';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'span';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'step-text';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Global: counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['ui_name'] = 'Global: counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_type'] = 'span';
  $handler->display->display_options['fields']['counter']['element_class'] = 'counter';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Custom: Step + Counter */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Custom: Step + Counter';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<span class="step-text">[nothing]</span><span class="counter">[counter]</span>';
  $handler->display->display_options['fields']['nothing_2']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_2']['element_class'] = 'step';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'headline';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['field_step_content']['id'] = 'field_step_content';
  $handler->display->display_options['fields']['field_step_content']['table'] = 'field_data_field_step_content';
  $handler->display->display_options['fields']['field_step_content']['field'] = 'field_step_content';
  $handler->display->display_options['fields']['field_step_content']['label'] = '';
  $handler->display->display_options['fields']['field_step_content']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_step_content']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_step_content']['element_class'] = 'description';
  $handler->display->display_options['fields']['field_step_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_step_content']['element_default_classes'] = FALSE;
  /* Field: Content: Screenshots */
  $handler->display->display_options['fields']['field_step_images']['id'] = 'field_step_images';
  $handler->display->display_options['fields']['field_step_images']['table'] = 'field_data_field_step_images';
  $handler->display->display_options['fields']['field_step_images']['field'] = 'field_step_images';
  $handler->display->display_options['fields']['field_step_images']['label'] = '';
  $handler->display->display_options['fields']['field_step_images']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_step_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_step_images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_step_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_step_images']['settings'] = array(
    'image_style' => 'screenshot',
    'image_link' => 'file',
  );
  $handler->display->display_options['fields']['field_step_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_step_images']['separator'] = '';
  /* Field: Content: Ikon */
  $handler->display->display_options['fields']['field_step_ikon']['id'] = 'field_step_ikon';
  $handler->display->display_options['fields']['field_step_ikon']['table'] = 'field_data_field_step_ikon';
  $handler->display->display_options['fields']['field_step_ikon']['field'] = 'field_step_ikon';
  $handler->display->display_options['fields']['field_step_ikon']['label'] = '';
  $handler->display->display_options['fields']['field_step_ikon']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_step_ikon']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_step_ikon']['element_class'] = 'icon';
  $handler->display->display_options['fields']['field_step_ikon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_step_ikon']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_step_ikon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_step_ikon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Custom: content */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Custom: content';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<span class="text"><a name="node-[nid]"><h2>[title]</h2></a>[field_step_content]</span>
<span class="icon">[field_step_ikon]</span>
<span class="screenshots">[field_step_images]</span>';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'step-content-wrapper';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'step' => 'step',
  );

  /* Display: Front page */
  $handler = $view->new_display('page', 'Front page', 'page_1');
  $handler->display->display_options['display_description'] = 'The sites frontpage steps';
  $handler->display->display_options['path'] = 'frontpage';
  $translatables['frontpage_steps'] = array(
    t('Master'),
    t('mere'),
    t('Apply'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('queue'),
    t('Step'),
    t('<span class="step-text">[nothing]</span><span class="counter">[counter]</span>'),
    t('<span class="text"><a name="node-[nid]"><h2>[title]</h2></a>[field_step_content]</span>
<span class="icon">[field_step_ikon]</span>
<span class="screenshots">[field_step_images]</span>'),
    t('Front page'),
    t('The sites frontpage steps'),
    t('more'),
  );
  $export['frontpage_steps'] = $view;

  return $export;
}
