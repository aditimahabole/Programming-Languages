// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int count_subset_diff(vector<int>v,int range,int diff)
{
    //now s1- s2 = diff
    //    s1+ s2 = range
    // so 2s1=diff+range
    //s1=(diff+range)/2
    //so we have to find two subset with sum = s1
    //that is s1 ke element ka sum uske barabr hoga
    int subset1=(diff+range)/2;
    int n=v.size();
    int t[n+1][subset1+1];
    for(int i=0;i<=n;i++)
    {
        t[i][0]=1;
    }
     for(int j=1;j<=subset1;j++)
    {
        t[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=subset1;j++)
        {
            if(v[i-1]<=j)
            {
                t[i][j]=t[i-1][j-v[i-1]]+t[i-1][j];
            }
            else if(v[i-1]>j)
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][subset1];
    
}


int main()
{
  
    vector<int>nums={1,1,2,3};
    //{1,1,2}  {3} 4-3=1
    //{1,2}    {1,3} 4-3=1
    //{1,2}    {1,3} 4-3 =1 second wala 1 used
    int diff=1;
    int range =0;
    for(int i=0;i<nums.size();i++)
    {
        range+=nums[i];
    }
    cout<<"ans = "<<count_subset_diff(nums,range,diff);
    return 0;
}
