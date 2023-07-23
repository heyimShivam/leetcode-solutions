class Solution {
public:
    bool isBipartite(vector<vector<int>>& adjList) {
        int n = adjList.size();

        vector<int> vis(n, -1);
        queue<pair<int, int>> q;

        bool flag = true; 

        for(int i=0; i<n; i++) {
            if(flag == false) break;

            if(vis[i] == -1) {
               q.push({i, 0});
               vis[i] = 0;
            }

            while( !q.empty() ) {
            int node = q.front().first;
            int prevColor = q.front().second;

            q.pop();

            for(auto adj : adjList[node]) {
                    int newColor = !prevColor;
    
                    if(vis[adj] == -1) {
                        q.push({adj, newColor});
                        vis[adj] = newColor;
                    } else if(vis[adj] != -1) {
                        if(newColor != vis[adj]) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }

        return flag;
    }
};