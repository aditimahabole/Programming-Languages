


//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Loacal
{
   //ye variable humare stack me store hote hai
   //pure->naahi humare state variable me change la rha and naahi read kar rha state variable ko

   function store() pure public returns(uint)
   {
       uint age=10;//ye humara local variable hai jo stack me store hua
       return age;

       string name ="ravi";
       //string data type jo hai vo humara storage me use hota hai bydefault
       //matlab ki ye contract level pe hi dclare hota
       //and if we want to use in local form
       string memory name = "aditi";
       //memory key word ka use karna padhta

   }

}
