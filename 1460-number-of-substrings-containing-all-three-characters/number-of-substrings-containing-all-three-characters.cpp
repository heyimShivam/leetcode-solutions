class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0,count=0, ans =0;

        while(j<s.size()) {
            if(mp[s[j]] == 0) count++;
            mp[s[j]]++;
 
            while(i<=j && count==3) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) count--;
                i++;
                ans+=s.size() - j;
            }
            
            j++;
        }

        return ans;
    }
};