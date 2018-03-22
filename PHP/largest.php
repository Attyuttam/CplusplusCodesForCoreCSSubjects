<?php
	$arr=array(1,2,3,4,1,29,15,28,36,12,45);
	$max=$arr[0];
	for($i=1;$i<count($arr);$i++){
		if($arr[$i]>$max){
			$max=$arr[$i];
		}
	}
	echo "Largest element: ".$max;
?>