<?php
$date1 = "1981-11-03";
$date2 = "2013-09-05";

$diff = abs(strtotime($date2) - strtotime($date1));;

$years=floor($diff/(365*60*60*24));
$months=floor(($diff - $years*365*60*60*24)/(30*60*60*24));
$num=ceil($diff - ($years*365*60*60*24) - ($months*31.2*60*60*24));

$days=floor($num/(60*60*24));
echo $years." years ".$months." months ".$days." days";
?>