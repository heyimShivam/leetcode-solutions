class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> absoluteDifference(
            heights.size(), vector<int>(heights[0].size(), 1e9)
        );

        absoluteDifference[0][0] = 0;

        queue<pair<int, pair<int, int>>> st;

        st.push({0, {0, 0}});

        int maxValue;
        while(!st.empty()) {
            int prevDist = (st.front()).first;
            int row = (st.front()).second.first;
            int col = (st.front()).second.second;
            st.pop();

            int delRow[] = {0, 0, 1, -1};
            int delCol[] = {1, -1, 0, 0};

            for(int i = 0; i < 4; i++) {
                if(row+delRow[i] >= 0 && row+delRow[i] < heights.size() &&
                   col+delCol[i] >=0 && col+delCol[i] < heights[0].size()) {
                       int differecState = max(abs(heights[row+delRow[i]][col+delCol[i]] - heights[row][col]), prevDist);
                       if(differecState < absoluteDifference[row+delRow[i]][col+delCol[i]]) {
                           if(absoluteDifference[row+delRow[i]][col+delCol[i]] != 1e9) {
                              maxValue = absoluteDifference[row+delRow[i]][col+delCol[i]];
                           }

                           absoluteDifference[row+delRow[i]][col+delCol[i]] = differecState;

                           st.push({
                               differecState, {row+delRow[i], col+delCol[i]}
                           });
                       }

                }
            }
        }
 
        return absoluteDifference[heights.size()-1][heights[0].size()-1];
    }
};