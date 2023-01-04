// code for making updating deleting a file in NodeJS
const fs = require('fs');
const path = require('path');
const dir_path = path.join(__dirname,'curd');//curd is folder name i created in vs code
//dir_path = myfoldername/curd 
const file_path = `${dir_path}/buibui.txt`;
//text file i want to create that is buibui.txt
//creating a file and writing
fs.writeFileSync(file_path,'This is simple buibui text bro');
//reading file 
fs.readFile(file_path,'utf8',(err,item)=>{
    console.log(item);
});
//updating file
fs.appendFile(file_path,`<br></br> adding a new line? `,(err)=>{
    if(!err) console.log('file is updated');
    else console.log(err);
});
//rename 
fs.rename(file_path,`${dir_path}/buibui.txt`,(err)=>{
    if(!err) console.log('file is renamed');
})
//deleting a file 
fs.unlinkSync(`${dir_path}/buibui.txt`);
