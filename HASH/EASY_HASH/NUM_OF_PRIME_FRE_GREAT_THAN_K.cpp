//https://www.geeksforgeeks.org/numbers-prime-frequencies-greater-equal-k/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    int p=1;
    if(n==1)
    {
        p=0;
        return p;
    }
    if(n==2 || n==3)
    {
        return p;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            p=0;
            break;
        }
    }
    return p;
}
void prime_fre(int arr[],int n,int k)
{
    unordered_map<int,int>count;
    for(int i=0;i<n;i++)
    {
       count[arr[i]]++;
    }
    int c=0;
 for(auto i:count)
 {
     if(is_prime(i.second)&& i.second>k)
     {
        cout<<i.first<<" ";
        
     }
     c=i.second;
 }
 if(c==1)
 {
     cout<<"-1";
 }
}


int main()
{
 
    // int arr[]={3, 4, 3, 2, 1, 5, 5};
    // int k=2;
    // int arr[]={11,11,11,23,11,37,51,37,37,51,51,51,51};
    int arr[]={ 11, 22, 33,33};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    prime_fre(arr,n,k);
    return 0;
}
