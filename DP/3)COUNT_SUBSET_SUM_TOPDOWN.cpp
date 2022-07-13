// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int count_subset(vector<int> nums,int n,int sum)
{

int t[n+1][sum+1];
for(int i=0;i<=n;i++)
{
    t[i][0]=1;
}
/*
   0 1 2
 0 1 0 0------------------>0
 1 1
 2 1
 JAB SUM 0 HAI AUR N KITNE BHI HO TO FRK KYA PADHTA HUM EK NULL SUBSET BHI TO BANA SAKTE KYUKI USKA SUM TO 0 HAI SO THAT WHY T[N][0]=1
*/
  
for(int j=1;j<=sum;j++)
{
    t[0][j]=0;
}
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=sum;j++)
    {
        if(nums[i-1]<=j)
        {
            t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
        }
        else 
        {
             t[i][j]=t[i-1][j];
        }
    }
}
return t[n][sum];

}

int main()
{
    vector<int>nums={2,3,5,6,8,10};
    int sum=10;
    int n=nums.size();
    cout<<count_subset(nums,n,sum);
 

    return 0;
}
