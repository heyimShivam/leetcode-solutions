class Solution {
private:
    int profit(int index,int check, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        if(cap==0 || index == prices.size()) return 0;

        if(dp[index][check][cap]!=-1) return dp[index][check][cap];

        int profitSum = 0;
        if(check == 0)
        profitSum = max(
                        0 + profit(index+1, 0,cap, prices, dp),
                        - prices[index] + profit(index+1, 1,cap, prices, dp)
                    );
        if(check == 1)
        profitSum = max(
                       0 + profit(index+1, 1,cap, prices, dp),
                       prices[index] + profit(index+1, 0,cap - 1, prices, dp)
                    );

        return dp[index][check][cap] = profitSum;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>> 
                                            (2,vector<int>(k+1,-1)));
       return  profit(0,0, k, prices, dp);
    }
};