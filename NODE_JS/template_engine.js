//dynamic routing
const express = require('express')
const app = express();
app.set('view engine','ejs');
//template engine used 
//for this we make a folder named views only
//and make file profile.ejs 
//and write same html code in that 
// and by using this  we can send data from server to client
app.get('/profile',(req,res)=>{
    const user  =[{
        name:"Aditi Mahabole",
        age : 20,
        city :"Noida"
    },
    {
        name:"Molshree Shamra",
        age : 21,
        city :"Lucknow"
    }
]
    res.render('profile',{user});
    //user is object
})
app.listen(8080);
