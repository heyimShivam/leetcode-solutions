class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        
        for(auto it : nums) {
            mp[it]++;
        }

        for(auto it : mp) {
            if(it.second > 1) {
                ans += (it.second * ( it.second-1 )) / 2;
            }
        }

        return ans;
    }
};