//Route level Middleware
//used for authentication 
const express = require('express');
const app = express();
const request_filter = require('./middleware');
//exporting middle ware form middleware.js 
//instead of writing code in this file
//below code is same as in middleware.js
// const request_filter= (req,res,next)=>{
//     console.log('request filter');
//     if(!req.query.age)
//     {
//         res.send("pls provide age");
//     }
//     else if(req.query.age<=17)
//     {
//         res.send("You cannot access this page")
//     }
//     else 
//     {
//         next();//compalsory hai lagana
//     }
    
// }

app.get('/',(req,res)=>{
    res.send("welcome to home");
})
//middleware applied to only one page
app.get('/users',request_filter,(req,res)=>{
    res.send("welcome to users");
})
app.get('/about', (req,res)=>{
    res.send("welcome to about");
})
app.listen(8080);
