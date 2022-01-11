//https://www.geeksforgeeks.org/pairs-of-positive-negative-values-in-an-array/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sor(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;
}

void pair_posneg(int arr[],int n)
{
    unordered_set<int>present;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
       if(present.find(-arr[i])!=present.end())
       {
           v.push_back(make_pair(arr[i],-arr[i]));
       }
       present.insert(arr[i]);
    }
    sort(v.begin(),v.end(),sor);
    for(int i=0;i<v.size();i++)
    {
        cout<<"("<<v[i].first<<","<<v[i].second<<")"<<endl;
    }
    


}
int main()
{
    // int arr[]={ 1, -3, 2, 3, 6, -1 };
    int arr[]={ 4, 8, 9, -4, 1, -1, -8, -9 };
    int n=sizeof(arr)/sizeof(arr[0]);

    pair_posneg(arr,n);
    return 0;
}
/*OUTPUT:
(-1,1)
(-4,4)
(-8,8)
(-9,9)
*/


