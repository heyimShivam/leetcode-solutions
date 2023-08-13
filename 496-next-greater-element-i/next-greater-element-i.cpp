class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stck;
        unordered_map<int, int> mp;

        for(int i=nums2.size()-1; i>=0; i--) {
            while(!stck.empty() && stck.top() <= nums2[i]) {
                stck.pop();
            }

            if(!stck.empty()) {
               mp[nums2[i]] = stck.top();
            } else {
                mp[nums2[i]] = -1;
            }
           
            stck.push(nums2[i]);
        }
        
        vector<int> ans;

        for(int i=0; i<nums1.size(); i++) {
           ans.emplace_back(mp[nums1[i]]);
        }

        return ans;
    }
};