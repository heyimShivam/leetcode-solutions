class Solution {
public:
    double solve(int indexRow, int indexCol, int n, int moves, vector<vector<vector<double>>> &dp) {
        if(indexRow<0 || indexRow>=n || indexCol<0 || indexCol>=n) return 0;
        if(dp[indexRow][indexCol][moves] != -1) return dp[indexRow][indexCol][moves];
        if(moves == 0) return 1;
        
        double chanceSum = 0;

        chanceSum += solve(indexRow - 2, indexCol-1, n, moves -1 ,dp );
        chanceSum += solve(indexRow - 2, indexCol+1, n, moves -1 ,dp );
        chanceSum +=solve(indexRow + 2, indexCol-1, n, moves -1 ,dp );
        chanceSum += solve(indexRow + 2, indexCol+1, n, moves -1 ,dp );
        chanceSum += solve(indexRow - 1, indexCol-2, n, moves -1 ,dp );
        chanceSum += solve(indexRow +1, indexCol-2, n, moves -1 ,dp ); 
        chanceSum += solve(indexRow -1, indexCol+2, n, moves -1 ,dp ); 
        chanceSum += solve(indexRow + 1, indexCol+2, n, moves -1 ,dp );

        return dp[indexRow][indexCol][moves] = chanceSum/8;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(
            n+1, vector<vector<double>>(
                n+1, vector<double>(
                    k+1,
                    -1)
            )
        );

        return solve(row, column, n, k, dp);
    }
};