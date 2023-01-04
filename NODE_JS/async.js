const colors = require('colors');
//asynchronous
// first line -> loading
//              second line -> also starts loading
//                             third line -> also starts loading
//does not wait to complete one task fully
//less time taken 
//synchronously-->
console.log("--synchronously--".blue);
console.log('start execution');
console.log('logic execution');
console.log('complete execution');
//output ->
// start execution
// logic execution
// complete execution
console.log("-----------------");

//asynchronous -->
console.log("--asynchronously--".green);
console.log('start execution');
setTimeout(()=>{
    console.log('logic execution took 2 sec');
},2000)
console.log('complete execution');
//output ->
// start execution
// complete execution
// logic execution
//drawback 
let a = 10;
let b = 0;
console.log('a = ',a);
console.log('b = ',b);
setTimeout(()=>{
    b = 20;
    console.log('b updated to ',b+ ' and took 2 sec');

},2000)
console.log(a+b);
//drawback is that after second statement
//b value has to be 20 and then addition should be performed 
// but due to its delay it executes 3rd statement as well 
//and we get wrong answer
//so to solve thi we use await and promises

//OUTPUT -->
--synchronously--
start execution
logic execution
complete execution
-----------------
--asynchronously--
start execution
complete execution
a =  10
b =  0
10 
// A+B = 10+0 =10 ,although it should be 10+20 because b = 20 after second statement 
//but as it took more time 
//and due to async property a+b executed first before updation 
logic execution took 2 sec
b updated to  20 and took 2 sec
