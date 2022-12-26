//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;
contract If_ELse
{
  function check(int a) public pure returns(string memory)
  {
      string memory value;
      if(a>0)
      {
          value="greater than zero";
      }
      else if(a==0)
      {
          value="equal to 0";
      }
      else 
      {
          value ="less than zero";
      }
      return value;
  }
}
