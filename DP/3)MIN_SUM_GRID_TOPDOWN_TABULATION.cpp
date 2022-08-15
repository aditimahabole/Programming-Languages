// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.




int minPathSum(vector<vector<int>>& grid)
    {
      
      int m=grid.size();
      int n=grid[0].size();
      // vector<vector<int>>dp(m,vector<int>(n,-1));
      // return ans(grid,m-1,n-1,dp);
      vector<vector<int>>dp(m,vector<int>(n,0));
      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
          if(i==0 && j==0)
          {
            dp[i][j]=grid[i][j];
          }
          else
          {
            int up=grid[i][j];
            if(i>0)
            {
              up+=dp[i-1][j];
            }
            else
            {
              up+=1e9;
            }
            int left=grid[i][j];
            if(j>0)
            {
              left+=dp[i][j-1];
            }
            else
            {
              left+=1e9;
            }
            dp[i][j]=min(up,left);
          }
        }
      }
      
      return dp[m-1][n-1];
      
    }
