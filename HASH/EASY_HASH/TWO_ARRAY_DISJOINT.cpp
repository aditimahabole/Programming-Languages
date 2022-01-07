//https://www.geeksforgeeks.org/check-two-given-sets-disjoint/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int disjoint_or_not(int a[],int b[],int n1,int n2)
{
    unordered_map<int,int> counts;
    
    for(int i=0;i<n1;i++)
    {
        counts[a[i]]++;
    }
    for(int j=0;j<n2;j++)
    {
        counts[b[j]]++;
        if(counts[b[j]] == 2)
        {
            return 0;
        }
    }
   return 1;
}

int main()
{
    int arr1[] = {12, 34, 11, 9, 3};
    int arr2[] = {2, 1, 3, 5};

    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    if(disjoint_or_not(arr1,arr2,n1,n2))
    {
        cout<<"disjoint"<<endl;
    }
    else
    {
        cout<<"not disjoint"<<endl;
    }

    return 0;
}
// OUTPUT : not disjoint
