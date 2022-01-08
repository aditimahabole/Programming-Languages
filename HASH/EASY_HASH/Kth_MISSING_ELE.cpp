//https://www.geeksforgeeks.org/k-th-missing-element-increasing-sequence-not-present-given-sequence/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kth_missing_element(int a[],int b[],int n1,int n2,int k)
{
    unordered_set<int> pro;
    vector<int> v;
    for(int i=0;i<n2;i++)
    {
        pro.insert(b[i]);
    }
    for(int i=0;i<n1;i++)
    {
        if(pro.find(a[i])==pro.end())
        {
            v.push_back(a[i]);
        }
    }
    
    return v[k - 1];
   
}
int main() 
{
    int a[] = {0, 2, 4, 6, 8, 10, 12, 14, 15};
    int b[] = {4, 10, 6, 8, 12};
    int n1 = sizeof(a) / sizeof(int);
    int n2 = sizeof(b) / sizeof(int);
    int k=3;
    cout<<kth_missing_element(a,b,n1,n2,k);
  
    return 0;
}
//OUTPUT 14
