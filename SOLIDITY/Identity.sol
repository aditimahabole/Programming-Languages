//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Identity
{
    string name;
    uint age;
    constructor() public
    {
        name="Ravi";
        age=17;
    }

    function getName() view public returns(string memory)
    {
        return name;
    }
     function getAge() view public returns(uint)
    {
        return age;
    }

    function setAge() public 
    {
        age=age+1;
    }
}
