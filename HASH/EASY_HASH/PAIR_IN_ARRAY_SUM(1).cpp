//https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
//TWO POINTER METHOD USED FOR THIS FIRST SORT ARRAY THEN TAKE END AND BEGIN POINTER
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,X;
    cout<<"ENTER SIZE : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"ENETER ELEMENTS : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"YOUR ARRAY : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    cout<<"ENTER NUMBER : "<<endl;
    cin>>X;
    cout<<endl;
    sort(arr,arr+n);
    int b=0;
    int e=n-1;
    while(b<e)
    {
        if(arr[b]+arr[e]==X)
        {
            cout<<"pair "<<arr[b]<<" and "<<arr[e]<<" exists"<<endl;
            e--;
            b++;
        }
        else if(arr[b]+arr[e]>X)
        {
            e--;
        }
        else if(arr[b]+arr[e]<X)
        {
            b++;
        }
        
    }
    
    return 0;
}
/* OUTPUT : 
ENTER SIZE : 
6
ENETER ELEMENTS : 
1
4
45
6
10
-8
YOUR ARRAY : 
1  4  45  6  10  -8  
ENTER NUMBER : 
16
pair 6 and 10 exists
*/
