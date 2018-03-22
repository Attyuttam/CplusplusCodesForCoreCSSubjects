<?php
interface  I1
           {
	const x=7;
	function x(); 
             }
class A implements I1
        {
                  function x()
                        {
                                echo  "x value is".self::x;
                         }
          }
$a=new A();
$a->x();
?>
