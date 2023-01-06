const db_connection = require('./mongodb');
const update_data = async () =>{
    let data = await db_connection();
    console.log(data);
    let result = data.updateOne(
        {enroll:"20103017"},
       { $set:{grade:"A+"}}
    )
}
update_data();
