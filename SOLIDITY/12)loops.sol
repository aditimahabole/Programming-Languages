//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Loops
{
   uint[3] public arr;
   uint public count;
   //hum ese kabhi bhi while loop declare nhi kar sakte hai
   //humesha function ke ander hi use karna hai
//    while(count<arr.length)
//    {
//        arr[count]=count;
//    }
      function loop() public 
      {
          while(count<arr.length)
          {
              arr[count]=count;
          }

          for(uint i=count;i<arr.length ;i++)
          {
              arr[i]=i;
          }

          do
          {
              arr[count]=count;
              count++;

          }while(count<arr.length);
      }
}
