class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp (m, vector<int>(n, 0));

      vector<int> dpI(n, 0);

      dpI[n-1] = 1;

      for(int i=m-1; i>=0; i--) {
        vector<int> dpI2(n, 0);
        for(int j=n-1; j>=0; j--) {
          if(i == m-1 && j == n-1) {
            dpI2[n-1] = 1; 
            continue;
          }
          
          int wrap = 0;

          if(i+1<m) wrap += dpI[j];
          if(j+1<n) wrap += dpI2[j+1];

          dpI2[j]  = wrap;
        }
        dpI = dpI2;
      }

      return dpI[0];
    }
};