class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int, int>> zeroPos;

        for(int i = 0; i < m; i++) {
            for(int j=0; j<n; j++) {
              if(matrix[i][j] == 0){
                  zeroPos.push_back({i, j});
              }
            }
        }

        for(auto it : zeroPos) {
            for(int i=0; i<n; i++) {
                matrix[it.first][i] = 0;
            }
        }

        for(auto it : zeroPos) {
            for(int i=0; i<m; i++) {
                matrix[i][it.second] = 0;
            }
        }
    }
};