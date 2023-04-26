Traits
And finally, the top of the cake. Traits are similar to implementations - they add functionality to types. Think of them like qualities that types can have.

Going back to our user struct, if I added a ThreeArms trait, the user would be able to type 50% faster because they'd have an extra arm! Traits are a bit abstract, so let's look at a real scenario we'll use them in:



As you'll remember, our instruction data comes in the form of a byte array (1s and 0s) and we deserialize it (convert it to a Rust type) in our program. We'll be using the BorshDeserialize trait to do this: it has a deserialize method that turns our data into a type we want. This means if we add the BorshDeserialize trait to our instruction struct, we can use the deserialize method to turn our instruction data instances into a Rust type.

Feel free to read that again if it's confusing lol, it took me a while to wrap my head around it.

Here's what that looks like in practice:


Note - A layer you might have forgotten about is Macros: they generate code.

In our case, traits are used in conjunction with macros. For example, the BorshDeserialize trait has two functions that must be implemented. deserialize and try_from_slice. We can use the #[derive(BorshDeserialize)] attribute to tell the compiler to implement those two functions for us on a given type (i.e. an instruction data struct).
The flow is:

You add the trait to a struct through the macro
The compiler will then look for the trait definition
The compiler will then implement the underlying functions for that trait
Your struct now has the functionality of the trait
What actually happens here is the macro generates the functions to deserialize strings on compile time. Using the trait we tell Rust: "Hey, I want to be able to deserialize strings, so please generate the code for me".

The only requirement in our scenario is that Borsh needs to support all the struct data types (String in our case). If you have a custom data type not supported by borsh, you'll need to implement the functions yourself by adding onto the macro.

If this hasn't clicked yet, don't worry! I didn't get it until I saw the whole flow in action, so let's do that now!
