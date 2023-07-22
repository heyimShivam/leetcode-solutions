class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        int cntfresh=0;
        int cnt=0;
        int vis[n][m];
        queue<pair<pair<int, int>, int>> qu;

        // to configure rotten oranges in box;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]  == 2) {
                    qu.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }

                // to check number of fresh orange;
                if(grid[i][j]==1) cntfresh++;
            }
        }

        int tm = 0;
        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};

        while(!qu.empty()) {
            int r = qu.front().first.first; 
            int c = qu.front().first.second; 
            int t = qu.front().second;

            tm = max(t, tm);
            
            qu.pop();
            
            for(int i = 0; i < 4; i++) {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1) {
                  qu.push({{nRow, nCol}, tm +1});
                  vis[nRow][nCol] = 2;

                  // no of oranges coverted to rotten
                  cnt++;
                }
            }
        }

        if(cnt!=cntfresh) return -1;

        return tm;
    }
};