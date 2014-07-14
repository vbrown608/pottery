<?php
/**
 * @file
 * pot_general.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pot_general_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
  );

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => 3,
  );

  // Exported role: potter.
  $roles['potter'] = array(
    'name' => 'potter',
    'weight' => 2,
  );

  return $roles;
}
