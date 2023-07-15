class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(2,-1);
        dp[0] = dp[1] =0;

        for(int index = n-1; index>=0; index--) {
            vector<int> cur(2,-1);
            for(int check= 0; check<=1; check++) {
                 long profitSum = 0;
                  if(check == 0)
                  profitSum = max(
                                  0 + dp[0],
                                  - prices[index] + dp[1]
                              );
                  if(check == 1)
                  profitSum = max(
                                 0 + dp[1],
                                 prices[index] - fee + dp[0]
                              );

                  cur[check] = (int)profitSum;
            }
            dp = cur;
        }

        return dp[0];
    }
};