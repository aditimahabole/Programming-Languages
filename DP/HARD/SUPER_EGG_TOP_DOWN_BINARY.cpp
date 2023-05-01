class Solution {
public:
    // int dp(int eggs, int floors,vector<vector<int>>&memo)
    // {
    //     if(memo[eggs][floors] != -1) return memo[eggs][floors];
    //     if(eggs == 1) return floors;
    //     if(floors == 0 || floors == 1) return floors;
    //     int mini = floors;
    //     int ith_floor;
    //     int worst_case ;
    //     for(ith_floor = 1;ith_floor<=floors;ith_floor++)
    //     {
    //         int egg_broke = dp(eggs-1,ith_floor-1,memo);
    //         int egg_safe = dp(eggs, floors- ith_floor,memo);
    //         worst_case = max(egg_broke,egg_safe);
    //         if(worst_case<mini) mini = worst_case;
    //     }
    //     memo[eggs][floors] = mini + 1;
    //     return mini + 1;
    // }

    int superEggDrop(int k, int n) {
        // ----------Memoization----------------
        // vector<vector<int>>memo(k+1,vector<int>(n+1,-1));
        // int ans = dp(k,n,memo);
        // return ans;
        // ------------Top Down------------------
        int eggs = k;
        int floors = n;
        int dp[eggs+1][floors+1];
        int worst_case;
        int i,j,floor;
        for(i=1;i<=eggs;i++)
        {
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        for(j=1;j<=floors;j++) dp[1][j] = j;
        for(i = 2;i<= eggs;i++)
        {
            for(j=2;j<=floors;j++)
            {
                int low = 1;
                int high = j;
                int mini = INT_MAX;
                while(low<=high)
                {
                    int mid = (high+low)/2;
                    int egg_broke = dp[i-1][mid-1];
                    int egg_safe = dp[i][j-mid];
                    worst_case = max(egg_broke,egg_safe);
                    if(egg_broke<egg_safe) low = mid+1;
                    else high = mid-1;
                    mini = min(mini,worst_case);
                }
                dp[i][j] = mini + 1; // +1 for egg dropped already
            }
        }
        return dp[eggs][floors];
        
    }
};
