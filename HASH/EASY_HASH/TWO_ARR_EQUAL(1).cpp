
//https://www.geeksforgeeks.org/check-if-two-arrays-are-equal-or-not/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool arr_equal(int arr1[],int arr2[],int n1,int n2)
{
    if(n1!=n2)
    {
        return false;
    }
    unordered_set<int>count;
    for(int i=0;i<n1;i++)
    {
        count.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++)
    {
        if(count.find(arr2[i])==count.end())
        {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = { 3, 5, 2, 5, 2 };
    int arr2[] = { 2, 3, 5, 5, 2 };
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    if(arr_equal(arr1,arr2,n1,n2))
    {
        cout<<"EQUAL"<<endl;
    }
    else
    {
        cout<<"NOT EQUAL"<<endl;
    }
    return 0;
}
// OUTPUT : EQUAL
