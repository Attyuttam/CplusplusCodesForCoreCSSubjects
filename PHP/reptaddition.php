<?php
	$x=991;
	while($x>9){
		$t=$x;
		$sum=0;
		while($t!=0){
			$r=$t%10;
			$sum=$sum+$r;
			$t=floor($t/10);
		}
		$x=$sum;
	}
	echo $x;
?>