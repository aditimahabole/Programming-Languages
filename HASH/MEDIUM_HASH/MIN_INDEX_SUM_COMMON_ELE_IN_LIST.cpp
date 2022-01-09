

//https://www.geeksforgeeks.org/minimum-index-sum-common-elements-two-lists/
//HERE SUM OF INDEX SHOULD BE MINIMUM JISKA KAM HUA VO PRINT HOGA 
//AGAR SAME HUA INDEX KA SUM TO VO BHI PRINT HOGA
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
void find_it(vector<string> a1,vector<string> a2)
{
    unordered_map<string,int>ma;
    vector<string> ans;
    for(int i=0 ;i < a1.size() ;i++)
    {
        ma[a1[i]]=i;
    }
    int min_sum=INT_MAX;
    for(int i=0;i<a2.size();i++)
    {
        // The map::count() is a built-in function in C++ STL which returns 1 if the element with key K is present in the map container. It returns 0 if the element with key K is not present in the container.
        //MORE ABOUT COUNT()
        //https://www.geeksforgeeks.org/map-count-function-in-c-stl/
        cout<<"--------"<<endl;
        cout<<"a2[i] = "<<a2[i]<<endl;
        cout<<"--------"<<endl;
        if(ma.count(a2[i]))
        {
            cout<<"--------------"<<endl;
            int sum=i+ma[a2[i]];
            cout<<"ma[a2[i]] : "<<ma[a2[i]]<<endl;
            cout<<"i : "<<i<<endl;
            cout<<"sum : "<<sum<<endl;
            cout<<"min_sum : "<<min_sum<<endl;
            cout<<"--------------"<<endl;
            if(sum<min_sum)
            {
                cout<<"--------------"<<endl;
                cout<<"sum = "<<sum<<endl;
                cout<<"a2[i] = "<<a2[i]<<endl;
                min_sum=sum;
                ans.clear();
                ans.push_back(a2[i]);
                cout<<"--------------"<<endl;
            }
            else if(sum==min_sum)
            {
                cout<<"--------------"<<endl;
                cout<<"sum = "<<sum<<endl;
                cout<<"min_sum = "<<min_sum<<endl;
                ans.push_back(a2[i]);
                cout<<"--------------"<<endl;
            }
        }
    }
    cout<<"---------------------------------"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------"<<endl;
}

int main()
{
vector<string> arr1;
vector<string> arr2;
//--------------------------
// arr1.push_back("GeeksforGeeks");
// arr1.push_back("Udemy");
// arr1.push_back("Coursera");
// arr1.push_back("edX");
//--------------------------
//--------------------------
arr1.push_back("GeeksforGeeks");
arr1.push_back("Udemy");
arr1.push_back("Coursera");
arr1.push_back("edX");
//--------------------------
for(int i=0;i<arr1.size();i++)
{
    cout<<arr1[i]<<"  ";
}
cout<<endl;
//----------------------------
// arr2.push_back("Codecademy");
// arr2.push_back("Udemy");
// arr2.push_back("Khan Academy");
// arr2.push_back("GeeksforGeeks");
//-----------------------------

// ----------------------------
arr2.push_back("GeeksforGeeks");
arr2.push_back("Udemy");
arr2.push_back("Khan Academy");
arr2.push_back("Udacity");
// -----------------------------

for(int i=0;i<arr2.size();i++)
{
    cout<<arr2[i]<<"  ";
}
cout<<endl;
find_it(arr1,arr2);

    return 0;
}
/* OUTPUT : 
GeeksforGeeks  Udemy  Coursera  edX  
GeeksforGeeks  Udemy  Khan Academy  Udacity  
--------
a2[i] = GeeksforGeeks
--------
--------------
ma[a2[i]] : 0
i : 0
sum : 0
min_sum : 2147483647
--------------
--------------
sum = 0
a2[i] = GeeksforGeeks
--------------
--------
a2[i] = Udemy
--------
--------------
ma[a2[i]] : 1
i : 1
sum : 2
min_sum : 0
--------------
--------
a2[i] = Khan Academy
--------
--------
a2[i] = Udacity
--------
---------------------------------
GeeksforGeeks 
---------------------------------
*/
