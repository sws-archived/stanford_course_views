<?php
/**
 * @file
 * stanford_course_views.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_course_views_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'courses';
  $context->description = 'Courses page';
  $context->tag = 'Courses';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses' => 'courses',
        'courses/search' => 'courses/search',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-courses-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-courses-search_page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-courses-block' => array(
          'module' => 'views',
          'delta' => 'courses-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Courses');
  t('Courses page');
  $export['courses'] = $context;

  return $export;
}
