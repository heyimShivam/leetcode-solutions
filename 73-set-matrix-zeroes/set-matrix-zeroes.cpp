class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        set<int> v1, v2;

        for(int i = 0; i < m; i++) {
            for(int j=0; j < n; j++) {
              if(matrix[i][j] == 0){
                  v1.insert(i);
                  v2.insert(j);
              }
            }
        }


        for(int i = 0; i < m; i++) {
            for(int j=0; j < n; j++) {
              if(v1.count(i) || v2.count(j)){
                matrix[i][j] = 0;
              }
            }
        }
    }
};