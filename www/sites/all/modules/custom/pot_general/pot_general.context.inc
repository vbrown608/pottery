<?php
/**
 * @file
 * pot_general.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pot_general_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'The landing page for the pottery site.';
  $context->tag = '';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The landing page for the pottery site.');
  $export['home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'internal';
  $context->description = 'Internal pages (excludes admin pages and homepage)';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
        '~<front>' => '~<front>',
        '~batch' => '~batch',
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
        '~node/*/devel' => '~node/*/devel',
        '~media/browser' => '~media/browser',
        '~media/*/format-form' => '~media/*/format-form',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Internal pages (excludes admin pages and homepage)');
  $export['internal'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'Sitewide (excludes admin pages)';
  $context->tag = '';
  $context->conditions = array(
    'error' => array(
      'values' => array(
        403 => 403,
        404 => 404,
      ),
    ),
    'path' => array(
      'values' => array(
        '*' => '*',
        '~batch' => '~batch',
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
        '~node/*/devel' => '~node/*/devel',
        '~media/browser' => '~media/browser',
        '~media/*/format-form' => '~media/*/format-form',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-site-name' => array(
          'module' => 'delta_blocks',
          'delta' => 'site-name',
          'region' => 'header',
          'weight' => '-10',
        ),
        'delta_blocks-site-slogan' => array(
          'module' => 'delta_blocks',
          'delta' => 'site-slogan',
          'region' => 'header',
          'weight' => '-9',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-9',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide (excludes admin pages)');
  $export['sitewide'] = $context;

  return $export;
}
