// https://www.geeksforgeeks.org/pair-with-given-product-set-1-find-if-any-pair-exists/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool product(int arr[],int n,int k)
{
    unordered_set<int> pro;
    for(int i=0;i<n;i++)
    {
        pro.insert(arr[i]);
        if(pro.find(k/arr[i])!=pro.end())
        {
            return true;
        }
    }
  
    return false;
}
int main() 
{
    int arr[] = {10, 20, 9, 40};
    int k=400;
    int n = sizeof(arr) / sizeof(int);
    if(product(arr,n,k))
    {
        cout<<"yes"<<endl;
    }
    else 
    {
        cout<<"no"<<endl;
    }
    return 0;
}
//OUTPUT : yes
