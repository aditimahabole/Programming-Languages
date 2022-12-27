//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;

contract Global
{
    function demo() public view returns(uint block_no,uint timestamp,address msg_sender)
    {
        return(block.number,block.timestamp,msg.sender);
        //global variables are built in variables
    }
// 0:
// uint256: block_no 3
// 1:
// uint256: timestamp 1672133402
// 2:
// address: msg_sender 0x5B38Da6a701c568545dCfcB03FcB875f56beddC4
}
