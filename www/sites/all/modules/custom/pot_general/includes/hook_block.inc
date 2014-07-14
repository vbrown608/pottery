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
      $block['subject'] = t('Inventory');
      $block['content'] = t('Total inventory: @inventory', array('@inventory' => $inventory));//$inventory;
      break;
  }
  return $block;
}

/**
 * Get the total pottery inventory.
 *
 * @return The sum of inventory counts of published pottery items
 */
function pot_general_get_inventory_count() {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_inventory_count', 'inventory', 'inventory.entity_id = n.nid');
  $query->condition('n.type', 'pottery_item');
  $query->condition('n.status', 1);
  $query->fields('inventory', array('field_inventory_count_value'));
  $query_result = $query->execute();

  $sum = 0;
  foreach ($query_result as $record) {
    $sum = $sum + $record->field_inventory_count_value;
  }

  return $sum;
}
