<?php

/**
 * @file
 * Remove text or whitespace from the beginning, middle, or both sides of array elements.
 */

$plugin = array(
  'form' => 'feeds_tamper_trim_array_form',
  'callback' => 'feeds_tamper_trim_array_callback',
  'name' => 'Trim Array',
  'multi' => 'loop',
  'category' => 'Text',
);

function feeds_tamper_trim_array_form($importer, $element_key, $settings) {
  $form = array();
  $form['mask'] = array(
    '#type' => 'textfield',
    '#title' => t('Array characters to trim'),
    '#default_value' => isset($settings['mask']) ? $settings['mask'] : '',
    '#description' => t('The characters to remove from the string. If blank, then whitespace will be removed.'),
  );
  $form['side'] = array(
    '#type' => 'radios',
    '#title' => t('Side'),
    '#default_value' => isset($settings['side']) ? $settings['side'] : 'trim',
    '#options' => array('trim' => t('Both'), 'ltrim' => t('Left'), 'rtrim' => t('Right')),
  );
  return $form;
}



function feeds_tamper_trim_array_callback($result, $item_key, $element_key, &$field, $settings, $source) {

	array_walk($field, 'trim_value');
}



function trim_value(&$value)
{
    $value = trim($value);
}
