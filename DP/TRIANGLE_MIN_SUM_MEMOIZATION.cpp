class Solution {
public:
    int ans(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp)
    {
      if(i==n-1)
      {
        return triangle[i][j];
        // tum koi se bhi col pe ho frk nhi
        //par jese hi last row pe aagye to value return kardo
      }
      if(dp[i][j]!=-1)
      {
        return dp[i][j];
      }
      int down= triangle[i][j]+ans(i+1,j,n,triangle,dp);
      int diagonal=triangle[i][j]+ans(i+1,j+1,n,triangle,dp);
      
      return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle)
    {
      int n=triangle.size();
      vector<vector<int>>dp(n,vector<int>(n,-1));
      return ans(0,0,n,triangle,dp);
    }
};
