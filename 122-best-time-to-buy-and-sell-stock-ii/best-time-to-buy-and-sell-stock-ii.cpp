class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(2,-1));
        dp[n][0] = dp[n][1] =0;

        for(int index = n-1; index>=0; index--) {
            for(int check= 0; check<=1; check++) {
                 long profitSum = 0;
                  if(check == 0)
                  profitSum = max(
                                  0 + dp[index+1][0],
                                  - prices[index] + dp[index+1][1]
                              );
                  if(check == 1)
                  profitSum = max(
                                 0 + dp[index+1][1],
                                 prices[index] + dp[index+1][0]
                              );

                  dp[index][check] = (int)profitSum;
            }
        }

        return dp[0][0];
    }
};