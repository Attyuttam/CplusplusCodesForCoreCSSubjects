<?php
    
  interface interdemo
    {
            function meth1();
            function meth2();   
           
    }
    
   class idemo implements interdemo
     {
             function meth1()    
                {
                        echo "We are in Method 1..";
                  }
              function meth2()
                 {
                       echo "We are in Method 2..";
                  }
       }
 $d=new idemo();
 echo "{$d->meth1()}";

?>
