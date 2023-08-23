class Solution {
private:
    void solve(
      int col,
      int n,
      vector<string>& board,
      vector<vector<string>>& ans,
      vector<int> &lowDiagonal,
      vector<int> &upperDiagonal,
      vector<int> &rowCheck
    ) {
       if(col>=n){
           ans.emplace_back(board);
           return;
       }

       for(int row =0; row<n; row++){
         if(rowCheck[row] == 0 && upperDiagonal[row+col] == 0 && lowDiagonal[(n-1 + (col-row))] == 0){
             board[row][col]='Q';
             rowCheck[row] = 1;
             upperDiagonal[row+col] = 1;
             lowDiagonal[(n-1 + (col-row))] = 1;
               solve(col+1, n, board, ans, lowDiagonal, upperDiagonal, rowCheck);
             board[row][col]='.';
             rowCheck[row] = 0;
             upperDiagonal[row+col] = 0;
             lowDiagonal[(n-1 + (col-row))] = 0;
         }
       }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i =0;i< n;i++){
            board[i]=s;
        }
        
        vector<int> lowDiagonal((2 * n - 1), 0);
        vector<int> upperDiagonal((2 * n - 1), 0);
        vector<int> row(n, 0);

        solve(0, n, board, ans, lowDiagonal, upperDiagonal, row);

        return ans;
    }
};