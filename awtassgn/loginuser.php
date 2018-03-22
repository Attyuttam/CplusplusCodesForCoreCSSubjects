<?php
	error_reporting(E_ALL ^ E_DEPRECATED);
	$conn=mysql_connect("localhost","root","");
	mysql_select_db("student");
	$query="select * from profile";
	$result=mysql_query($query);
	$flag=0;
	while($stu=mysql_fetch_array($result)){

		$n=($_POST["name"]);
		$p=($_POST["password"]);

		if(strcmp(($stu['uname']),$n)==0 && strcmp(($stu['upass']),$p)==0){
			$flag=1;
			break;
		}
	}
	if($flag==1){
		session_start();
		$_SESSION['name']=$n;
		$_SESSION['pass']=$p;


		//echo "session set";
		include("loginattach.html");
		echo "<center><h3>Welcome ".$n."</h3></center>";
	}
	else{
		echo "<p style='color:red'>Sorry invalid user name or password</p>";
		include("login.html");
	}
	mysql_close($conn);
?>
