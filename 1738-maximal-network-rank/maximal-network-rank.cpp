class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank=INT_MIN;
        vector<int> adjList[n];

        for(auto it : roads) {
            adjList[it[0]].emplace_back(it[1]);
            adjList[it[1]].emplace_back(it[0]);
        }

        for(int i=0; i<n;i++){
            for(int j=i+1; j<n; j++){
                int rank_i = adjList[i].size();
                int rank_j = adjList[j].size();

                int total_rank = rank_i + rank_j;

                if(find(adjList[i].begin(), adjList[i].end(), j) != adjList[i].end())    total_rank--;

                maxRank = max(total_rank, maxRank);
            }
        }

        return maxRank;
    }
};