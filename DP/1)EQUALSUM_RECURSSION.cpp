// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& arr,int n,int sum) 
{
    if(n==0 && sum==0)
    {
        return true;
    }
    if(n==0 && sum>0)
    {
        return false;
    }
    if(n>0 && sum==0)
    {
        return true;
    }
    
    if(arr[n]<=sum)
    {
        return (canPartition(arr,n-1,sum-arr[n]) || canPartition(arr,n-1,sum));
    }
    else
    {
        return canPartition(arr,n-1,sum);
    }

}

int main() {
   
   vector<int>arr={5,5,2,11};
   int total=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            total+=arr[i];
        }
        if(total%2)
        {
            cout<<"false"<<endl;
        }
        else
        {
            int sum=total/2;
            cout<<canPartition(arr,n,sum) ;
        }
 
    return 0;
}
