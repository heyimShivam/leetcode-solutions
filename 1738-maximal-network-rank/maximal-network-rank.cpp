class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> rank_nodes(n, 0);
        vector<vector<bool>> connection(n, vector<bool>(n, false));

        for(auto it : roads) {
            connection[it[0]][it[1]] = true;
            connection[it[1]][it[0]] = true;

            rank_nodes[it[0]]++;
            rank_nodes[it[1]]++;
        }

        int max_rank;

        for(int i=0; i<n;i++) {
            for(int j=i+1; j<n; j++) {
                int total = rank_nodes[i] + rank_nodes[j];
                if(connection[i][j]) total--;

                max_rank = max(max_rank, total);
            }
        }

        return max_rank;
    }
};