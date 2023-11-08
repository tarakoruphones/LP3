// SPDX-License-Identifier: MIT
pragma solidity ^0.8.7;
contract bank{
    
    int bal;


    function get() view public returns(int)
    {
        return bal;
    }

    function deposit(int amt) public 
    {
        bal=bal+amt;
    }

    function withfraww(int amt) public 
    {
        bal=bal-amt;
    }
}