class Solution {
public:
    bool solve(vector<int>& nums, int k,int limit){
        int t=1;
        int sum=limit;
        for(auto i:nums){
            if(sum>=i) sum-=i;
            else{
                sum=limit;
                t++;
                if(sum<i) return 0;
                sum-=i;
            }
            if(t>k) return 0;
            
        }
        
        return 1;

    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
 
        int i=*max_element(nums.begin(), nums.end());
        int j=accumulate(nums.begin(), nums.end(), 0);
        
        while(i<=j){
            int m=(i+j)/2;
            if(solve(nums,k,m)){
                ans=min(ans,m);
                j=m-1;

            } else i=m+1;
        }
        return ans;
    }
};