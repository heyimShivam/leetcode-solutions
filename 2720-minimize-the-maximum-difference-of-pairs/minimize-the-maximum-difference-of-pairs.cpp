class Solution {
 public:
   bool solve(vector<int>& nums,int d,int p){
        int n=nums.size();
        int c=0;
        
        for (int i = 0; i  < n-1; i++){
           if (nums[i + 1] - nums[i] <= d) {
              c++;
              i++;
           }
           
           if(c>=p) return true;
        }

        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        int low = 0, high = nums[n-1] - nums[0];
   
        while (low < high) {
            int mid = (low + high) / 2;
          
            if (solve(nums,mid,p))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};