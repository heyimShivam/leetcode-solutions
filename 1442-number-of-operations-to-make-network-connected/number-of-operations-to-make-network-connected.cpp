class Solution {
public:
    class Disjoint{
        public:
        vector<int> rank;
        vector<int> parent;

        public:
        Disjoint(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
           
            for(int i = 0; i < n+1; i++) {
               parent[i] = i;
            }
        }

        int findUPar(int node) {
            if(node == parent[node]) return node;

            return  parent[node] = findUPar(parent[node]);
        }

        int unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
 
            if (ulp_u == ulp_v) return 1;

            if(rank[ulp_u] < rank[ulp_v]) {
               parent[ulp_u] = ulp_v;
            } else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }

            return 0;
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
       Disjoint disJoint(n);
       
       int extraEdge = 0;

        for(int i=0; i<connections.size(); i++) {
           extraEdge += disJoint.unionByRank(connections[i][0], connections[i][1]);
        }

        int numbersCont = 0;
        for(int i=0; i<n ;i++) {
            if(disJoint.parent[i] == i) numbersCont++;
        }
        
        if(extraEdge >= numbersCont - 1) return numbersCont - 1;
        
        return -1;
    }
};