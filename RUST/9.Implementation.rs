<!-- if we want to addd functions to stuct we use impl simple!  -->
<!-- Structs are pretty cool, but what if you could add functions to them?
Meet implementations: they let you add methods to structs, making them a lot more like objects.
If you're confused about what it means to "add methods to a struct" - 
think of it like giving abilities to a struct. You can have a plain user struct that has speed, health and damage.
 By using impl to add a wordPerMinute method, you could calculate the user's typing speed ⌨️. -->

struct Example{
    number:i32
}

impl Example{
    fn boo(){
        println!("boo is called");
    }
    fn answer(&mut self)
        {
            self.number +=12;
        }
    fn get_number(&self)->i32{
        self.number
    }
}

Example :: boo(); // function called
let mut ex = Example{number:3};
example.answer();
