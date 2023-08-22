class Solution {
public:
    bool check(int row, int col, int n, vector<string> &board) {
      int tempRow = row;
      int tempCol = col;

      while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
      }
      
      row = tempRow;
      col = tempCol;

      while(row>=0){
        if(board[row][col]=='Q') return false;
        row--;
      }

      row=tempRow;

      while(row>=0 && col<n){
        if(board[row][col]=='Q') return false;
        col++;
        row--;
      }

      return true;
    }
    void solve(int row, int n, vector<string> &board, vector<vector<string>> &ans) {
      if(row == n) {
        ans.emplace_back(board);
        return;
      }

      for(int col=0; col<n; col++) {
        if(check(row, col, n, board)) {
          board[row][col] = 'Q';

          solve(row +1, n, board, ans);

          board[row][col] = '.';
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n);
      string s(n, '.');

      for(int i =0;i< n;i++){
        board[i]=s;
      }

      solve(0, n, board, ans);

      return ans;
    }
};