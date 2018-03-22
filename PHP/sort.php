<?php
	class sorting{
		function sort($arr,$n){
			for($i=0;$i<($n-1);$i++){
				for($j=0;$j<($n-1-$i);$j++){
					if($arr[$j]>$arr[$j+1]){
						$temp=$arr[$j];
						$arr[$j]=$arr[$j+1];
						$arr[$j+1]=$temp;
					}
				}	
			}
			for($i=0;$i<$n;$i++){
				echo $arr[$i]." ";	
			}
		}
		function sortimplicit($arr){
			sort($arr);
			$len=count($arr);
			for($i=0;$i<($len);$i++){
				echo $arr[$i]." ";	
			}
		}
	}
	$s=new sorting();
	$arr=array(5,4,3,2,1);
	$s->sort($arr,5);
	echo " <br>";
	$s->sortimplicit($arr);
?>