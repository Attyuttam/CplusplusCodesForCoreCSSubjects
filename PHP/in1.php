<?php

class  Person
   {
	private $name;
	private $gender;
	private $address;
	function setInfo()
                        {
		$this->gender="male";
		$this->address="tpt";
		$this->name="vijay";
	     }
          function getInfo()
                      {
                            echo "gender is.$this->gender";
	         echo "$address is"."$this-> address";
	         echo "$name is $this-> name";
                      }
        /*   function eat()
                      {
                             echo "each person will take food to survive";
                       }  */
           function sleep()
                      {
                            echo "each person will sleep to take rest ";
                      }
             }
          class  Doctor extends Person
                    {
	           private $qualification;
	     function setdoctorInfo()
		{
		$this-> qualification="MBBS";
		$this->setInfo();
		}   
                        function getdoctorInfo()
                                     {
		$this->getInfo();
		echo "qualification is"."$qualification";
		}

	    function dosurgery()
		{
			echo "as a  $this->qualification qualified  person will take food to survive ";
                                      }
                    }
 $d=new Doctor();
$d->setdoctorInfo();
$d->getdoctorInfo();
$d->dosurgery();
//$d->eat();//ok

?>
