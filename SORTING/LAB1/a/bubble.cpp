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


void display(int arr[],int n)
{
   
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={299,3267,51,1,49,876,23};
    // int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int end=n - 1;
     bubble_sort(arr,n,end);
     display(arr,n);
    return 0;
}
/* OUTPUT 

299 3267 51 1 49 876 23 
1 23 49 51 299 876 3267 
CODE BY ADITI MAHABOLE 20103023
*/
