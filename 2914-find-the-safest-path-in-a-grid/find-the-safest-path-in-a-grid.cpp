class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        //for bfs push coordinate of all thief into queue

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // BFS
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<pair<int, int>> mv = {
                {1, 0},
                {0, 1},
                {-1, 0},
                {0, -1}};

            for (auto m : mv)
            {
                int i = x + m.first;
                int j = y + m.second;
                if (i < 0 || j < 0 || i >= n || j >= n || dist[i][j] <= dist[x][y] + 1)
                    continue;
                q.push({i, j});
                dist[i][j] = 1 + dist[x][y];
            }
        }
        //Dijktra
        priority_queue<pair<int, pair<int, int>>> pq;
        vis.assign(n, vector<bool>(n, false));
        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = true;

        while (!pq.empty())
        {
            int val = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            vector<pair<int, int>> mv = {
                {1, 0},
                {0, 1},
                {-1, 0},
                {0, -1}};

            for (auto m : mv)
            {
                int i = x + m.first;
                int j = y + m.second;
                if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == true)
                    continue;

                vis[i][j] = true;
                dist[i][j] = min(dist[i][j], dist[x][y]);
                pq.push({dist[i][j], {i, j}});
            }
        }
        return dist[n - 1][n - 1];
    }
};