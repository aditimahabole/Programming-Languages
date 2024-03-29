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
    msg!("Hello World Rust program entrypoint");
    //msg! helps to print on screen
    //msg is macro provided by solana

    // Iterating accounts is safer than indexing
    let accounts_iter = &mut accounts.iter();

    // Get the account to say hello to
    let account = next_account_info(accounts_iter)?;

    // The account must be owned by the program in order to modify its data
    if account.owner != program_id {
        msg!("Greeted account does not have the correct program id");
        return Err(ProgramError::IncorrectProgramId);
    }

    // Increment and store the number of times the account has been greeted
    //try_from_slice take account section from bytes and convert to struct type
    let mut greeting_account = GreetingAccount::try_from_slice(&account.data.borrow())?;
    greeting_account.counter += 1;
    greeting_account.serialize(&mut *account.data.borrow_mut())?;

    msg!("Greeted {} time(s)!", greeting_account.counter);

    Ok(())
    //does not have semicolon mean we are returning this
    //so to return dont apply semi colon
    //or write return Ok(();)
}
