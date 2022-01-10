//https://www.geeksforgeeks.org/convert-an-array-to-reduced-form-set-1-simple-and-hashing/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void convert_arr(int *arr,int n)
{
    int temp[n];
    memcpy(temp,arr,n*sizeof(int));
    sort(temp,temp+n);
    unordered_map<int,int>mo;
    int val=0;
    for(int i=0;i<n;i++)
    {
        mo[temp[i]]=val++;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=mo[arr[i]];
    }
    
}
void print(int arr[],int n)
{
    cout<<"___________________________"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"___________________________"<<endl;

}
int main()
{
   int arr[] = {10, 20, 15, 12, 11, 50};
   int n = sizeof(arr)/sizeof(arr[0]);
   print(arr,n);
   convert_arr(arr,n);
   print(arr,n);
   return 0;
}
/*
OUTPUT
___________________________
10 20 15 12 11 50 
___________________________
___________________________
0 4 3 2 1 5 
___________________________
*/
