
// https://www.geeksforgeeks.org/frequent-element-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int most_frequent(int arr[],int n)
{
    unordered_map<int,int> dora;
   for(int i=0;i<n;i++)
   {
       dora[arr[i]]++;
   }
   
   int max=0;
   int max_ele=dora[0];
   for(auto i:dora)
   {
       if(i.second>max)
       {
           max=i.second;
           max_ele=i.first;
       }
   }
   return max_ele;
}

int main() 
{
  int n,k;
  int arr[] ={1, 3, 2, 1, 4, 1};
   n=sizeof(arr)/sizeof(arr[0]);
   cout<<"YOUR ARRAY : "<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   cout<<most_frequent(arr,n)<<" = is most frequent"<<endl;
   return 0;
}
/* OUTPUT: 
YOUR ARRAY : 
1 3 2 1 4 1 
1 = is most frequent
*/
