<?php
	function keep_back(){
		static $count=2;
		$count++;
		echo $count;
	}
	keep_back();
	keep_back();
?>