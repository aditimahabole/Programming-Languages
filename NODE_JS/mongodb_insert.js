const db_connection= require('./mongodb')

const insert = async () =>{
    console.log ("Inserting...");
    const db = await db_connection();
    console.log(db);//database print ho jaega 
    const result =  db.insert([{
        name:"Arushi",
        enroll:"20103009",
        grade:"B+",
        subject:"COA"
    },
    {
        name:"Samarth",
        enroll:"20103017"
    }
])
}
insert();
