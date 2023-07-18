class Solution
{
    public:
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
        {
            int iniColor = image[sr][sc];
            vector<vector < int>> vis(image.size(), vector<int> (image[0].size(), 0));
            vector<vector < int>> ans = image;
            vis[sr][sc] = 1;

            queue<pair<int, int>> qu;
            qu.push({ sr, sc });

            while (!qu.empty())
            {
                pair<int, int> node = qu.front();
                qu.pop();
                if (image[node.first][node.second] == iniColor)
                {
                    ans[node.first][node.second] = color;
                }

                for (int delj = -1; delj <= 1; delj++) {
                    int r = node.first;
                    int c = node.second + delj;

                    if (c >= 0 && c <= image[0].size() && image[r][c] == iniColor) {
                        if (vis[r][c] != 1) {
                            vis[r][c] = 1;
                            qu.push({ r,
                                c });
                        }
                    }
                }

                for (int deli = -1; deli <= 1; deli++) {
                    int r = node.first + deli;
                    int c = node.second;

                    if (r >= 0 && r < image.size() && image[r][c] == iniColor) {
                        if (vis[r][c] != 1) {
                            vis[r][c] = 1;
                            qu.push({r, c});
                        }
                    }
                }
            }

            return ans;
        }
};