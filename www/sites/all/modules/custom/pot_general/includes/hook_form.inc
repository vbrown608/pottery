<?php

/**
 * Implements hook_form_alter().
 */
function npe_general_form_alter(&$form, &$form_state, $form_id) {
  // Disable revision fieldsets on all content types.
  foreach (node_type_get_types() as $key => $value) {
    if ($form_id == $key . '_node_form') {
      unset($form['revision_information']);
    }
  }
}
