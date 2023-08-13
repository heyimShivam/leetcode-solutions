class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stck;
        unordered_map<int, int> mp;

        for(int i=nums2.size()-1; i>=0; i--) {
            if(!stck.empty() && nums2[i]<stck.top()) {
                mp[nums2[i]] = stck.top();
                stck.push(nums2[i]);
            } else {
                while(!stck.empty()) {
                    if(nums2[i] > stck.top()) {
                        stck.pop();
                    } else if (nums2[i] < stck.top()) {
                        mp[nums2[i]] = stck.top();
                        stck.push(nums2[i]);
                        break;
                    }
                }
                if(stck.empty()) {
                   mp[nums2[i]] = -1;
                   stck.push(nums2[i]);
                }
            }
        }
        
        vector<int> ans;

        for(int i=0; i<nums1.size(); i++) {
           ans.emplace_back(mp[nums1[i]]);
        }

        return ans;
    }
};