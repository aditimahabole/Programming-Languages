//Middleware
//used for authentication 
const express = require('express');
const app = express();
const request_filter= (req,res,next)=>{
    console.log('request filter');
    if(!req.query.age)
    {
        res.send("pls provide age");
    }
    else if(req.query.age<=17)
    {
        res.send("You cannot access this page")
    }
    else 
    {
        next();//compalsory hai lagana
    }
    
}
app.use(request_filter);
app.get('/',(req,res)=>{
    res.send("welcome to home");
})
app.get('/users',(req,res)=>{
    res.send("welcome to users");
})
app.listen(8080);
