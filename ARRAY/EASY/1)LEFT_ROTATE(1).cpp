//https://www.geeksforgeeks.org/array-rotation/
//Time complexity : O(n * d) 
// Auxiliary Space : O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void left_rotate_by_one(int arr[],int n)
{
    int temp=arr[0];
    int i;
    for(i=0;i<n-1;i++)
    {
        arr[i]=arr[i + 1];
    }
    arr[n-1]=temp;
}
void left_rotate(int arr[],int n,int k )
{
    for(int i=0;i<k;i++)
    {
        left_rotate_by_one(arr,n);
    }
}
void display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main() {
  
  int arr[]={1,2,3,4,5,6,7};
  int n=sizeof(arr)/sizeof(arr[0]);
  left_rotate(arr,n,2);
  display(arr,n);

    return 0;
}
//3 4 5 6 7 1 2 
