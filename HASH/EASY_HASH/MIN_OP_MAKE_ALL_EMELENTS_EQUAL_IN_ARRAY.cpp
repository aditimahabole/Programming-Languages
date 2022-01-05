//https://www.geeksforgeeks.org/minimum-operation-make-elements-equal-array/
//SAME AS MIN_DELETE_ARRAY.cpp QUESTION IN MY REPO 
#include <bits/stdc++.h>
using namespace std;
int min_operation(int arr[],int n)
{
    unordered_map<int,int> hash;
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    int max_count=0;
    for(auto i:hash)
    {
        if(max_count<i.second)
        {
            max_count=i.second;        }
    }
    
    return n-max_count;//this will be the min deleltion to make array same type
}

int main()
{
    int n,sum;
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
    cout<<"Minimum number of Deletions are = "<<min_operation(arr,n)<<endl;
    
    
    return 0;
}
