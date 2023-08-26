class Solution {
public:
    static bool cpm(vector<int> a, vector<int> b) {
       if(a[1] < b[1]) return true;

       return false;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cpm);
        
        int prev = 0, res = 1;

        for(int i=1; i < pairs.size(); i++) {
          if(pairs[prev][1] < pairs[i][0]) {
            prev =i;
            res++;
          }
        }

        return res;
    }
};