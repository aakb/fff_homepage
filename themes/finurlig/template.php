<?php

function finurlig_menu_link_alter(&$item) {
  if ($item['menu_name'] == 'main-menu') {
    $item['link_title'] = 'gd';
  }
}