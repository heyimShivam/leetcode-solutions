class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s == "") return 0;

      set<char> st;

      int i=0;
      int j=0;
      int maxLen = 0;

      while(j < s.size()) {
          if(st.find(s[j]) == st.end()) {
            st.insert(s[j]);
            maxLen = maxLen > st.size() ? maxLen : st.size();
            j++;
          } else {
            st.erase(st.find(s[i]));
            i++;
          }
      }

      return maxLen;
    }
};
