class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int n = nums.size(), count = 0, i = 0, j = 0, sum = 0;
        while(j < n){
            sum += nums[j];
            while(i <= j && sum > goal)
                sum -= nums[i++];
            count += j - i + 1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal) - helper(nums,goal - 1);
    }
};