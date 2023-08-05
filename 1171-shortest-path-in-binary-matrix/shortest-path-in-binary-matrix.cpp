class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        vector<vector<int>> distance(
            grid.size(), vector<int>(grid[0].size(), 1e9)
        );

        distance[0][0] = 0;

        queue<pair<int, pair<int, int>>> st;

        st.push({0, {0, 0}});

        while(!st.empty()) {
            int prevDist = (st.front()).first;
            int row = (st.front()).second.first;
            int col = (st.front()).second.second;
            st.pop();

            int delRow[] = {0, 0, 1, -1, 1, -1, -1, 1};
            int delCol[] = {1, -1, 0, 0, 1, -1, 1, -1};

            for(int i = 0; i < 8; i++) {
                if(row+delRow[i] >= 0 && row+delRow[i] < grid.size() &&
                   col+delCol[i] >=0 && col+delCol[i] < grid[0].size() &&
                   grid[row+delRow[i]][col+delCol[i]] == 0) {

                       if(prevDist + 1 < distance[row+delRow[i]][col+delCol[i]]) {
                        //    if(distance[row+delRow[i]][col+delCol[i]] != 1e9) {
                        //        st.erase({distance[row+delRow[i]][col+delCol[i]] ,{row+delRow[i], col+delCol[i]}});
                        //    }
                           
                           distance[row+delRow[i]][col+delCol[i]] = prevDist +1;

                           st.push({
                               prevDist +1, {row+delRow[i], col+delCol[i]}
                           });
                       }

                }
            }
        }
 
        if(distance[grid.size()-1][grid[0].size()-1] >= 1e9) return -1;
        return distance[grid.size()-1][grid[0].size()-1] + 1;
    }
};