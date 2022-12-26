//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;

contract Mapping
{
    
   mapping(uint=>string)public roll_no;
   function setter(uint keys,string memory value) public
   {
       roll_no[keys]=value;
   }
   //here no sequncial order is needed
}
