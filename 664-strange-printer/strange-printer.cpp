class Solution {
public:
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 1 + solve(s, i + 1, j, dp);
        for (int k = i + 1; k <= j; k++) {
            if (s[k] == s[i]) {
                ans = min(ans, solve(s, i, k - 1, dp) + solve(s, k + 1, j, dp));
            }
        }
        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};