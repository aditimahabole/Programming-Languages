let a = 10;
let b = 0;
console.log('before updation ');
    console.log('a = ' ,a);
    console.log('b = ', b);
//promises

let waiting_data = new Promise((resolve,reject)=>{
    setTimeout(()=>{
        resolve(30)//changing value of b
    },2000);

})
waiting_data.then((b)=>{
    console.log('after updation ');
    console.log('a = ' ,a);
    console.log('b = ', b);
    console.log('after addition = ',a+b);
})
//OUTPUT -->
before updation
a =  10
b =  0
after updation
a =  10
b =  30
after addition =  40
