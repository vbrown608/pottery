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
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-intro_text' => array(
          'module' => 'boxes',
          'delta' => 'intro_text',
          'region' => 'content',
          'weight' => '-19',
        ),
        'pot_general-inventory_count_block' => array(
          'module' => 'pot_general',
          'delta' => 'inventory_count_block',
          'region' => 'content',
          'weight' => '-18',
        ),
        'views-pottery_items-most_recent_block' => array(
          'module' => 'views',
          'delta' => 'pottery_items-most_recent_block',
          'region' => 'content',
          'weight' => '-17',
        ),
        'pot_general-user_name_block' => array(
          'module' => 'pot_general',
          'delta' => 'user_name_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
    'menu' => '0',
    'region' => array(
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
        ),
      ),
      'omega' => array(
        'disable' => array(
          'branding' => 0,
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
        ),
      ),
      'pot_theme' => array(
        'disable' => array(
          'branding' => 0,
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
        ),
      ),
    ),
  );
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
