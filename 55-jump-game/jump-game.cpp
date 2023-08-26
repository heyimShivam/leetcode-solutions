class Solution {
public:
    bool solve(vector<int>& nums, int index, vector<int> &dp) {
      if(index == nums.size() -1) return true;

      if(nums[index] == 0) return false;
      if(dp[index] != -1) return dp[index];
      
      for(int i = 1; i<=nums[index]; i++) {
        if(index + i <nums.size() && solve(nums, index + i, dp)) return dp[index] = true;
      }

      return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
      vector<int> dp(nums.size(), -1);
      return solve(nums, 0, dp);
    }
};