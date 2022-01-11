//https://www.geeksforgeeks.org/smallest-element-repeated-exactly-k-times-not-limited-small-range/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int small_k_time(int arr[],int n,int k)
{
    unordered_map<int,int>count;
    unordered_map<int,int>posi;
    for(int i=0;i<n;i++)
    {
        if(posi.find(arr[i])==posi.end())
        {
            posi[arr[i]]=i;
        }
        count[arr[i]]++;
        
    }
    int pos=n-1;
 for(auto i:count)
 {
     if(i.second==k)
     {
         if(posi[i.first]<pos)
         {
             pos=posi[i.first];
         }
     }
 }
    
   return arr[pos];
}


int main()
{
 
    // int arr[]={3, 4, 3, 2, 1, 5, 5};
    // int k=2;
    int arr[]={2, 1, 3, 1, 2, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    cout<<small_k_time(arr,n,k);
    return 0;
}
