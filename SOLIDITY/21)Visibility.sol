//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;

contract Visibility
{
    function f1() public pure returns(uint)
    {
        return 1;//visibity to outside world
    }
    function f2() private pure returns(uint)
    {
        return 2;
    }
    function f3() internal pure returns(uint)
    {
        uint x=f4();//not posible
        //external jo hote unhe within the contract access nhi kar sakte
        uint y=f2();//possible 
        uint z=f1();//possible 
        uint a=f3();//possible 
        
        return 3;
    }
    function f4() external pure returns(uint)
    {
        return 4;//visibility to outside world
    }

}
// contract inheritance
contract B is Visibility
{
    //B sari properties inherti karega jo visibility me hai

    // uint public b=f2();//f2 is private and cannot be accessed
    //matlab private jo hai vo sirf with in the contract applicable hai
    //kisi aur contract me use nhi kar sakte usko

    uint public c=f3();//applicable
    uint public d=f1();//applicable
    uint public e=f4();// not applicable 
    // kyuki B jo hai f4 ko inherit kar rha and jab hum 
    // f4 ko call kar rhe to vo ek tarah se within the contract hi call ho rha

}
contract C 
{
    //other contract 
    Visibility object =new Visibility();//object of Visibility
    uint public c=object.f1();//applicable
    uint public d=object.f2();//not applicable(private)
    uint public e=object.f3();//applicable
    uint public f=object.f4();//applicable
}
