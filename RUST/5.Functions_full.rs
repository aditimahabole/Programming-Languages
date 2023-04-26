<!-- Since our function body is empty, it's implicitly returning () - the empty tuple. 
The error message says it's expecting Result, but we declared the return type to be ProgramResult.
Hmmmm what going on here 🤔?
This is because the Solana ProgramResult type is using the Rust Result type: -->

pub type ProgramResult = Result<(), ProgramError>;
  
<!-- Result is a standard library type that represents two discrete outcomes:
success (Ok) or
failure (Err) -->
  
pub enum Result<T, E> {
    Ok(T),
    Err(E),
}
<!-- Think of it like HTTP error codes -- 200 is Ok and 404 is Err. So when we return ProgramResult we're saying that our function can either return () (an empty value) for success, or use the custom ProgramError enum to tell us exactly what went wrong. Useful!

Here's all we need to do to fix it: -->

pub fn process_instruction(
    program_id: &Pubkey,
    accounts: &[AccountInfo],
    instruction_data: &[u8]
) -> ProgramResult{
  // Return Ok() for success
  
  Ok(())
}
