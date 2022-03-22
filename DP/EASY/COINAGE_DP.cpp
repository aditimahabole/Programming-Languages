#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kam_paisa(int arr[],int n,int rupee,int *dp)
{
    if(rupee==0)
    {
        cout<<"returned"<<endl;
        return 0;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(rupee-arr[i]>=0)
        {
            int sub_ans=0;
            if(dp[rupee-arr[i]]!=-1)
            {
                cout<<endl;
                cout<<"first if called"<<endl;
                sub_ans=dp[rupee-arr[i]];
            }
            else
            {
                cout<<"else called"<<endl;
                cout<<rupee-arr[i]<<endl;
             sub_ans=kam_paisa(arr,n,rupee-arr[i],dp);
            }
          
            if(sub_ans!=INT_MAX && sub_ans+1<ans)
            {
                cout<<"second if called"<<endl;
                
                ans=sub_ans+1;
                cout<<"ans = "<<ans<<endl;
              //basically yaha count kar rhe hai hum
            }
        }
    }
    cout<<rupee<<" --> "<<ans<<endl;
    return dp[rupee]=ans;
}
int main() {
    int arr[]={7,5,1};
    int rupee=18;
    int dp[rupee + 1];
    for(int i=0;i<rupee+1;i++)
    {
        dp[i]=-1;
    }
    dp[0]=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<kam_paisa(arr,n,rupee,dp)<<endl;
    for(int i=0;i<rupee+1;i++)
    {
        cout<<"For "<<i<<" coins we need "<<dp[i]<<endl;
    }
    return 0;
}
