class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
       
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<char>> result(n, vector<char>(m, 'X'));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j] == 'O') {
                    result[i][j] = 'O';
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        while( !q.empty() ) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                    result[nrow][ncol]='O';
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        board = result;
    }
};