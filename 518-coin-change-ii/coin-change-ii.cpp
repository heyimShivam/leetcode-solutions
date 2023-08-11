class Solution {
public:
    long countWaysToMakeChangeUtil(vector<int>& arr,int ind, int T, vector<vector<long
>>& dp){

    if(ind == 0){
        return (T%arr[0]==0);
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    long notTaken = countWaysToMakeChangeUtil(arr,ind-1,T,dp);
    
    long taken = 0;
    if(arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = notTaken + taken;
}

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
vector<vector<long>> dp(n,vector<long>(amount+1,-1));
return countWaysToMakeChangeUtil(coins,n-1, amount, dp);
    }
};