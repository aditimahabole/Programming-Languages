//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;

contract Mapping_in_Struct
{
          //key   value
    struct Student
    {
        string name;
        uint class;
    }
   mapping(uint => Student)public data;
   function setter(uint _roll,uint _class, string memory _name) public
   {
       data[_roll]=Student(_name,_class);
   }
   //here no sequncial order is needed
}
