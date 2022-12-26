//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract Arrays
{
    bytes public b1 = "abc";//dynamic bytes array
    function push_element()public
    {
        b1.push('d');
        // b1.push(4);//wrong error happens
    }
    function get_element(uint i ) public view returns(bytes1)
    {
        return b1[i];
    }
    function get_length() public view returns(uint)
    {
        return b1.length;
    }

}
