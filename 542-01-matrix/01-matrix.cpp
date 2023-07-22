class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
       
        queue<pair<pair<int, int>, int>> qu;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> result(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (mat[i][j]==0){
                    result[i][j]=0;
                    vis[i][j]=1;
                    qu.push({{i,j}, 0});
                }
            }
        }
 
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        while( !qu.empty() ) {
            int r = qu.front().first.first;
            int c = qu.front().first.second;
            int steps = qu.front().second;
            
            steps++;
            
            qu.pop();

            for(int i=0; i<4; i++) {
                int row = r + delRow[i];
                int col = c + delCol[i];

                if(row>=0 && col>=0 && row<n && col<m && vis[row][col] == 0 && mat[row][col] == 1) {
                   vis[row][col] = 1;
                   result[row][col] = steps;
                   qu.push({{row, col}, steps});
                }
            }
        }

        return result;
    }
};