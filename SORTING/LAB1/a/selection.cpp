#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void selection_sort(int *arr,int n)
{
   int min_index; 
   for(int i=0;i<n;i++)
   {
       min_index=i;
      for(int j=i+1;j<n;j++)
      {
          if(arr[j]<arr[i])
          {
              min_index=j;
          }
      }
      swap(arr[min_index], arr[i]);
   }
    
}
void display(int arr[],int n)
{
   
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={92,312,59,10,4};
    // int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    selection_sort(arr,n);
    display(arr,n);
    return 0;
}
/* OUTPUT 
92 312 59 10 4 
4 92 10 59 312
CODE BY ADITI MAHABOLE 20103023
*/
