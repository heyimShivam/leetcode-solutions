class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto it: nums) {
            st.insert(it);
        }

        int candidate=*(st.begin()), len = 0, maxLen = 0;
        cout<<candidate<< " "<<st.size();
        for(auto it: st) {
            if(candidate == it) {
               len++;
               candidate++;
               maxLen = max(maxLen, len);
            } else {
                len = 1;
                candidate = it +1;
            }
        }

        return maxLen;
    }
};