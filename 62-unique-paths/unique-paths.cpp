class Solution {
public:
    int solve(int indexI,int indexJ, int m, int n, vector<vector<int>> &dp) {
        if(indexI == m-1 && indexJ == n-1) return 1;

        if(dp[indexI][indexJ] != -1) return dp[indexI][indexJ];

        int ways = 0;
        if(indexI+1 < m)
          ways += solve(indexI+1, indexJ, m, n, dp);

        if(indexJ+1 < n)
          ways += solve(indexI, indexJ + 1, m, n, dp);

        return dp[indexI][indexJ] = ways;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int>(n, -1));

        return solve(0, 0, m, n, dp);
    }
};