class Solution {
private:
    int profit(int index,int check,int fee, vector<int> &prices, vector<vector<int>> &dp) {
        if(index == prices.size()) return 0;

        if(dp[index][check]!=-1) return dp[index][check];

        long profitSum = 0;
        if(check == 0)
        profitSum = max(
                        0 + profit(index+1, 0,fee, prices, dp),
                        - prices[index] + profit(index+1, 1,fee, prices, dp)
                    );
        if(check == 1)
        profitSum = max(
                       0 + profit(index+1, 1,fee, prices, dp),
                       prices[index] - fee + profit(index+1, 0,fee, prices, dp)
                    );

        return dp[index][check] = (int)profitSum;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        if(n==0) return 0;
       return  profit(0,0,fee, prices, dp);
    }
};