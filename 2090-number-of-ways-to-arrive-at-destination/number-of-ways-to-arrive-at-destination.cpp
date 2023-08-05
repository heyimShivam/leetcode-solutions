class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : roads)
        {
            int from = it[0];
            int to = it[1];
            int time = it[2];
            adj[from].push_back({to, time});
            adj[to].push_back({from, time});
        }
        long long mod = 1e9 + 7;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        vector<long long> dist(n, 1e15);
        vector<long long> count(n, 0);
        dist[0] = 0;
        count[0] = 1;
        while(pq.size())
        {
            long long timetaken = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            for(auto it : adj[curr])
            {
                int neigh = it.first;
                int traveltime = it.second;
                if(dist[neigh] == timetaken + traveltime)
                {
                    count[neigh] = (count[neigh] + count[curr]) % mod;
                }
                else if(dist[neigh] > timetaken + traveltime)
                {
                    dist[neigh] = timetaken + traveltime;
                    pq.push({dist[neigh], neigh});
                    count[neigh] = count[curr];
                }
            }
        }
        return count[n-1] % mod;
    }
};