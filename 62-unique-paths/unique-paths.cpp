class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp (m, vector<int>(n, 0));

      dp[m-1][n-1] = 1;

      for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
          if(i == m-1 && j == n-1) continue;
          
          int wrap = 0;

          if(i+1<m) wrap += dp[i+1][j];
          if(j+1<n) wrap += dp[i][j+1];

          dp[i][j]  = wrap;
        }
      }

      return dp[0][0];
    }
};