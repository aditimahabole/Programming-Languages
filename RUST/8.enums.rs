enum Coin{
    attani,
    chawanni,
    paise,
    rupiya,
}
fn value_in_cents(coin:Coin)->u8{
    match coin{
        Coin::attani=>0.75
        Coin::chawanni=>0.25
        Coin::paise=>1
        Coin::rupiye=>10 
    }
}

Enums, variants & match
Enums are pretty simple - they're like drop-down lists in code. They force you to choose from a list of several possible variants.
The cool thing about enums in Rust is that you can (optionally) add data to them - making it almost like a mini if statement. In this example you're choosing the status of a traffic light. If it's on, you need to specify the colour - is it red, yellow or green?
Enums are great when used in conjunction with match statements. They're a way to check the value of a variable and execute code based on the value - the same as switch statements in Javascript.
