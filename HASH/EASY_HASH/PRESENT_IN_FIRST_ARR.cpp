// https://www.geeksforgeeks.org/find-elements-present-first-array-not-second/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void present_in_first_arr(int a[],int b[],int n1,int n2)
{
    unordered_set<int> s;
    
    
    
    for(int i=0;i<n2;i++)
    {
        s.insert(b[i]);
    }
    for(int i=0;i<n1;i++)
    {
        if(s.find(a[i])==s.end())
        {
            cout<<a[i]<<" ";
        }
    }
   
   
}
int main()
{
    int arr1[] = {1, 5, 3, 8};
    int arr2[] = {5, 4, 6, 7};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    present_in_first_arr(arr1,arr2,n1,n2);
    return 0;
}
//OUTPUT :1 3 8
