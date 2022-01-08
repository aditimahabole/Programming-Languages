//https://www.geeksforgeeks.org/minimum-number-subsets-distinct-elements/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int assend_count(pair<int,int>a,pair<int,int>b)
{
    return a.second>b.second;
}
int min_subset(int a[],int n)
{
    unordered_map<int,int> op;
    for(int i=0;i<n;i++)
    {
        op[a[i]]++;
    }
    cout<<"-----------------------------"<<endl;
    cout<<"key"<<"  "<<"value"<<endl;
    cout<<"-----------------------------"<<endl;
    for(auto i:op)
    {
        cout<<i.first<<" | "<<i.second<<endl;
    }
    cout<<"-----------------------------"<<endl;
    vector<pair<int,int>>v(op.begin(),op.end());
    sort(v.begin(),v.end(),assend_count);
    
    return v[0].second;
   
}
int main() 
{
    int a[] = { 5, 6, 9, 3, 4, 3, 4 };
    // int a[] = {30, 10, 9, 3, 35};
    int n = sizeof(a) / sizeof(int);
    cout<<min_subset(a,n)<<" = TOTAL SUBSET"<<endl;
    return 0;
}

/* OUTPUT : 
-----------------------------
key  value
-----------------------------
4 | 2
3 | 2
9 | 1
6 | 1
5 | 1
-----------------------------
2 = TOTAL SUBSET
*/
