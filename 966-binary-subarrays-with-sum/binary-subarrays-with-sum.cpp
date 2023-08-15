class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0, j=0, ans=0;
        int sum = 0;

        if(goal==0)
        {
            while(j<nums.size())
            {
                while(i<=j && nums[j])
                {
                    i++;
                }
                ans+=j-i+1;
                j++;
            }
            return ans;
        }

        while(j < nums.size()) {
            sum += nums[j];
            
            while(sum > goal) {
                sum -= nums[i];
                i++;
            }

            if(sum == goal) ans++;
            int x=i;
            while(nums[x]==0 && sum==goal){
                ans++;
                x++;
            }
            j++;
        }

        return ans;
    }
};