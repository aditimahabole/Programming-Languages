//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Arrays
{
  //Byte array
  //values stored in hexadecimal form
  //1byte=8 bits
  //1 hexa decimal= 4bits
  //everything is stored in hexadecimal form
  bytes3 public b3;
  //bytes3 ka matlab 3 byte ka array create ho gya
  //byte4 ka matlab 4 byte ka 
  bytes2 public b2;
  function setter() public 
  {
      b3='abc';
      b2='ab';
      b2='a';//0x6100 for this padding of 0 occurs
    //   a in hexa decimal is 61 and so on

    //byte array is immutable that is cannot be mofified
    b3[0]='d';//we cant do this error will occur
  }



}
