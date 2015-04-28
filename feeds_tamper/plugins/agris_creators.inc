<?php
/**
 * @file
 * Create agris creators nodes.
 */

$plugin = array(
  'form' => 'feeds_tamper_create_mul_nodes_form',
  'callback' => 'feeds_tamper_agris_creators_callback',
  'name' => 'Agris creator filter',
  'multi' => 'direct',
  'category' => 'List',
);

function feeds_tamper_agris_creators_form($importer, $element_key, $settings) {
  $form = array();

  $form['default_value'] = array(
    '#type' => 'textarea',
    '#title' => t('Create multiple creators'),
    '#default_value' => isset($settings['default_value']) ? $settings['default_value'] : '',
    '#description' => t('This field will be set to the preferable content type machine name.'),
  );
  return $form;


}

function feeds_tamper_agris_creators_callback($result, $item_key, $element_key, &$field, $settings, $source) {

      $c_type = $settings['default_value'];

/*      if (!is_array($field)) {
           $row = db_query("SELECT nid FROM {node} WHERE title = :mytitle", array(':mytitle' => $field))->fetchField();

        if ( !isset($row['nid'])){
        //$keys = array_keys($field);
                $full_name = substr($field  , 0  ,60 );





 }else
 { */
  foreach($field as $value){

        // $comma_counter = 0; //        $comma_counter = substr_count($value,',');     //        $value = preg_replace('/^([^,]*).*$/', '', $value );
              //  $myfile = fopen("/var/www/htdocs/newfile.txt", "w") or die("Unable to open file!");
         //    fwrite($myfile, "\n value = ");  //      fwrite($myfile, $value);//        fwrite($myfile, "\n0000000000 before if 000000000000000000000\n0");
    //$row = db_query('SELECT nid FROM {node} WHERE title = :mytitle', array(':mytitle' => $value))->fetchField(); // mysql_real_escape_string();

//   if( !empty($value) && !isset($row['nid']) ){
 //    $row = db_query("SELECT nid FROM {node} WHERE title = :mytitle", array(':mytitle' => $value))->fetchField();

/////////////////////////////////////       $full_name = substr( $value  , 0  ,60 );

  /////     $pieces = explode(" ", $value);
  ////     $value = $pieces[0] . " " . $pieces[1];
  ////     $value  = preg_replace( '/,/','' , $value);

   if( !empty($value) ){ //&& !isset($row['nid'])

   //////   if( strlen($value) > 40  && isset($value)){
   /////       $value =  substr($value  , 0  ,39 );
   /////    }
           $value = trim($value);
       $row = db_query('SELECT title  FROM {node} WHERE title = :title', array(':title' => $value))->fetchField();

        if(!isset($row['title'])){


     $values = array(
        'type' => $c_type,
        'status' => 1,
        'promote' => 0,
        );
        $entity = entity_create('node', $values);

                // The entity is now created, but we have not yet simplified use of it.
                // Now create an entity_metadata_wrapper around the new node entity
                // to make getting and setting values easier
        $ewrapper = entity_metadata_wrapper('node', $entity);

            // to make getting and setting values easier
        $ewrapper = entity_metadata_wrapper('node', $entity);

                // Using the wrapper, we do not have to worry about telling Drupal
                // what language we are using. The Entity API handles that for us.
          //        if( strlen($value) > 40  && isset($value)){
          //       $value =  substr($value  , 0  ,39 );
          //   }
       // if(!in_array($value,$previous)){
        //$previous = $value;
       // array_push($previous,$value);}
        $ewrapper->title->set($value);
                //      $ewrapper->field_person_full_name->set($full_name);
        $ewrapper->save();

     }//row
    }//ifempty


  }//foreach

//}//if






}

