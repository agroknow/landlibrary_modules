<?php
/**
 * @file
 * Create new node.
 */

$plugin = array(
  'form' => 'feeds_tamper_create_new_node_form',
  'callback' => 'feeds_tamper_create_new_node_callback',
  'name' => 'create new node',
  'multi' => 'direct',
  'category' => 'List',
);

function feeds_tamper_create_new_node_form($importer, $element_key, $settings) {
  $form['reduce_method'] = array(
    '#type' => 'radios',
    '#title' => t('Method to create new Person node'),
    '#options' => array(
      'first' => t('Create 1 node'),
      'second' => t('Create 2 nodes'),
    ),
    '#required' => TRUE,
    '#default_value' => isset($settings['reduce_method']) ? $settings['reduce_method'] : NULL,
  );
  return $form;
}

function feeds_tamper_create_new_node_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (!is_array($field)) {
  
  
  switch ($settings['reduce_method']) {
    case 'first':
  
//
$values = array(
  'type' => 'person',
  'status' => 1,
  'promote' => 0,
);
$entity = entity_create('node', $values);

// The entity is now created, but we have not yet simplified use of it.
// Now create an entity_metadata_wrapper around the new node entity
// to make getting and setting values easier
$ewrapper = entity_metadata_wrapper('node', $entity);

// Using the wrapper, we do not have to worry about telling Drupal
// what language we are using. The Entity API handles that for us.
$ewrapper->title->set($field);
//$ewrapper->title->set(field_person_full_name)->set($field);
$ewrapper->save();
//
      break;
    case 'second':
              
       break;
 
  }
 }//if
}
