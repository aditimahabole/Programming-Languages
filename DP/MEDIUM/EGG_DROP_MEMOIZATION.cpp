// PROBLEM STATEMENT : https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // vector<vector<int> > memo(250, vector<int>(250, -1));
    //Function to find minimum number of attempts needed in 
    int dp(int n,int k,vector<vector<int> > &memo)
    {
        //n = eggs , k = floors 
        // ----------------------------------------
        if(k == 0 || k == 1) return k;
        // ----------------------------------------
        if(n==1) return k; 
        // agar ek hi anda diya to lowest to highest fekar dekhna padega
        //and worst case top floor pe tutega yahi hoga haina
        // to kth floor tak jana padega yaani k attempts to return kiya k
        // ----------------------------------------
        if (memo[n][k] != -1) return memo[n][k];
        
        int mini = INT_MAX;
        int i;
        int res;

        for(i=1;i<=k;i++)
        {
            res = max(dp(n-1,i-1,memo),dp(n,k-i,memo));
            
            // agar break hua to matlabho sakta ki aur niche jao kya pata vo bhi break ho
            //and hume mil jaye necche jate jate vo floor jaha se safe hai
            
            // ya fir agar break nhi hua  to matlab upar jao waha se pata lagane ki 
            //konse floor pe break ho rha
            
            // to hume worst case dekhna hai jab break ho rha hai and jab break nhi ho rha
            // to max lo uskaa and result me store kar diya
            if(res<mini) mini = res;
            
        }
        memo[n][k] = mini + 1;
        return mini+1;
        // ----------------------------------------
        
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int> > memo(250, vector<int>(250, -1));
        int ans = dp(n,k,memo);
        return ans;
        
    }
};
/*
LEET CODE EGG = 2 
// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/description/
class Solution {
public:
    int dp(int egg, int floor,vector<vector<int>>&memo)
    {
        if(memo[egg][floor]!=-1) return memo[egg][floor];
        if(egg == 1) return floor;
        if(floor == 0 || floor == 1) return floor;
        int mini=INT_MAX;
        int ith_floor;
        int res;
        for(ith_floor=1;ith_floor<=floor;ith_floor++)
        {
            int egg_broke = dp(egg-1,ith_floor-1,memo);
            int egg_safe = dp(egg,floor - ith_floor,memo);
            res = max(egg_broke,egg_safe);
            if(res<mini) mini = res;
        }
        memo[egg][floor] = mini+1;
        return memo[egg][floor];

    }
    int twoEggDrop(int n) {
        //eggs = 2 given
        vector<vector<int>>memo(3,vector<int>(10001,-1));
        int ans = dp(2,n,memo);
        return ans;
        
    }
};



*/
//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
