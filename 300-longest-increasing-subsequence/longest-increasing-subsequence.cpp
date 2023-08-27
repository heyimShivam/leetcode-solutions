class Solution {
public:
    int solve(int index, int prevIndex, int n, vector<int> &nums, vector<vector<int>> &dp) {
        if(index == n) return 0;

        int take = INT_MIN, notTake = INT_MIN;

        if(dp[index + 1][prevIndex + 1] != -1) return dp[index + 1][prevIndex + 1];

        notTake = solve(index + 1, prevIndex, n, nums, dp);

        if(prevIndex == -1 || nums[prevIndex] < nums[index]) 
          take = 1 + solve(index+1, index, n, nums, dp);

        return dp[index + 1][prevIndex + 1] = max(notTake, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return solve(0, -1, n, nums, dp);
    }
};
