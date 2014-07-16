<?php
/**
 * @file
 * Helper functions for included files
 */

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

/**
 * Returns user name.
 *
 * @param $uid
 */
function pot_general_get_user_name($uid) {
  $user = user_load($uid);
  if (!empty($user) && $user->uid != 0) {
    return $user->name;
  }
  else {
    return 'anonymous';
  }
}
