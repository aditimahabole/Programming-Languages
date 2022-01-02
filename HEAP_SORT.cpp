#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/////////////////DISPLAY FUNCTION////////////////////////
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
//////////////////HEAPIFY FUNCTION////////////////////////
void Heapify(int arr[],int n,int i)
{
    int largest = i;
    cout<<"largest = i : "<<largest<<" and value of arr[largest] : "<<arr[largest]<<endl;
    int l = 2 * i + 1;
    cout<<"left INDEX  : "<<l<<" left element : "<<arr[l]<<endl;
    int r = 2 * i + 2;
    cout<<"right INDEX : "<<r<<" right element : "<<arr[r]<<endl;
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
        cout<<endl;
        cout<<"current array looks like :" <<endl;
        display(arr,n);
        cout<<endl;
        Heapify(arr, n, largest);
    }
}
/////////////HEAP SORT FUNCTION/////////
void heap_sort(int arr[],int n)
{
    for(int i= n-1;i>0;i--)
    {
        cout<<endl;
        cout<<"size of array : i :"<<i<<endl;
        cout<<"value of arr[0] : "<<arr[0]<<" and value of arr[i] =arr[ n-1] : "<<arr[i]<<endl;
        swap(arr[0],arr[i]);
        cout<<arr[0]<<" and "<<arr[i]<<" are swapped "<<endl;
        Heapify(arr, i ,0);
    }
}

int main()
{
    /*TAKE n = 5  and elements 4,10,3,5,1 (just an example )*/
    int n;
    cout << "Enter size" << endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    cout<<"ORIGINAL ARRAY : "<<endl;
    for(int i= 0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
    cout<<"FIRST ARRAY IS HEAPIFIED  : "<<endl;
    for(int i= n /2 -1;i>=0 ;i--)
    {
        cout<<"CURRENT VALUE  of i (i = n/2-1) :"<<i<<endl;
        Heapify(arr,n,i);
    }
    cout<<endl;
    cout<<"AFTER HEAPIFY : "<<endl;
    display(arr,n);
    cout<<endl;
    cout<<"HEAP SORT CALLED : "<<endl;
    heap_sort(arr,n);
    cout<<endl;
    cout<<"AFTER HEAP SORTED  : "<<endl;
    display(arr,n);

    return 0;
}
