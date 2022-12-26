//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Arrays
{
   //fixed size-->
   //datataype
   //sqaure bracket
   uint [4] public arr=[10,20,30,40];//compile tim epe hi size bata diya hai to fixed kehete hai isse
   function setter(uint index,uint value)public{
       arr[index]=value;
   }
   function length()public view returns(uint)
   {
       return arr.length;
   }
}
