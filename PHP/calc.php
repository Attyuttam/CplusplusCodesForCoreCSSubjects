<?php
	class datec{
		function calc(){
			echo "1st number entered is: ".$_GET["v1"]."<br/>";
			echo "2nd number entered is: ".$_GET["v2"];
			if (isset($_GET["add"])){
 		
				echo "<br>Sum: ".($_GET["v1"]+$_GET["v2"]);
			} 
			if(isset($_GET["div"])){
 		
				echo "<br>Division: ".($_GET["v1"]/$_GET["v2"]);
			}
			if(isset($_GET["mul"])){
 			
				echo "<br>Product: ".($_GET["v1"]*$_GET["v2"]);
			}
			if(isset($_GET["sub"])){
 		
				echo "<br>Difference: ".($_GET["v1"]-$_GET["v2"]);
			}
		}
	}
	$ob=new datec();
	ob->calc();	
?>