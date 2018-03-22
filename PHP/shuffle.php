<?php
$states = array("Uttar Pradesh"=>"UP", "Madhya Pradesh"=>"MP", "West Bengal"=>"WB");
   $keys = array_keys($states);

        shuffle($keys);

        foreach($keys as $key) {
            $new[$key] = $states[$key];
		
        }

        $array = $new;
 	foreach($array as $x => $x_value) {
   		 echo "Key=" . $x . ", Value=" . $x_value;
  	        echo "<br>";
        }
?>