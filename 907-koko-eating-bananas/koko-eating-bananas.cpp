class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        //find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low  = 1, high = findMax(piles), mid = 0;

        int ans=-1;

        while(low<=high) {
            mid = (low+high) /2;

            long long value = 0;
            for(int i = 0; i < piles.size(); i++) {
               value += ceil(double(piles[i])/double(mid));
            }

            if(value <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};