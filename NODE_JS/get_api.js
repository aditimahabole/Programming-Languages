const express = require('express');
const db_connection = require('./mongodb');
const app = express();

//get API 
//POSTMAN API me GET method me body use nhi kar sakte 
app.get('/',async (req,res)=>{
    let data = await db_connection();
    data = await data.find().toArray();
    console.log(data);
    // res.send({name:"Aditi"})
    res.send({data});
});
app.listen(5000);
//after running this postman api me url daalo aur waha sara data mil jaega
