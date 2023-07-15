class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int index = n-1; index>=0; index--) {
           for(int prevIndex= index-1; prevIndex>=-1; prevIndex--) {
               int take =INT_MIN;
               
               if(prevIndex == -1 || nums[prevIndex] < nums[index])
                  take = 1 + dp[index+1][index+1];

               dp[index][prevIndex+1] = max(dp[index+1][prevIndex+1], take);
           }
        }

        return dp[0][0];
    }
};