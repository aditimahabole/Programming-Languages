


//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Functions
{
    //getters and setters
   uint age = 10;
   //how to create a function->
   //1)function keyword
   //2)name of funtion 
   //3) () brackets 
   //4)visibility ->public ,private
   //5) write pure or view 
   //6)kya data type get karne wale ho returns(datatype)
   function getter() public view returns(uint)
   {
       return age;
   }
   function setter() public 
   {
       age=age+1;
   }
   //after argument passed
   function setter1(uint newAge) public 
   {
       age=newAge;
   }
   uint public num =11;
   //whenever public keyword is attached then 
   //automatically getter function is created for that state variable



}
