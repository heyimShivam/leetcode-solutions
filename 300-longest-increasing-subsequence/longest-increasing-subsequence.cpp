class Solution {
private: 
    int solveIncreaing(int index, int prevIndex, int &n, vector<int> &nums, vector<vector<int>> &dp) {
        if(index == n) return 0;

        if(dp[index][prevIndex+1]!=-1)
          return dp[index][prevIndex+1];

        int take=INT_MIN, notTake;

        // not take
        notTake = solveIncreaing(index+1, prevIndex, n, nums, dp);

        // take
        if(prevIndex == -1 || nums[prevIndex] < nums[index])
          take = 1 + solveIncreaing(index+1, index, n, nums, dp);

        return dp[index][prevIndex+1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solveIncreaing(0, -1, n, nums, dp);
    }
};