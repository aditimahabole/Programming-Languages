//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;

  struct Student{
      uint roll;
      string name;
  }

contract Struct
{
    Student public s1;
    constructor (uint _roll,string memory _name)
    {
        s1.roll= _roll;
        s1.name= _name;
    }
    //for chnaging roll and name make a funtion
    function change (uint _roll,string memory _name) public{
        Student memory new_student = Student({
            roll:_roll,
            name:_name

        });
        s1=new_student;

    }
}
