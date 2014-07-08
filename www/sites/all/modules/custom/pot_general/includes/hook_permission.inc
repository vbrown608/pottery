<?php
/**
 * @file
 * Code for hook_permission()
 */

/**
 * Implements hook_permission().
 */
function npe_general_permission() {
  $permissions = array(
    'administer prices' => array(
      'title' => t('Administer pottery item prices'),
      'description' => t('Allow managers to set prices of pottery items'),
    ),
  );

  return $permissions;
}
