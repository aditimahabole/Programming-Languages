const {MongoClient} = require('mongodb');
const colors  = require('colors');
const url = 'mongodb://localhost:27017';
const client = new MongoClient(url);
const database = 'User';
const Collection = 'Users'
async function db_connection()
{
    let result = await client.connect();
    let db = result.db(database);
    let collection = db.collection(Collection);
    return collection;
}

module.exports = db_connection;
