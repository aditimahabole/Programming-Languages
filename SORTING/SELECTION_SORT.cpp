// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int *arr,int n,int end)
{   if(end ==0)
    { return;}
    for(int i=0;i<end;i++)
    {
        if(arr[i]>arr[i + 1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    bubble_sort(arr,n,end - 1);
}

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
    int arr[]={2,3,5,1,4};
    // int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // int end=n - 1;
    // bubble_sort(arr,n,end);
    // display(arr,n);
   int start=0;
    selection_sort(arr,n);
    display(arr,n);
    return 0;
}
