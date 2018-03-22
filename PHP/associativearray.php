<?php
	$states=array(0=>'Ap',1=>'Up',2=>'Mp');
	
	foreach($states as $i){
	
		echo "$i ";
	}
	print_r($states);
	echo "<br/> Next process: <br/>";
	$states1=array('Andhra'=>'Ap','Uttar'=>'Up','madhya'=>'Mp');
	foreach($states1 as $i){
	
		echo "$i ";
	}
	print_r($states1);
?>