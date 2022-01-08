//https://www.geeksforgeeks.org/remove-minimum-number-elements-no-common-element-exist-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int remove_common(int a[],int b[],int n1,int n2)
{
    unordered_set<int> op;
    for(int i=0;i<n1;i++)
    {
        op.insert(a[i]);
    }
    int count=0;
    for(int i=0;i<n2;i++)
    {
        if(op.find(b[i])!=op.end())
        {
            count++;
        }
    }
    return count;
   
}
int main() 
{
//   int a[] = { 1, 2, 3, 4};
//   int b[] = { 2, 3, 4, 5, 8 };
//   int a[] = { 4, 2, 4, 4};
//   int b[] = { 4,3};
     int a[] = { 1, 2, 3, 4 };
     int b[] = { 5, 6, 7 };
    int n1 = sizeof(a) / sizeof(int);
    int n2 = sizeof(b) / sizeof(int);
    
    cout<<remove_common(a,b,n1,n2)<<" = TOTAL COMMON REMOVED"<<endl;
    return 0;
}
