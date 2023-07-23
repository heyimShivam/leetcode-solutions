class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> adjoint[n];

        for(int i = 0; i < n; i++) {
            for(auto it: graph[i]) {
                adjoint[it].push_back(i);
            }
        }

        vector<int> indgree(n, 0);

        for(int i=0; i<n; i++) {
            for(auto it: adjoint[i]) {
                indgree[it]++;
            }
        }

        queue<int> q;

        for(int i=0 ;i<n; i++) {
            if(indgree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while( !q.empty() ) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adjoint[node]) {
                indgree[it]--;
                if(indgree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(topo.begin(), topo.end());
        
        return topo;
    }
};