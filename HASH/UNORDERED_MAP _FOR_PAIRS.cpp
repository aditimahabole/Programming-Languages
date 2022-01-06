//QUESTION RELATED TO THIS CONCEPT : 
//https://www.geeksforgeeks.org/count-maximum-points-on-same-line/
// here since we are using unordered_map 
    // which is based on hash function 
    //But by default we don't have hash function for pairs
    //so we'll use hash function defined in Boost library
    //INFO FOR UNORDERED_MAPS OF PAIRS IN C++
    //https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-pairs-in-c/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class hash_pair
{
    public:
    template<class T1,class T2>
    //* size_t is an unsigned integer data type which can assign only 0 and greater than 0 integer values. It measure bytes of any object's size and is returned by sizeof operator.
    
    //* In programming, an operator is a symbol that operates on a value or a variable. Operators are symbols that perform operations on variables and values. For example, + is an operator used for addition, while - is an operator used for subtraction.
    size_t operator()(const pair<T1,T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T1>{}(p.second);
        // auto hash11 = hash<T1>{}(p.first);
        // auto hash22 = hash<T1>{}(p.second);
        // cout<<hash11^hash22<<endl;
        
        return hash1^hash2;
    }
    
};

int main() 
{
    //can also be type 
    // unordered_map<pair<int,int>,char,hash_pair> um;
    // unordered_map<pair<int,int>,int,hash_pair> um;
    // unordered_map<pair<int,int>,bool,hash_pair> um;
    unordered_map<pair<int,int>,string,hash_pair> um;
    pair<int,int> p1(2,3);
    pair<int,int> p2(3,3);
    pair<int,int> p3(3,4);
    pair<int,int> p4(-1,1);
    pair<int,int> p5(2,2);
    
    // um[p1]='a';
    // um[p2]='b';
    // um[p3]='c';
    // um[p4]='d';
    // um[p5]='e';
    
    um[p1]="momo";
    um[p2]="bubu";
    um[p3]="dodo";
    um[p4]="pudina";
    um[p5]="nimbuda";
    
    cout<<"CONTENTES OF UNORDERED_MAP PAIR :"<<endl;
    for(auto i:um)
    {
        cout<<"[ "<<(i.first).first<<" , "<<(i.first).second<<" ]===>"<<i.second<<endl;
    }
    
    return 0;
}
/* OUTPUT: 
CONTENTES OF UNORDERED_MAP PAIR :
[ 3 , 4 ]===>dodo
[ 2 , 2 ]===>nimbuda
[ 3 , 3 ]===>bubu
[ -1 , 1 ]===>pudina
[ 2 , 3 ]===>momo
*/
