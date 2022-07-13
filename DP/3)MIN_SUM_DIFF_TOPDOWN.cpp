// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int min_sum_diff(vector<int> nums,int range)
{
    int n=nums.size();
    bool t[n+1][range+1];
    for(int i=0;i<=n;i++)
    {
        t[i][0]=true;
    }
    for(int j=1;j<=range;j++)
    {
        t[0][j]=false;
    }
    // similar to subset sum possible or not
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=range;j++)
        {
            if(nums[i-1]<=j)
            {
                t[i][j]=t[i-1][j]||t[i-1][j-nums[i-1]] ;
            }
            else 
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    vector<int>v;
    for(int i=0;i<=(range/2)+1;i++)
    {
        if(t[n][i]==true)
        {
            v.push_back(i);
           
        }
    }
 
    int ans=INT_MAX;;
    for(int i=0;i<v.size();i++)
    {
         ans=min(ans,abs(range-(2*v[i])));
       
    }
    return ans;
}


int main() {
  
 vector<int>nums={5,5,11};
 
    int n=nums.size();
    int range =0;
    //find range kyuki usse badi value to hogi nhi aur mininum sum =0 ho sakta and max sum joho sakta vo total sum of array hoga haina 
    //iss case me range( 0,10)hogi
    //ab hume ese two subsets nikalne hai s1 and s2 
    // to agar s1 nikal lia to s2 to aahi jaega
    // ab iss Q me na hihume s1 pata that is s1 ka sum bhi nhi pata kya le aur na hi s2 ka sum kya le ki different of both sums humara min value de thike
    /*
    like kya subests ho sakte 
    s1               s2
    {}=0              {1,2,7}=10 --->10-0=0
    {1}=1              {2,7}=9   --->9-1=8
    {1,2}=3            {7}=7     --->7-3=4
    so min isme se konsa hai 4 so that will bw ans
    so we got to know ki s1 , s2 ki value 0 se total sum ke bich hi hogi thike
    
    ab hume ye bhi pata hai ki s1 ka sum jo aata to s2 ki value range - s1 hogii obvio
    aur ab hum s2-s1 karna hai aur min nikalni iski value
    so hum pehle to ek bool dp ka use karke ye pata lagenege ki kya uss range ke ander vo sum uss array ke dwara represent kiya ja sakta hai ya nhi
    
    0 1 2 3 4 5 6 7 8 9 10
    ab ye hai range 
    isme 4 sum ka subset nhi possible using 1 2 7 similarly 5 ka bhi nhi
    to hum vector banaenge usme jo sum possible hai unko store karenge
    relate it to subset sum problem 
    usme hume ek hi sum diya hua tha
    lekin isme hume range ke ander sare sum check karnee 
    
    */
    for(int i=0;i<nums.size();i++)
    {
        range+=nums[i];
    }
    cout<<"ans = "<<min_sum_diff(nums,range);
    return 0;
}
