//WITHOUT HASHING TIME COMPLEXITY = arr1_size*log(arr1_size)+arr2_size*log(arr2_size)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/
bool is_subset(int arr1[],int arr2[],int arr1_size,int arr2_size)
{
    int i1=0,i2=0;
    if(arr1_size<arr2_size)
    {
        return 0;
    }
    sort(arr1,arr1+arr1_size);
    sort(arr2,arr2+arr2_size);
    
    while(i1<arr1_size && i2<arr2_size)
    {
        if(arr1[i1]<arr2[i2])
        {
            i1++;
        }
        else if(arr1[i1]==arr2[i2])
        {
            i1++;
            i2++;
        }
        else if(arr1[i1]>arr2[i2])
        {
            return 0;
        }
    }
    if(i2<arr2_size)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main() 
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
    int arr1_size=sizeof(arr1) / sizeof(arr1[0]);
    int arr2_size=sizeof(arr2) / sizeof(arr2[0]);
    if(is_subset(arr1,arr2,arr1_size,arr2_size))
    {
        printf("arr2[] is subset of arr1[] ");
    }
    else
    {
        printf("arr2[] is not a subset of arr1[] ");
    }
    return 0;
}
