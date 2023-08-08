class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low =0, high = nums.size() - 1, mid =0;

        while(high >= low) {
            mid = low + (high-low)/2;

            if(nums[mid] == target) return true;
            
            if(nums[low] == nums[mid] && nums[high]== nums[mid]) {
               low +=1;
               high-=1;
               continue;
            }

            if(nums[low] <= nums[mid]) {
                // left sorted
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid -1;
                } else {
                    low = mid +1;
                }
                
            } else {
                // right sorted
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid -1;
                }
            }
        }

        return false;
    }
};