<?php
	$states=array("Uttar Pradesh"=>"UP","Madhya Pradesh"=>"MP","West Bengal"=>"WB");
	$value="MP";
	$flag=0;
	foreach($states as $x=>$x_value){
		if(strcmp($x_value,$value)==0){
			$flag=1;	
			echo "found";
			break;
		}
	}
	if($flag==0){
		echo "Not found";
	}
?>