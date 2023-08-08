class Solution {
public:
    int findMin(vector<int>& nums) {
       int low =0, high = nums.size() - 1, mid =0;

        int minmum = INT_MAX;
        while(high >= low) {
            mid = low + (high-low)/2;

            // if(nums[low]< nums[high]) {
            //   minmum = min(minmum, nums[low]);
            //   break;
            // }

            if(nums[low] <= nums[mid]) {
                // left sorted
                minmum = min(minmum, nums[low]);
                low = mid + 1;
                
            } else {
                // right sorted
                high = mid - 1;
                minmum = min(minmum, nums[mid]);
            }
        }

        return minmum; 
    }
};