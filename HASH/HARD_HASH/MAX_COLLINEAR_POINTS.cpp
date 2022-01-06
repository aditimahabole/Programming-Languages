// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/////////////////HASH_PAIR CLASS////////////////////////
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
//////////////////////////////////////////////////////
// unordered_map can takes upto 5 arguments:
// Key : Type of key values
// Value : Type of value to be stored against the key
// Hash Function : A function which is used to hash the given key. If not provided it uses default hash function.
// Pred : A function which is used so that no two keys can have same hash values
// Alloc : An object used to define the memory model for the map
//////////////////////////////////////////////////////
int max_points(vector<pair<int,int>>points)
{
    int cur_max=0;
    int overlap_point=0;
    int vertical_point=0;
    int N=points.size();
    if(N<2)
    {
        return N;
    }
    int max_point=0;
    // here since we are using unordered_map 
    // which is based on hash function 
    //But by default we don't have hash function for pairs
    //so we'll use hash function defined in Boost library
    //INFO FOR UNORDERED_MAPS OF PAIRS IN C++
    //https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-pairs-in-c/
    unordered_map<pair<int,int>,int,hash_pair>slopemap;
    for(int i=0;i<N;i++)
    {
        cur_max=0;
        overlap_point=0;
        vertical_point=0;
        
        for(int j=i+1;j<N;j++)
        {
            if(points[i]==points[j])
            {
                cout<<"------------------------------------"<<endl;
                cout<<"point[i] = "<<points[i].first<<" and point[j] = "<<points[j].first<<endl;
                overlap_point++;
                //that is points x,y are equal x=y
                cout<<"Overlap Point Count = "<<overlap_point<<endl;
                cout<<"------------------------------------"<<endl;
            }
            else if(points[i].first==points[j].first)
            {
                cout<<"------------------------------------"<<endl;
                vertical_point++;
                cout<<"Vertical Point Count = "<<vertical_point<<endl;
                cout<<"------------------------------------"<<endl;
            }
            else
            {
                cout<<"------------------------------------"<<endl;
                int del_y=points[j].second-points[i].second;
                cout<<"del_y : "<<points[j].second<<" - "<<points[i].second<<" = "<<del_y<<endl;
                int del_x=points[j].first-points[i].first;
                cout<<"del_x : "<<points[j].first<<" - "<<points[i].first<<" = "<<del_x<<endl;
                int GCD=__gcd(del_x,del_y);
                cout<<"GCD of "<<del_x<<" and "<<del_y<<" = "<<GCD<<endl;
                del_y=del_y/GCD;
                del_x=del_x/GCD;
                cout<<"dividing the del_y and del_x by their GCD respectively: "<<endl;
                cout<<"Value of del_y = "<<del_y<<endl;
                cout<<"Value of del_x = "<<del_x<<endl;
                cout<<"------------------------------------"<<endl;
                
                
                //make_pair() : This template function allows to create a value pair without writing the types explicitly
                
                slopemap[make_pair(del_y,del_x)]++;
                cout<<"------------------------------------"<<endl;
                cout<<"current max = "<<cur_max<<endl;
                cout<<"slopemap[make_pair(del_y,del_x)] = "<<slopemap[make_pair(del_y,del_x)]<<endl;
                
                cout<<"------------------------------------"<<endl;
                
                cur_max=max(cur_max,slopemap[make_pair(del_y,del_x)]);
                
            }
            cout<<"------------------------------------"<<endl;
            cout<<"current max = "<<cur_max<<endl;
            cout<<"vertical point count =  "<<vertical_point<<endl;
            cur_max=max(cur_max,vertical_point);
            cout<<"Now current max = "<<cur_max<<endl;
            cout<<"------------------------------------"<<endl;
        }
        cout<<"------------------------------------"<<endl;
        cout<<"Maximum points = "<<max_point<<endl;
        cout<<"current max = "<<cur_max<<endl;
        cout<<"overlap point count = "<<overlap_point<<endl;
        
        max_point=max(max_point,cur_max +overlap_point +1);
        cout<<"MAX COLLINEAR POINT WHICH CONTAINS CURRENT POINT "<<points[i].first<<" and "<<points[i].second<<" ARE : "<<cur_max +overlap_point +1<<endl;
        cout<<"------------------------------------"<<endl;
        slopemap.clear();
    }
    cout<<endl;
    return max_point;
}

int main() {
   int n=7;
   int arr[n][2]={{-1,1},{0,0},{1,1},{2,2},{1,1},{3,3},{3,4}};
   // Pair is used to combine together two values which may be different in type.
   vector<pair<int,int>>points;
   for(int i=0;i<n;i++)
   {
       points.push_back(make_pair(arr[i][0],arr[i][1]));
   }
   cout<<endl;
   cout<<"------------------------------------"<<endl;
   cout<<max_points(points)<<" : Max Collinear points on a Line "<<endl;
   cout<<"------------------------------------"<<endl;

    return 0;
}
/* OUTPUT :
/tmp/pSwEA9HyCg.o
------------------------------------
------------------------------------
del_y : 0 - 1 = -1
del_x : 0 - -1 = 1
GCD of 1 and -1 = -1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = -1
------------------------------------
------------------------------------
current max = 0
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
del_y : 1 - 1 = 0
del_x : 1 - -1 = 2
GCD of 2 and 0 = 2
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 0
Value of del_x = 1
------------------------------------
------------------------------------
current max = 1
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
del_y : 2 - 1 = 1
del_x : 2 - -1 = 3
GCD of 3 and 1 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 3
------------------------------------
------------------------------------
current max = 1
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
del_y : 1 - 1 = 0
del_x : 1 - -1 = 2
GCD of 2 and 0 = 2
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 0
Value of del_x = 1
------------------------------------
------------------------------------
current max = 1
slopemap[make_pair(del_y,del_x)] = 2
------------------------------------
------------------------------------
current max = 2
vertical point count =  0
Now current max = 2
------------------------------------
------------------------------------
del_y : 3 - 1 = 2
del_x : 3 - -1 = 4
GCD of 4 and 2 = 2
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 2
------------------------------------
------------------------------------
current max = 2
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 2
vertical point count =  0
Now current max = 2
------------------------------------
------------------------------------
del_y : 4 - 1 = 3
del_x : 3 - -1 = 4
GCD of 4 and 3 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 3
Value of del_x = 4
------------------------------------
------------------------------------
current max = 2
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 2
vertical point count =  0
Now current max = 2
------------------------------------
------------------------------------
Maximum points = 0
current max = 2
overlap point count = 0
MAX COLLINEAR POINT WHICH CONTAINS CURRENT POINT -1 and 1 ARE : 3
------------------------------------
------------------------------------
del_y : 1 - 0 = 1
del_x : 1 - 0 = 1
GCD of 1 and 1 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 0
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
del_y : 2 - 0 = 2
del_x : 2 - 0 = 2
GCD of 2 and 2 = 2
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 1
slopemap[make_pair(del_y,del_x)] = 2
------------------------------------
------------------------------------
current max = 2
vertical point count =  0
Now current max = 2
------------------------------------
------------------------------------
del_y : 1 - 0 = 1
del_x : 1 - 0 = 1
GCD of 1 and 1 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 2
slopemap[make_pair(del_y,del_x)] = 3
------------------------------------
------------------------------------
current max = 3
vertical point count =  0
Now current max = 3
------------------------------------
------------------------------------
del_y : 3 - 0 = 3
del_x : 3 - 0 = 3
GCD of 3 and 3 = 3
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 3
slopemap[make_pair(del_y,del_x)] = 4
------------------------------------
------------------------------------
current max = 4
vertical point count =  0
Now current max = 4
------------------------------------
------------------------------------
del_y : 4 - 0 = 4
del_x : 3 - 0 = 3
GCD of 3 and 4 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 4
Value of del_x = 3
------------------------------------
------------------------------------
current max = 4
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 4
vertical point count =  0
Now current max = 4
------------------------------------
------------------------------------
Maximum points = 3
current max = 4
overlap point count = 0
MAX COLLINEAR POINT WHICH CONTAINS CURRENT POINT 0 and 0 ARE : 5
------------------------------------
------------------------------------
del_y : 2 - 1 = 1
del_x : 2 - 1 = 1
GCD of 1 and 1 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 0
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
point[i] = 1 and point[j] = 1
Overlap Point Count = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
del_y : 3 - 1 = 2
del_x : 3 - 1 = 2
GCD of 2 and 2 = 2
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 1
slopemap[make_pair(del_y,del_x)] = 2
------------------------------------
------------------------------------
current max = 2
vertical point count =  0
Now current max = 2
------------------------------------
------------------------------------
del_y : 4 - 1 = 3
del_x : 3 - 1 = 2
GCD of 2 and 3 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 3
Value of del_x = 2
------------------------------------
------------------------------------
current max = 2
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 2
vertical point count =  0
Now current max = 2
------------------------------------
------------------------------------
Maximum points = 5
current max = 2
overlap point count = 1
MAX COLLINEAR POINT WHICH CONTAINS CURRENT POINT 1 and 1 ARE : 4
------------------------------------
------------------------------------
del_y : 1 - 2 = -1
del_x : 1 - 2 = -1
GCD of -1 and -1 = -1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 0
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
del_y : 3 - 2 = 1
del_x : 3 - 2 = 1
GCD of 1 and 1 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 1
slopemap[make_pair(del_y,del_x)] = 2
------------------------------------
------------------------------------
current max = 2
vertical point count =  0
Now current max = 2
------------------------------------
------------------------------------
del_y : 4 - 2 = 2
del_x : 3 - 2 = 1
GCD of 1 and 2 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 2
Value of del_x = 1
------------------------------------
------------------------------------
current max = 2
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 2
vertical point count =  0
Now current max = 2
------------------------------------
------------------------------------
Maximum points = 5
current max = 2
overlap point count = 0
MAX COLLINEAR POINT WHICH CONTAINS CURRENT POINT 2 and 2 ARE : 3
------------------------------------
------------------------------------
del_y : 3 - 1 = 2
del_x : 3 - 1 = 2
GCD of 2 and 2 = 2
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 1
Value of del_x = 1
------------------------------------
------------------------------------
current max = 0
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
del_y : 4 - 1 = 3
del_x : 3 - 1 = 2
GCD of 2 and 3 = 1
dividing the del_y and del_x by their GCD respectively: 
Value of del_y = 3
Value of del_x = 2
------------------------------------
------------------------------------
current max = 1
slopemap[make_pair(del_y,del_x)] = 1
------------------------------------
------------------------------------
current max = 1
vertical point count =  0
Now current max = 1
------------------------------------
------------------------------------
Maximum points = 5
current max = 1
overlap point count = 0
MAX COLLINEAR POINT WHICH CONTAINS CURRENT POINT 1 and 1 ARE : 2
------------------------------------
------------------------------------
Vertical Point Count = 1
------------------------------------
------------------------------------
current max = 0
vertical point count =  1
Now current max = 1
------------------------------------
------------------------------------
Maximum points = 5
current max = 1
overlap point count = 0
MAX COLLINEAR POINT WHICH CONTAINS CURRENT POINT 3 and 3 ARE : 2
------------------------------------
------------------------------------
Maximum points = 5
current max = 0
overlap point count = 0
MAX COLLINEAR POINT WHICH CONTAINS CURRENT POINT 3 and 4 ARE : 1
------------------------------------

5 : Max Collinear points on a Line 
------------------------------------
*/

