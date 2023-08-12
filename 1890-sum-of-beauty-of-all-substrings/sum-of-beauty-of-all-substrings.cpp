class Solution {
public:
int res(unordered_map<char,int>&mp){
    int mf=-1;
    int lf=INT_MAX;
    for(auto &it:mp){
        mf=max(mf,it.second);
        if(it.second>=1){
            lf=min(lf,it.second);
        }
       
    }
     return mf-lf;
}
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                ans=ans+res(mp);
            }
        }
        return ans;
    }
};