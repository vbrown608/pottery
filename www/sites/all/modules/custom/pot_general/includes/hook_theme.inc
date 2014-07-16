<?php
/**
 * @file
 * Code for hook_theme and custom theme functions.
 */

/**
 * Implements hook_theme().
 *
 */
function pot_general_theme() {
  $theme_functions = array(
    'inventory_count' => array(
      'variables' => array(
        'inventory' => NULL,
      ),
    ),
    'user_name' => array(
      'variables' => array(),
    ),
  );

  // Hmm...
  // $field_options = field_info_field('field_activity_type');
  // foreach ($field_options['settings']['allowed_values'] as $value) {
  //   $theme_function = 'theme_activity_type_' . str_replace(' ', '_', $value);
  //   if (function_exists($theme_function)) {
  //     $theme_functions['activity_type_' . str_replace(' ', '_', $value)] = array(
  //       'variables' => array(
  //         'node' => NULL,
  //       ),
  //     );
  //   }
  // }

  return $theme_functions;
}

function theme_inventory_count($variables) {
  $result = '';
  if (isset($variables['inventory']) && !empty($variables['inventory'])) {
    $result = t('Total inventory: @inventory', array('@inventory' => $variables['inventory']));
  }
  return $result;
}

/*
 * Renders the logged in user's name or anonymous and one of six randomized emojis.
 *
 */
function theme_user_name($variables) {
  global $user;
  $name = pot_general_get_user_name($user->uid);
  $emoji_id = rand(1, 6);
  return t('@name<div class = "emoji emoji-@emoji_id"></div>',
    array('@name' => $name, '@emoji_id' => $emoji_id));
}

