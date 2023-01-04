//expressJS is framework for NodeJS
const express = require('express');
const app = express();//to make it executable
app.get('',(req,res)=>{
    res.send('hello ,this is home page')
});
app.get('/about',(req,res)=>{
    res.send('hello,this is about page');
});

app.listen(4000);
