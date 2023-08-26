class Solution {
public:
    bool dfs(vector<int>& arr, int index, vector<int> &vis) {
      if(index < 0 || index >= arr.size()) {
        return false;
      }

      if(vis[index] == 1) return false;
      vis[index] = 1;

      if(arr[index] == 0) return true;

      if(dfs(arr, index + arr[index], vis)) return true;

      if(dfs(arr, index - arr[index], vis)) return true;

      return false;
    }
    bool canReach(vector<int>& arr, int start) {
      vector<int> vis(arr.size() + 1, -1);
      return dfs(arr, start, vis);
    }
};