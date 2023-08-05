class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        vector<vector<int>> distance(
            grid.size(), vector<int>(grid[0].size(), 1e9)
        );

        distance[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> st;

        st.push({0, {0, 0}});

        while(!st.empty()) {
            int prevDist = (st.top()).first;
            int row = (st.top()).second.first;
            int col = (st.top()).second.second;
            st.pop();

            int delRow[] = {0, 0, 1, -1};
            int delCol[] = {1, -1, 0, 0};

            for(int i = 0; i < 4; i++) {
                if(row+delRow[i] >= 0 && row+delRow[i] < grid.size() &&
                   col+delCol[i] >=0 && col+delCol[i] < grid[0].size()) {
                       int newEfforts = (max(
                           abs(grid[row][col] - grid[row+delRow[i]][col+delCol[i]]),
                           prevDist
                       ));

                       if(newEfforts < distance[row+delRow[i]][col+delCol[i]]) {
                           distance[row+delRow[i]][col+delCol[i]] = newEfforts;

                           st.push({
                               newEfforts, {row+delRow[i], col+delCol[i]}
                           });
                       }

                }
            }
        }
 
        return distance[grid.size()-1][grid[0].size()-1];
    }
};