const express = require('express')
const app = express();
const path = require('path');
const public_path = path.join(__dirname,'public');//name of folder
//public contains about.html
//so when server is on and in url we write /about.html
//our html file will be seen
console.log(public_path);
app.use(express.static(public_path));
app.listen(8080);
