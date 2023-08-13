class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stck;
        vector<int> ans(nums.size(), 0);
        int n = nums.size();

        for(int i=(2*n) - 1; i>=0; i--) {
            while(!stck.empty() && nums[i%n]>=stck.top()) {
                stck.pop();
            }

            if(!stck.empty()) {
                ans[i%n] = stck.top();
            } else {
                ans[i%n] = -1;
            }

            stck.push(nums[i%n]);
        }

        return ans;
    }
};