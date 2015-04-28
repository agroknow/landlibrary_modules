<?php

/**
 * @file
 * Reduces an array to a single element.
 */

$plugin = array(
  'form' => 'feeds_tamper_reduce_to_single_element_bynum_form',
  'callback' => 'feeds_tamper_reduce_to_single_element_bynum_callback',
  'name' => 'Get single element',
  'multi' => 'direct',
  'category' => 'List',
);

function feeds_tamper_reduce_to_single_element_bynum_form($importer, $element_key, $settings) {
  $form['reduce_method'] = array(
    '#type' => 'radios',
    '#title' => t('Method to use when reducing the array to a single element'),
    '#options' => array(
      'first' => t('Use the first array element'),
      'second' => t('Use the second array element'),
      'third' => t('Use the third array element'),
      'fourth' => t('Use the fourth array element'),
       'fifth' => t('Use the fifth array element'),
       'sixth' => t('Use the sixth array element'),
      'last' => t('Use the last array element'),
      'array' => t('Create a single-valued array with the input array inside it'),
    ),
    '#required' => TRUE,
    '#default_value' => isset($settings['reduce_method']) ? $settings['reduce_method'] : NULL,
  );
  return $form;
}

function feeds_tamper_reduce_to_single_element_bynum_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  //if (!is_array($field)) {
  //  $field = array($field);
  // }
  switch ($settings['reduce_method']) {
    case 'first':
      $field = array_shift($field);
      break;
    case 'second':
            //array_push($field)
	$keys = array_keys($field);
      if (isset($keys[1])){  
    	$field =  $field[$keys[1]];
      }          
       break;
    case 'third':
	$keys = array_keys($field);
      if (isset($keys[2])){
            // $keys = array_keys($field);
       $field =  $field[$keys[2]];
     }
      break;
    case 'fourth':
	$keys = array_keys($field);
      if (isset($keys[3])){
            //$keys = array_keys($field);
      $field =  $field[$keys[3]];
      }
      break;
    case 'fifth':
      $keys = array_keys($field);
      if (isset($keys[4])){
           //$keys = array_keys($field);
      $field =  $field[$keys[4]];
      }
      break;
    case 'sixth':
      $keys = array_keys($field);
      if (isset($keys[5])){
          // $keys = array_keys($field);
      $field =  $field[$keys[5]];
      }
       break;
    case 'last':
      $field = array_pop($field);
      break;
    case 'array':
      $field = array($field);
      break;
  }
}
