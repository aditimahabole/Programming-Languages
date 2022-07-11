// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int canPartition(vector<int>& arr,int n,int sum,int **t) 
{
    if(n==0 && sum==0)
    {
        t[n][sum]=1;
        return t[n][sum];
    }
    if(n==0 && sum>0)
    {
        t[n][sum]=0;
        return t[n][sum];
    }
    if(n>0 && sum==0)
    {
        t[n][sum]=1;
        return t[n][sum];
    }
    if(t[n][sum]!=-1)
    {
         return t[n][sum];
    }
    
    if(arr[n]<=sum)
    {
        t[n][sum]=max(canPartition(arr,n-1,sum-arr[n],t), canPartition(arr,n-1,sum,t));
         return t[n][sum];
    }
    if(arr[n]>sum)
    {
       t[n][sum]=canPartition(arr,n-1,sum,t);
       return t[n][sum];
    }
return -1;
}

int main() {
   
   vector<int>arr={3,3,3,4,5};
   int total=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            total+=arr[i];
        }
        if(total%2)
        {
            cout<<"0"<<endl;
        }
        else
        {
            int sum=total/2;
            int **t;
            t=new int*[n];
            for(int i=0;i<n;i++)
            {
                t[i]=new int[sum+1];
            }
            
    for (int i = 0; i <n; i++)
       { 
           for (int j = 0; j <=sum; j++)
           {
             t[i][j] = -1;
             //initializing to -1
           }
           
       }
          
            cout<<canPartition(arr,n-1,sum,t) ;
        }
 
    return 0;
}
