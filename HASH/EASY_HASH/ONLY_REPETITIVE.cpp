//https://www.geeksforgeeks.org/find-repetitive-element-1-n-1/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int only_repetetive(int arr[],int n)
{
    unordered_map<int,int>count;
    
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
        if(count[arr[i]]>=2)
        {
            return arr[i];
        }
    }
    return -1;
}
int main() 
{
  int arr[] = {1, 5, 1, 2, 3, 4};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"repetetive element = "<<only_repetetive(arr,n);
  return 0;
}
/*
OUTPUT : 
repetetive element = 1
*/
