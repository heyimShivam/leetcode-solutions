class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if(numRows > 0) ans.emplace_back(vector<int>(1, 1));
        else return ans;

        for(int i = 1; i < numRows; i++) {
            vector<int> temp;
            for(int j = 0; j <= i; j++) {
               if(j-1 < 0) temp.emplace_back(1);
               else if(j == i) temp.emplace_back(1);
               else {
                temp.emplace_back(ans[i-1][j]  + ans[i-1][j-1]);
               }
            }
            ans.emplace_back(temp);
        }

        return ans;
    }
};