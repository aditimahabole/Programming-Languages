//https://www.geeksforgeeks.org/smallest-subarray-with-all-occurrences-of-a-most-frequent-element/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void sub_array(int arr[],int n)
{
    unordered_map<int,int> count;
    unordered_map<int,int> posi;
    unordered_map<int,int> last;
    for(int i=0;i<n;i++)
    {
        if(posi.find(arr[i])==posi.end())
        {
            posi[arr[i]]=i;
        }
        last[arr[i]]=i;
        count[arr[i]]++;
    }
    int max_fre=0;
    int max=0;
    for(auto i :count)
    {
        if(i.second>max)
        {
            max=i.second;
            max_fre=i.first;
        }
    }
    cout<<endl;
    cout<<"Max Element : "<<max_fre<<" and its frequency : "<<count[max_fre]<<endl;
    
    for(int i=posi[max_fre];i!=last[max_fre]+ 1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() 
{
//   int arr[]={4, 1, 1, 2, 2, 1, 3, 3};
  int arr[]={1, 2, 2, 3, 1};
  int n=sizeof(arr)/sizeof(arr[0]);
  sub_array(arr,n);
  return 0;
}
/* OUTPUT : 
Max Element : 2 and its frequency : 2
2 2 
*/
