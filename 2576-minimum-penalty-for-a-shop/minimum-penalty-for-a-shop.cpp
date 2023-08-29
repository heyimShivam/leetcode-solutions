class Solution {
    vector<vector<int>> dp;
    int ans_(int i, string& str, bool status)
    {
        if(i == str.size())
            return 0;
        if(dp[i][status] != -1)
            return dp[i][status];
        int penal = 0;
        if(status && str[i] == 'N')
            penal++;
        else if(!status && str[i] == 'Y')
            penal++;
        return dp[i][status] = min(ans_(i + 1, str, status) + penal, ans_(i + 1, str, false) + penal);
    }
public:
    int bestClosingTime(string customers) {
        dp = vector<vector<int>>(customers.size() + 1, vector<int>(2, -1));
        int min_penal = min(ans_(0, customers, true), ans_(0, customers, false));
        int defc = 0, i = 0, p = 0;
        for(auto it: customers)
        {
            if(it == 'Y')
                defc++;
        }
        while(i < customers.size())
        {
            if(defc + p == min_penal)
                break;
            if(customers[i] == 'Y')
                defc--;
            else
                p++;
            i++;
        }
        return i;
    }
};