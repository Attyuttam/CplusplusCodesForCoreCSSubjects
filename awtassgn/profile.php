<?php
session_start();
$n=$_SESSION['name'];
include("loginattach.html");
echo "<center><h3>Welcome ".$n."</h3></center>";

?>
