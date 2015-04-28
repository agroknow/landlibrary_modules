<?php
/**
 * @file
 * Check if contains.
 */

$plugin = array(
  'form' => 'feeds_tamper_check_if_contains_form',
  'callback' => 'feeds_check_if_contains_callback',
  'name' => 'Check if contains',
  'multi' => 'direct',
  'category' => 'Other',
);

function feeds_tamper_check_if_contains_form($importer, $element_key, $settings) {
  $form = array();

  $form['default_value'] = array(
    '#type' => 'textarea',
    '#title' => t('Check if contains a given string else return null with use of substr'),
    '#default_value' => isset($settings['default_value']) ? $settings['default_value'] : '',
    '#description' => t('This field will sett the values of substr like: http 0 4.'),
  );
  return $form;


}


function feeds_tamper_check_if_contains_callback($result, $item_key, $element_key, &$field, $settings, $source) {

      $value = $settings['default_value'];
      $pieces = explode(" ", $value);
      if ( substr( $field, $pieces[1], $pieces[2] ) === $pieces[0] ){
	return $field;
      }else {
	$field = null;
        return $field;
     }  
     
}


