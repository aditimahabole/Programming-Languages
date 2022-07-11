// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int  fun(int *arr,int sum,int n,int **t)
{
     
    if(n==0 && sum==0)
    {
        t[n][sum]=1;
        return t[n][sum];
    }
    if(n>0 && sum==0)
    {
        t[n][sum]=1;
        return t[n][sum];
    }
     if(n==0 && sum>0)
    {
        t[n][sum]=0;
        return t[n][sum];
    }
  /////////YE NICHE WALA CONDITION HUMESHA BASE CONDITION KE BAAD HI AATA HAI YAAD RAKHNA
    if(t[n][sum]!=-1)
    {
        return t[n][sum];
    }
   
    
   
    else if(arr[n]<=sum)
    {
        t[n][sum]= max(fun(arr,sum-arr[n], n-1,t),fun(arr,sum,n-1,t));
        return t[n][sum];
    }
    else if(arr[n]>sum)
    {
        t[n][sum]=fun(arr,sum,n-1,t);
        return t[n][sum];
    }
    return -2;

}

int main() {
   int n = 4;
int arr[] = {1,2,3,5};
int sum =7 ;
/////declare table for memoization
int **t=new int*[n];
for(int i=0;i<n;i++)
{
    t[i]=new int[sum+1];
    //we are creating cols for each row 
    //col size is equal to sum +1
    //because only sum and n are changing in recursion
}
for (int i = 0; i <n; i++)
       { 
           for (int j = 0; j<sum+1; j++)
           {
             t[i][j] = -1;
             //initializing to -1
           }
           
       }

cout<<fun(arr,sum,n-1,t)<<endl;

for (int i = 0; i <n; i++)
       { 
           for (int j = 0; j<sum+1; j++)
           {
             cout<<t[i][j] <<"  ";
             //initializing to -1
           }
           cout<<endl;
           
       }

    return 0;
}
