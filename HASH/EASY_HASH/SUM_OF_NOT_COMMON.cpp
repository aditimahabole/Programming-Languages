//https://www.geeksforgeeks.org/overlapping-sum-two-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sum_of_not_common(int a[],int b[],int n1,int n2)
{
    unordered_map<int,int> counts;
    int sum=0;
    
    for(int i=0;i<n1;i++)
    {
        counts[a[i]]++;
    }
    for(int j=0;j<n2;j++)
    {
        counts[b[j]]++;
    }
    for(auto i:counts)
    {
        if(i.second ==1)
        {
            sum=sum+i.first;
        }
    }
   return sum;
}
int main()
{
    int arr1[] = {1, 5, 3, 8};
    int arr2[] = {5, 4, 6, 7};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    cout<<"SUM IS = "<<sum_of_not_common(arr1,arr2,n1,n2);
    return 0;
}
//OUTPUT : SUM IS = 29
