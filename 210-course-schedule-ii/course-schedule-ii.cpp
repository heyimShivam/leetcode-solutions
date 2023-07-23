class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjoint[numCourses];

        for(auto it : prerequisites) {
            adjoint[it[0]].push_back(it[1]);
        }

        vector<int> indgree(numCourses, 0);

        for(int i=0; i<numCourses; i++) {
            for(auto it: adjoint[i]) {
                indgree[it]++;
            }
        }

        queue<int> q;

        for(int i=0 ;i<numCourses; i++) {
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
        reverse(topo.begin(), topo.end());
        if(topo.size() == numCourses) return topo;
        return {};
    }
};