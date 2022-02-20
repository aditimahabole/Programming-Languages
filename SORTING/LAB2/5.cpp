//time complexity is coming out infinity
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
void fun(int *arr,int s,int n)
{
    int m;
    cout<<"--------------------"<<endl;
    cout<<"start = "<<s<<endl;
    cout<<"end   = "<<n<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" , ";
    }
    cout<<endl;
    cout<<"--------------------"<<endl;
    if(n==2 && arr[0]>arr[1])
    {
        cout<<"inside if condition "<<endl;
        swap(arr[0],arr[1]);
    }
    else if(n>2)
    {
        cout<<"inside else condition "<<endl;
        m=floor((2*n)/3);
        // m=ceil((2*n)/3);
        cout<<"m = "<<m<<endl;
    }
    cout<<"_____________________"<<endl;
    cout<<" first function called"<<endl;
    cout<<"_____________________"<<endl;
    fun(arr,0,m - 1);
     cout<<"_____________________"<<endl;
    cout<<" second function called"<<endl;
    cout<<"_____________________"<<endl;
    fun(arr,m-n,n-1);
     cout<<"_____________________"<<endl;
    cout<<" third function called"<<endl;
    cout<<"_____________________"<<endl;
    fun(arr,0,m - 1);
    
}
int main() 
{
    int n=6;
    int arr[n]={1,2,3,4,5,6};
    fun(arr,0,n - 1);
    return 0;
}
