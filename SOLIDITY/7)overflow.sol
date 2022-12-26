//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Overflow
{
    uint8 public money=255;
    function setter() public{
        money=money+1;
        //here we are doing money =255+1 that is 256
        // but it is out of range and in output we are getting value 0
        // so iff someone send us value more than our container then the value is beccoming zero in account
        //dangerous 
        // but this is not a problem now a days but in lod compiler we can get this problem
    }
}
