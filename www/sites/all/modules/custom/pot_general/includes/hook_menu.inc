<?php
/**
 * @file
 * Code for menu hooks.
 */

/**
 * Implements hook_menu().
 */

function pot_general_menu() {
  $items = array();

  $items['home'] = array(
    'title' => 'Homepage',
    'page callback' => 'pot_general_home',
    'description' => t('Pottery homepage'),
    'access callback' => TRUE,
    'type' => MENU_CALLBACK,
  );

  return $items;
}

/**
 * Custom menu callback for /home.
 */
function pot_general_home() {
  return '';
}
