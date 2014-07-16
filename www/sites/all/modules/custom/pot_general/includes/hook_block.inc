<?php
/**
 * @file
 * Code for hook_block_*.
 */

/**
 * Implements hook_block_info.
 */

function pot_general_block_info() {
  $blocks = array();

  $blocks['inventory_count_block'] = array(
    'info' => t('Homepage content: inventory count'),
    'cache' => DRUPAL_NO_CACHE,
  );

  $blocks['user_name_block'] = array(
    'info' => t('User name and emoji'),
    'cache' => DRUPAL_NO_CACHE,
  );

  return $blocks;
}


/**
 * Implements hook_block_view.
 */
function pot_general_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'inventory_count_block':
      $inventory = pot_general_get_inventory_count();
      $result = theme('inventory_count', array('inventory' => $inventory));
      if (!empty($result)) {
        $block['content'] = $result;
      }
      break;

    case 'user_name_block':
      $result = theme('user_name', array());
      if (!empty($result)) {
        $block['content'] = $result;
      }
      break;
  }

  return $block;
}
