<!-- Variables. You know them. You've used them. You've probably even misspelled them. The only thing new about Rust variables is mutability. 
All variables in Rust are immutable by default - you can't change the value of a variable once it's been declared.
All you gotta do is tell the compiler that you want a mutable variable by adding the mut keyword. Ezpz. 
If we don't provide the type, the compiler will infer it based on the data we provide. It will then enforce that we maintain that type over time. -->

use borsh::{BorshDeserialize, BorshSerialize};
//use ->import
//borsh -> pckage for handling bytecode
//:: is similar to '/' or a '.' to traverse code tree
//similar to import {BorshSerialze} from 'borsh'
use solana_program::{
    account_info::{next_account_info, AccountInfo},
    entrypoint,
    entrypoint::ProgramResult,
    msg,
    program_error::ProgramError,
    pubkey::Pubkey,
};

/// Define the type of state stored in accounts
#[derive(BorshSerialize, BorshDeserialize, Debug)]
//macro that assigns a trait to BorshDeserize, these are kind of interfaces
pub struct GreetingAccount {
    /// number of greetings
    pub counter: u32,
}
//structure

// Declare and export the program's entrypoint
entrypoint!(process_instruction);
//this is solana provided macro
// function process  instruction
//its the entry point we can chnage the name
// entrypoint!(bubu);
//then pub fn bubu() we have to write like this

// Program entrypoint's implementation
pub fn process_instruction(
    program_id: &Pubkey, // Public key of the account the hello world program was loaded into
    accounts: &[AccountInfo], // The account to say hello to
    _instruction_data: &[u8], // Ignored, all helloworld instructions are hellos
) -> ProgramResult {
    //this -> arrow returns a type
    msg!("Hello Buddy");
    let mut age = 20; // changable variable
    age = 21;
    msg!("my age is : {age}")
    Ok(())
    
}
