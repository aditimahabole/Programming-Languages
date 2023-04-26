<!-- Functions in Rust
Functions are pretty similar to Typescript - just need parameters, types and a return type. Add this under the entrypoint! macro:
 -->


pub fn process_instruction(
    //Arguments and their types
    program_id: &Pubkey,
    accounts: &[AccountInfo],
    instruction_data: &[u8]
    // The return type (i.e. what data type the function returns)
) -> ProgramResult{
  // Leave the body empty for now :)
}


<!-- Our process_instruction function requires the following arguments: -->

<!-- program_id: The public key of the program account. Required to verify that the program is being called by the correct account. Of type &Pubkey.
accounts: which accounts the instruction touches. Required to be type &[AccountInfo]
instruction_data: 8 bit instruction data from our transaction. Required to be type &[u8]
The [] mean that AccountInfo and u8 are "slice" types - they're like arrays of unknown length. We don't call them arrays because they're lower level -
 a slice in Rust is a pointer to a block of memory 🤯 -->
