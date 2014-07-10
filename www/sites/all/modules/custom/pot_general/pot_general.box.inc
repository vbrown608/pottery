<?php
/**
 * @file
 * pot_general.box.inc
 */

/**
 * Implements hook_default_box().
 */
function pot_general_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'intro_text';
  $box->plugin_key = 'simple';
  $box->title = 'Welcome';
  $box->description = 'Intro text';
  $box->options = array(
    'body' => array(
      'value' => '<p>Welcome to the pottery site. Below is a selection of our latest items.</p>',
      'format' => 'filtered_html',
    ),
  );
  $export['intro_text'] = $box;

  return $export;
}
