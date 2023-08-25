class Solution {
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>>&dp) {
        if(i+j == s3.size()) return true;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i] == s3[i+j]) {
            if(solve(i+1, j, s1, s2, s3, dp)) return dp[i][j] = true;
        }

        if(s2[j] == s3[i+j]) {
            if(solve(i, j+1, s1, s2, s3, dp)) return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};