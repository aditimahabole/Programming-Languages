//call stack-->Node API -->callback Queue
// setTimeout is a c++ function  so it goes into Node Api 
//and then 0s setTimeout is sent to callback queue because of less burst time
// and during this process  finishing done is executed 
//and then 0s log is done
//at last 2s log is executed 

console.log('starting up ')
setTimeout(()=>{
    console.log('2 sec log')
},2000)

setTimeout(()=>{
    console.log('0 sec log')
},0)
console.log('finishing done');
//OUTPUT-->
starting up
finishing done
0 sec log
2 sec log
