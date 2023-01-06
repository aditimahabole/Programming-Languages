const {MongoClient} = require('mongodb');
const colors  = require('colors');
const url = 'mongodb://localhost:27017';
const client = new MongoClient(url);
const database = 'User';
const Collection = 'Users'
async function get_data()
{
    let result = await client.connect();
    let db = result.db(database);
    let collection = db.collection(Collection);
    let response = await collection.find({}).toArray();
    console.log(response);
    console.log('my response'.blue);
}
get_data();
