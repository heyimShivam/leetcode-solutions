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
              cout<<s[j];
              j++;
            } else {
              st.erase(st.find(s[i]));
              i++;
            }

          maxLen= maxLen > st.size() ? maxLen : st.size();
        }

        return maxLen;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//       unordered_map<char, int> mp;
//       int len = 0;
//       if(s == "") {return 0;}
//       for(int i=0; i< s.length(); i++) {
//         if(mp.find(s[i]) != mp.end()) {
//           mp[s[i]] = i;
//           int temp = s.length()-1-i;
//           len = max(len, temp);
//           // mp.insert({s[i], i});
//         } else {
//           mp.insert({s[i], i});
//         }
//       }
//         return len;
//     }
// };