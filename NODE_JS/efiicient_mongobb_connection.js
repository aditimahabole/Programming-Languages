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
console.warn(db_connection())
//output ->Promise { <pending> }
// to solve it we use .then function

// first method 
db_connection().then((res)=>{
    console.warn(res.find().toArray())
    // toArray returns -> Promise
    // so we use .then 
    res.find().toArray().then((data)=>{
        console.warn(data)
    })
})
//output again ->Promise { <pending> }


// 2nd method efficient 
const main = async ()=>{
    console.log("main function");
    let data = await db_connection();
    data = await data.find().toArray();
    console.log(data)
}
main();



//OUTPUT -->
Promise { <pending> }
main function
Promise { <pending> }
[
  {
    _id: new ObjectId("63b7ed5ab2752fb366a83b13"),
    name: 'Aditi',
    enroll: '20103023',
    grade: 'B+',
    subject: 'COA'
  },
  {
    _id: new ObjectId("63b7ed87b2752fb366a83b14"),
    name: 'Molshree',
    enroll: '20103060',
    grade: 'A+',
    subject: 'COA'
  },
  {
    _id: new ObjectId("63b7ee27469d546a873c6087"),
    name: 'Pranay',
    enroll: '20103061',
    grade: 'B+',
    subject: 'COA'
  }
]
[
  {
    _id: new ObjectId("63b7ed5ab2752fb366a83b13"),
    name: 'Aditi',
    enroll: '20103023',
    grade: 'B+',
    subject: 'COA'
  },
  {
    _id: new ObjectId("63b7ed87b2752fb366a83b14"),
    name: 'Molshree',
    enroll: '20103060',
    grade: 'A+',
    subject: 'COA'
  },
  {
    _id: new ObjectId("63b7ee27469d546a873c6087"),
    name: 'Pranay',
    enroll: '20103061',
    grade: 'B+',
    subject: 'COA'
  }
]

