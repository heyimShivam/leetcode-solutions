class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(auto it: arr) {
            if(it<=k) {
                k++;
            } else {
                break;
            }
        }

        return k;
    }
};