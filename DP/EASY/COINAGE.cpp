// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kam_paisa(int arr[],int n,int rupee)
{
    if(rupee==0)
    {
        return 0;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(rupee-arr[i]>=0)
        {
            
            int sub_ans=kam_paisa(arr,n,rupee-arr[i]);
          
            if(sub_ans!=INT_MAX && sub_ans+1<ans)
            {
                ans=sub_ans+1;
              //basically yaha count kar rhe hai hum
            }
        }
    }
    return ans;
}
int main() {
    int arr[]={7,5,1};
    int rupee=18;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<kam_paisa(arr,n,rupee);
    return 0;
}
