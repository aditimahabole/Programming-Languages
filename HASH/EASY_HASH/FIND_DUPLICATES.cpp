//https://www.geeksforgeeks.org/find-duplicates-given-array-elements-not-limited-range/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void duplicates(int arr[],int n)
{
    unordered_map<int,int> momo;
    for(int i=0;i<n;i++)
    {
        momo[arr[i]]++;
    }
    
    for(auto i:momo)
    {
        if(i.second>=2)
        {
            cout<<i.first<<" has "<<i.second<<" duplicates "<<endl;
            
        }
    }
}

int main() 
{
  int n,k;
  int arr[]={2, 10,10, 100, 2, 10, 11,2,11,2};
//   int arr[] = {1, 2, 3, 4, 1, 2, 3, 4};
//   int arr[] = {1, 2, 3, 1, 4, 5,1};
//   int arr[] = {1, 2, 3, 4, 5};
//   int arr[] = {1, 2, 3, 4, 4};
   n=sizeof(arr)/sizeof(arr[0]);
   duplicates(arr,n);
   return 0;
}
/* OUTPUT : 
11 has 2 duplicates 
10 has 3 duplicates 
2 has 4 duplicates 
*/
