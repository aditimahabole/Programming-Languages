// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maximum(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
int minimum(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}
int min_product(int a[],int n)
{
    if(n==1)
    {
        return a[0];
    }
    int max_neg=INT_MIN;
    int min_pos=INT_MAX;
    int count_n=0;
    int count_zero=0;
    int pro=1;
    for(int i=0;i<=n;i++)
    {
        if(a[i]==0)
        {
            count_zero++;
        }
        if(a[i]<0)
        {
            count_n++;
            max_neg=maximum(max_neg,a[i]);
        }
        if(a[i]>0)
        {
            min_pos=minimum(min_pos,a[i]);
        }
        pro=pro*a[i];
        if(count_zero==n-1 ||(count_n==0 && count_zero>0))
        {
            return 0;
        }
        if(count_n==0)
        {
            return min_pos;
        }
        if(count_n%2==0 && count_n !=0)
        {
            pro=pro/max_neg;
        }
    }
    return pro;
}


int main() {
  int arr[]={-1,0};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<min_product(arr,n-1);
  return 0;
}
