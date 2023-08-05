class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       //  directed Node = first in pair;
       //  time = sec in pair;
       vector<pair<int, int>> adj[n + 1];

        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({ times[i][1], times[i][2] });
        }

        vector<int> dist(n+1, 1e9);
        
        // because node is starting from 1 to n;
        dist[0] = 0;

        dist[k] = 0;

        // first = time;
        // sec = node;
        queue<pair<int, int>> st;

        st.push({0, k});

        while(!st.empty()) {
           int curtime = (st.front()).first;
           int curNode = (st.front()).second;
    
           st.pop();
           
           for(auto it : adj[curNode]) {
               int timeToNode = it.second;
               int nextNode = it.first;
           
               if(curtime + timeToNode < dist[nextNode] ) {
                  dist[nextNode] = curtime + timeToNode;
                  st.push({dist[nextNode], nextNode});
               }
           }
        }

        int minTime=-1;

        for(auto it: dist) {
            if(minTime<it) {
                minTime = it;
            }
        }

        if(minTime >= 1e9) return -1;
        return minTime;
    }
};