<?php

/**
 * @file
 * Filters out empty values from an array.
 */

$plugin = array(
  'form' => 'feeds_tamper_array_order_form',
  'callback' => 'feeds_tamper_array_order_callback',
  'name' => 'Order IFPRI array items',
  'multi' => 'direct',
  'category' => 'List',
);

function feeds_tamper_array_order_form($importer, $element_key, $settings) {
  $form = array();
  $form['help'] = array(
    '#markup' => t('Return an orderd list of IFPRI values with first http://cdm ,second numerical and third http://www.ifpri.org/'),
  );
  return $form;
}

function feeds_tamper_array_order_callback($result, $item_key, $element_key, &$field, $settings, $source) { 


      //  $pattern1= "http://cdm";
      //  $pattern2= "http://www.ifpri.org/";



 if (is_array($field)) {

    $field = feeds_tamper_checkIdentifiersOrder($field ); //array_values(array_filter($field));
   //  array_values($field);


 }
}


function feeds_tamper_checkIdentifiersOrder($inputarray) {
	$pattern1= "http://cdm";
	$pattern2= "http://www.ifpri.org/";
	
	if (is_array($inputarray)){
		$array_length = count($inputarray);
		$new_array = array('','','');
		for($i=0;$i<$array_length;$i++){
			$var1 = $inputarray[$i];
			if(stripos($var1, $pattern1)!==false){
				$new_array[0] = $var1;
			}elseif (is_numeric($var1)) {
				$new_array[1] = $var1;
			}elseif (stripos($var1, $pattern2)!==false) {
				$new_array[2] = $var1;
			}
		}
		return $new_array;
 	// If it is not array
	}else{
		$var1 = $inputarray;
                        if(stripos($var1, $pattern1)!==false){
                                return $var1;
                        }elseif (is_numeric($var1)) {
                                 $var1 = "";
                        }elseif (stripos($var1, $pattern2)!==false) {
                                $var1 = "";
                        }

	}
       
        $var1="";
}
