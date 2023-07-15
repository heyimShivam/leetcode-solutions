class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n+1, 0);

        for(int index = n-1; index>=0; index--) {
           vector<int> cur(n+1, 0);
           
           for(int prevIndex= index-1; prevIndex>=-1; prevIndex--) {
               int take =INT_MIN;
               
               if(prevIndex == -1 || nums[prevIndex] < nums[index])
                  take = 1 + prev[index+1];

               cur[prevIndex+1] = max(prev[prevIndex+1], take);
           }
           
           prev = cur;
        }

        return prev[0];
    }
};