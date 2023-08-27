class Solution {
public:
    int n;
    vector<vector<int>> dp;
        bool f(vector<int>& stones, int i, int k){
        if (i==n-1) return 1;
        if (i>=n) return 0;
        if (dp[i][k]!=-1) return dp[i][k];
        
        bool ans=0;
        
        for(int jump: {k-1, k, k+1}){
            if (jump==0) continue;
            
            int next=lower_bound(stones.begin()+(i+1), stones.end(), stones[i]+jump)
                -stones.begin();
            if (next==n || stones[next]!=stones[i]+jump) continue; // not found
            ans=ans||f(stones, next, jump);
        }
        return dp[i][k]=ans;
    }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return f(stones, 0, 0); 
    }
};