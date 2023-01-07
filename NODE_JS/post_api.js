const express = require('express');
const db_connection = require('./mongodb');
const app = express();
app.use(express.json());

//post API 
//POSTMAN API me GET method me body use nhi kar sakte 
app.get('/',async (req,res)=>{
    let data = await db_connection();
    data = await data.find().toArray();
    console.log(data);
    res.send(data);
});
//POST API
app.post('/',async (req,res)=>{
    console.log(req.body);
    let data = await db_connection();
    let result =await  data.insert(req.body);
    res.send(result);
})
app.listen(5000);
