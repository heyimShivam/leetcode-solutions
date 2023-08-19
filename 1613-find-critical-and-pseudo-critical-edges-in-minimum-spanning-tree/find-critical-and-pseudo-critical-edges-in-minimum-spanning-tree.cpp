class DSU {
    class Node {
        public:
            int parent;
            int rank = 0;
    };
    vector<Node> parent;
    public:
        DSU(int n) {
            parent = vector<Node>(n);

            for (int i = 0; i < n; i++) {
                parent[i].parent = i;
            }
        }

        int find(int x) {
            if (parent[x].parent == x) return x;

            return parent[x].parent = find(parent[x].parent);
        }

        void Union(int x, int y) {
            int xParent = find(x);
            int yParent = find(y);

            if (xParent == yParent) return;

            if (parent[xParent].rank > parent[yParent].rank) {
                parent[yParent].parent = xParent;
            } else if (parent[xParent].rank == parent[yParent].rank) {
                parent[yParent].parent = xParent;
                parent[xParent].rank++;
            } else {
                parent[xParent].parent = yParent;
            }
        }

        void reset() {
            for (int i = 0; i < parent.size(); i++) {
                parent[i].parent = i;
                parent[i].rank = 0;
            }
        }
};


bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), cmp);

        DSU dsu(n);
        int stdweight = 0;
        for (auto edge: edges) {
            if (dsu.find(edge[0]) == dsu.find(edge[1])) continue;
            stdweight += edge[2];
            dsu.Union(edge[0], edge[1]);
        }

        // cout << stdweight << endl;

        vector<vector<int>> results(2, vector<int>());

        for (int i = 0; i < edges.size(); i++) {
            dsu.reset();
            int newWeight = 0;
            for (auto edge: edges) {
                // skip
                if (edge[3] == edges[i][3]) {
                    continue;
                };
                if (dsu.find(edge[0]) == dsu.find(edge[1])) continue;
                newWeight += edge[2];
                dsu.Union(edge[0], edge[1]);
            }

            if (newWeight != stdweight) {
                results[0].push_back(edges[i][3]);
                continue;
            }

            dsu.reset();
            dsu.Union(edges[i][0], edges[i][1]);
            newWeight = edges[i][2];
            for (auto edge: edges) {
                if (dsu.find(edge[0]) == dsu.find(edge[1])) continue;
                newWeight += edge[2];
                dsu.Union(edge[0], edge[1]);
            }

            if (newWeight == stdweight) results[1].push_back(edges[i][3]);
        }

        return results;
    }
};