<?php
	class factorial{
		function fac($x){
			$p=1;
			for($i=1;$i<=$x;$i++){
				$p=$p*$i;
			}
			echo "factorial is: ".$p;
		}
	}
	$f=new factorial();
	$f->fac(5);
?>