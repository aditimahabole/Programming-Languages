//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Arrays
{
   //dynamic array
   uint[] public arr;
   //dynamic array me hum push kar skte ya pop kar sakte
   function push_element(uint item) public{
       arr.push(item);
   }
   function len() public view returns(uint)
   {
       return arr.length;
   }
   function pop_element() public{
       arr.pop();
   }
}
