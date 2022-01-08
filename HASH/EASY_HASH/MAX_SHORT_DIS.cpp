
// https://www.geeksforgeeks.org/print-maximum-shortest-distance/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sum_short_end(int arr[],int n,int k)
{
    unordered_map<int,int> lo;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        int d=min(i+1,n-i);
        if(lo.find(x)==lo.end())
        {
            lo[x]=d;
        }
        else
        {
            //if duplicate fount then chck for min dis from ends
            lo[x]=min(d,lo[x]);
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        if(x!=k-x &&lo.find(k-x)!=lo.end())
        {
            ans=min(max(lo[x],lo[k - x]),ans);
        }
    }
    return ans;
}
int main() 
{
    int arr[] = {2, 4, 3, 2, 1};
    int k=5;
    int n = sizeof(arr) / sizeof(int);
    cout<<sum_short_end(arr,n,k)<<endl;
    return 0;
}

