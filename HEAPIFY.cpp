#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void Heapify(int arr[],int n,int i)
{
    int largest = i;
    cout<<"largest : "<<largest<<endl;
    int l = 2 * i + 1;
    cout<<"left : "<<l<<" left element : "<<arr[l]<<endl;
    int r = 2 * i + 2;
    cout<<"right : "<<r<<" right element : "<<arr[r]<<endl;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
         largest = r;
    }

    if (largest != i)
    {
        cout<<arr[i]<<" swap "<<arr[largest]<<endl;
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout << "Enter size" << endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    cout<<"Original array"<<endl;
    for(int i= 0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
    for(int i= n /2 -1;i>=0 ;i--)
    {
        cout<<"current value of i :"<<i<<endl;
        Heapify(arr,n,i);
    }
    display(arr,n);

    return 0;
}
