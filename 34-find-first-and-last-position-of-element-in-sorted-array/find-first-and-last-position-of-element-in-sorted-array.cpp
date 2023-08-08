class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator lb = lower_bound(nums.begin(), nums.end(), target);
        vector<int>::iterator ub = upper_bound(nums.begin(), nums.end(), target);
       
        if(lb< ub) return {int(lb - nums.begin()), int(--ub - nums.begin())};
        return {-1, -1}; 
    }
};