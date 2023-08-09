class Solution {
private:
    bool check(vector<int> &weights, int days, int maxWeight) {
       int load =0, day=1;
       for(int  i=0; i< weights.size(); i++) {
           if(load + weights[i] <= maxWeight) {
               load += weights[i];
           } else {
               day++;
               load = weights[i];
           }
       }

       if(day <= days) return true;
       return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(high >= low) {
            int mid = (high + low) / 2;

            if(check(weights, days, mid)) {
               high = mid - 1;
            } else {
               low = mid + 1;
            }
        }

        return low;
    }
};