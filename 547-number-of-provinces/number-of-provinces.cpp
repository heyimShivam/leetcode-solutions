class Solution {
private: 
    void dfs(int node, vector<int> adj[], vector<int> &vistedArray) {
        vistedArray[node] = 1; 

        for(auto it : adj[node]) {
            if(!vistedArray[it]) dfs(it, adj, vistedArray);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        vector<int> adj[isConnected.size()];
        vector<int> vistedArray(isConnected.size(), 0);

        // to change matrix to list
        for(int i=0; i< isConnected.size(); i++) {
            for(int j=0; j<isConnected[i].size(); j++) {
                if(isConnected[i][j] == 1 && i!=j) {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }

        for(int i=0; i < vistedArray.size(); i++) {
            if(vistedArray[i] != 1) {
               dfs(i, adj, vistedArray);
               count++;
            }
        }

        return count;
    }
};