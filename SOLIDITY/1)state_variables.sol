
//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract State
{
    // uint age;
    //-----state variable-----
    //ye block chain me store hota hai 
    //kuch amount of gas pay karni padhti
    // isiliye bohot hi sambhal ke use karna hota 
    //isme koi null ya none ka concept nhi hota
    //automatically iski value assign ho jati hai

    uint public age1;
    //public lagakr vo function ki tarah kaam karta

    uint public num;
    // num=1;//<------ wrong
    //esa hum assign nhi kar sakteeee
    //we have to use constructor or make stter function 
    function setNum() public 
    {
        num=10;
    }


}
