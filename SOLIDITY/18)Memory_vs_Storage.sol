//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;

contract Memory_Vs_Storage
{
    string [] public students=['aditi','molly','chaman'];
    function mem() public view
    {
        string[] memory s1=students;
        s1[0]='momo';//this does not chnage in students only in s1 array
    }
     function sto() public
    {
        string[] storage s1=students;
        s1[0]='momo';//this changes students array 0th location
        //ye ek pointer ki tarah act kar sakta like s1 student array pe point kar rha and 
        //jab change kiya s1 ko to student me bhi chnage hua
    }
}
