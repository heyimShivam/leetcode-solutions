class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0, j=0,count=0, ans=0;

        while(j<nums.size()) {
            if(nums[j]%2 == 1) count++;

            while(count>k) {
                if(nums[i]%2 == 1) count--;
                i++;
            }
            
            if(count == k) ans++;
            int x=i;
            while(nums[x]%2 == 0 && count == k) {
                x++;
                ans++;
            }
            j++;
        }

        return ans;
    }
};