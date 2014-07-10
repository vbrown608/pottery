<?php
/**
 * Implements hook_form_POTTERY_ITEM_NODE_FORM_alter().
 */
function pot_general_form_pottery_item_node_form_alter(&$form, &$form_state, $form_id) {
  global $user;
  $bypass_access = user_access('bypass node access', $user);

  // Only users with permission to administer prices can access the price field
  $admin_prices_access = user_access('administer prices', $user);
  if ($admin_prices_access || $bypass_access) {
    $form['field_pottery_price']['#access'] = TRUE;
  } else {
    $form['field_pottery_price']['#access'] = FALSE;
  }

}
