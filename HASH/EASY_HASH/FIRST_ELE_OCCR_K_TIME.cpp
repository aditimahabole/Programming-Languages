//https://www.geeksforgeeks.org/first-element-occurring-k-times-array/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k_time_occur(int arr[],int n,int k)
{
    unordered_map<int,int> count;
    int flag=1;
    
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
   
    for(auto i :count)
    {
       if(i.second==k)
       {
           cout<<i.first<<" occurs "<<k<<" times "<<endl;
           flag=0;
       }
       else
       {
           flag=1;
       }
    }
    
   return flag;
}
int main() 
{
//   int arr[]={4, 1, 1, 2, 2, 1, 3, 3};
//   int arr[]={1, 7, 4, 3, 4, 8, 7};
    // k=2;
  int k;
  int arr[]={4, 1, 6, 1, 6, 4};
  k=1;
  int n=sizeof(arr)/sizeof(arr[0]);
//   cout<<"Enter value of k = "<<endl;
//   cin>>k;
  if(k_time_occur(arr,n,k)==1)
  {
      cout<<"no element has frequency = "<<k<<endl;
  }
  return 0;
}
