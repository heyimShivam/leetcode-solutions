class Solution {
private:
    void backtrack(int n, int k, int start, vector<int>& temp, vector<vector<int>>& result) {
        if(temp.size() == k) {
            result.emplace_back(temp);
        }

        for(int i = start; i<=n; i++) {
            temp.emplace_back(i);

            backtrack(n, k, i + 1, temp, result);
            
            temp.pop_back();
        }

    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;

        backtrack(n, k, 1, temp, result);
        
        return result;
    }
};