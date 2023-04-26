<!-- That's what our second use statement is for - it brings in the entrypoint! macro: a special kind of main function that Solana will use to run our instructions.

Macros are like code shortcuts - they're a way to write code that writes code. entrypoint!(process_instruction); will expand to a bunch of boilerplate code at compile time, sort of like a template. You don't need to know how macros work, but you can read more about them here.

Our entrypoint function will call process_instruction, so here's what our lib.rs file should look like so far: -->

use solana_program::{
    account_info::AccountInfo,
    entrypoint,
    entrypoint::ProgramResult,
    pubkey::Pubkey,
    msg
};

entrypoint!(process_instruction) // simimar to main , start from this function
