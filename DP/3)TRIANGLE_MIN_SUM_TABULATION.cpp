 int minimumTotal(vector<vector<int>>& triangle)
    {
      int n=triangle.size();
      vector<vector<int>>dp(n,vector<int>(n,0));
     // return ans(0,0,n,triangle,dp);
      
      //TABULATION
      //base case
      for( int j=0;j<n;j++)
      {
        dp[n-1][j]=triangle[n-1][j];
      }
      //main part
      for(int i= n-2;i>=0;i--)
      {
        for(int j=i;j>=0;j--)
        {
          int down= triangle[i][j]+dp[i+1][j];
          int diagonal=triangle[i][j]+dp[i+1][j+1];
          
          dp[i][j]=min(down,diagonal);
        }
      }
      return dp[0][0];
      //recussion me humne shuruwat 0,0 se ki thi 
      //to y yaad rakhna hi tabulation me base case last wale ka banega 
      //and last me value 0,0 ki hi return hogi
      //aur agar recusrrion me humne n-,m-1 se shuru kiya to vo 0,0 tak jaega
      //to iska tabulation me 0,0 ka base case banega and then n-1 ,m-1 tak jaenge hum
      //and return n-1 m-1 ki value karenge 
    }
