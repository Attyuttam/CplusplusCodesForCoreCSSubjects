<?php
	$arr=array(1,2,3,1,4,1,1,5,2);
	$val=2;
	$count=0;
	foreach($arr as $x){
		if($x==$val){
			$count++;
		}
	}
	echo "$count";
?>