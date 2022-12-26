//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;

contract Enum
{
    //jab hum kisi integral value ko name assign karte usse enum kehte
    enum user{allowed,not_allowed,wait}
             //0         1         2
    user public u1 = user.allowed;
    uint public lottery=1000;
    function owner() public{
        if(u1==user.allowed)
        {
            lottery=0;
        }
    }

    function change_owner() public{
        u1=user.not_allowed;
    }
   
}
