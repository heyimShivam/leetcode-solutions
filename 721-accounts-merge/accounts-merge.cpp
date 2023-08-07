class DisJoint{
  public:
  vector<int> rank, parent;

  DisJoint(int n) {
      rank.resize(n +1, 0);
      parent.resize(n+1);

      for(int i = 0 ; i < n; i++){
          parent[i] = i;
      }
  }

  int findParent(int node) {
      if(node == parent[node]) return node;

      return parent[ node ] = findParent(parent[node]);
  }

  void unionRank(int u, int v) {
      int prt_u = findParent(u);
      int prt_v = findParent(v);

      if(prt_u == prt_v) return;

      if(rank[prt_u] < rank[prt_v]) {
          parent[prt_u] = prt_v;
      } else if(rank[prt_v] < rank[prt_u]) {
          parent[prt_v] = prt_u;
      } else {
          parent[prt_v] = prt_u;
          rank[prt_u]++;
      }
  }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJoint ds(n);
        unordered_map<string,int> mapMailNode;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
               string mail = accounts[i][j];

               if(mapMailNode.find(mail) == mapMailNode.end()) {
                   mapMailNode[mail] = i;
               } else {
                   ds.unionRank(i, mapMailNode[mail]);
               }
            }
        }

        vector<string> mergeMail[n];

        for(auto it: mapMailNode) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0; i< n;i++) {
            if(mergeMail[i].size()==0) continue;

            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string> temp;
            temp.emplace_back(accounts[i][0]);

            for(auto it : mergeMail[i]) {
                temp.emplace_back(it);
            }
            ans.emplace_back(temp);
        }

        return ans;
    }
};