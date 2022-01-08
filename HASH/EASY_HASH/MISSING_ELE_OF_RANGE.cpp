
//https://www.geeksforgeeks.org/find-missing-elements-of-a-range/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> missing_element(int arr[],int n,int low,int high)
{
    unordered_set<int> pro;
    vector<int> yo;
    for(int i=0;i<n;i++)
    {
        pro.insert(arr[i]);
    }
    int i=low;
    
    while(i>=low && i<high)
    {
        
        if(pro.find(i)==pro.end())
        {
            yo.push_back(i);
        }
        i++;
        
    }
    return yo;
}
int main() 
{
    // int arr[] = {10, 12, 11, 15};
    int arr[] = {1, 14, 11, 51, 15};
    int n = sizeof(arr) / sizeof(int);
    // int low=10;
    // int high=15;
    int low=50;
    int high=55;
    vector<int> yo1=missing_element(arr,n,low,high);
    for(int j=0;j<yo1.size();j++)
    {
        cout<<yo1[j]<<" , ";
    }
    return 0;
}
//OUTPUT 50 , 52 , 53 , 54 , 
