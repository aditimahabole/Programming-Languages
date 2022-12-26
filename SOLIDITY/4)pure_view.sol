


//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract View_Pure
{
    
  uint public age=20;
//   pure-> when state var is not read nor write in that funtion then use it
//   view-> when read is allowed in funtion but not write
     function  getter() public  pure returns (uint)
     {
         return age;//error because pure is used
         //and pure is only applicable when no state variable is used
         //but here we are using state variable so error showing

     }


      function  getter() public  pure returns (uint)
     {
         uint roll=23;
         return roll;//here no error showing kyuki local variable ko return karwa rhe
         //state variable ka use nhi ho rha so pure likh sakte

     }

      function  getter() public  view returns (uint)
     {
         return age;//this is valid

     }
      function  getter() public  view returns (uint)
     {
         uint roll=23;
         return roll;//this is also  valid

     }
     //conclusion in view we can read state var value but not write
     //but in pure we cant do read /write both





}
