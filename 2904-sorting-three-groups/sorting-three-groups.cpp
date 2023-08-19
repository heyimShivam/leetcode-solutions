class Solution {
public:
    int solve(vector<int>&nums, vector<vector<int>>&dp, int currIdx, int prevGroup)
    {
        if (currIdx == nums.size()) return 0;
        if (dp[currIdx][prevGroup] != -1) 
            return dp[currIdx][prevGroup];
        
        int currGroup = nums[currIdx];
        int minOp = INT_MAX;
        
        for (int newGroup = prevGroup; newGroup <= 3; newGroup++)  {
            int nextOp = solve(nums, dp, currIdx + 1, newGroup);

            if (newGroup != currGroup) 
                nextOp++;

            minOp = min(minOp, nextOp);
        }
        
        return dp[currIdx][prevGroup] = minOp;
    }
    int minimumOperations(vector<int>& nums) 
    {
        vector<vector<int>>dp(nums.size(), vector<int>(4, -1));
        int ans = solve(nums, dp, 0, 1);
        return ans;
    }
};