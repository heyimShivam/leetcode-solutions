class Solution {
public:
    int solve(vector<int> &nums, int index, int count, vector<vector<int>> &dp) {
        if(index == nums.size()) return count;

        if(dp[index][count] != -1) return dp[index][count];

        int count1 = INT_MAX, cnt2= INT_MAX, cnt3= INT_MAX, simple = INT_MAX;

        if(index == 0 || nums[index -1] <= nums[index]) {
            simple = solve(nums, index + 1, count, dp);
        }
        
        int temp = nums[index];

        if(nums[index] != 1 && (index == 0 || nums[index-1] <=1 )) {
            nums[index] = 1;
            count1 = solve(nums, index + 1, count +1, dp);
            nums[index] = temp;
        }

        if(nums[index] != 2 && (index == 0 || nums[index-1] <=2 )) {
            cout<<"index is 1:";
            nums[index] = 2;
            cnt2 = solve(nums, index + 1, count +1, dp);
            nums[index] = temp;
        }

        if(nums[index] != 3 && (index == 0 || nums[index-1] <=3 )) {
            nums[index] = 3;
            cnt3 = solve(nums, index + 1, count +1, dp);
            nums[index] = temp;
        }

        return min(cnt3, min(cnt2, min(simple, count1)));
    }
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, 0, 0, dp);
    }
};