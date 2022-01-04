
#include <iostream>
#include <string>
#include <unordered_set>
// The unordered_set::rehash() is a built-in function in C++ STL which is used to set the number of buckets in the container of unordered_set to given size or more

// If size is greater than the current size of the container, then rehash is called. If it is lower than the current size, then the function has no effect on bucket count of hash.

// defalut value of alpha (load factor is 0.75)


// LINKS TO UNSERSTAND THE CONCEPT :
// https://www.geeksforgeeks.org/unordered_set-rehash-function-in-c-stl/
// https://www.geeksforgeeks.org/load-factor-and-rehashing/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main() 
{
    unordered_set<string> set;
    set.rehash(2); //set.rehash(9); TRY WITH THIS ONE ALSO
    set.insert("aditi");
    set.insert("is");
    set.insert("a");
    set.insert("good");
    set.insert("girl");
    set.insert(".");
    set.insert("chunnu");
    set.insert("bola");
    set.insert("yay");
    set.insert("boleto");
    set.insert("chal");
    set.insert("hatt");
    // here you can reduce the inserted values and see output then you will understand what is happening
    cout<<set.size();
    cout<<endl;
    for(auto i=set.begin();i!=set.end();i++)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;
    cout<<"Bucket count is : "<<set.bucket_count();
    return 0;
}
