<?php
	$m=6;
	$n=5;
	echo '<table border=1 style="border-collapse:collapse" cellpadding="8">';
	for($i=1;$i<=$m;$i++){
		echo "<tr>";
		for($j=1;$j<=$n;$j++){
			echo "<td>".$i." * ".$j." = ".($i*$j)."</td>";
		}
		echo "</tr>";
	}
	echo "</table>";
?>