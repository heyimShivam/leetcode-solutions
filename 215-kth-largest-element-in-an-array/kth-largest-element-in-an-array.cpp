class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int, greater<int>> st;
        
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }
       
        auto it = next(st.begin(), k-1);

        return *it;
    }
};