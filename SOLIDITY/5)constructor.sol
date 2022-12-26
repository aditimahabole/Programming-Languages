//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Constructor
{
    uint public count;//automatically getter function create ho jaega
    constructor()//without argument
    {
        count=8;
    }
    
    constructor(uint new_count)//with argument
    {
        count=new_count;
    }
    // conclusion ->
    // executed only once
    // only 1 constructor can be made 
    // defalut constructor is automatically made by compiler even if we don not make
}
