class Solution {
private:
    bool check(vector<int> &nums, int mid,int threshold) {
      int sum = 0;
      for(auto num : nums) {
         sum += ceil((double)num/(double)mid);
      }

      if(sum <= threshold) return true;
      return false;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            int mid= (low+high) / 2;

            if(check(nums, mid, threshold)) {
               high = mid - 1;
            } else  low  = mid + 1;
        }

        return low;
    }
};