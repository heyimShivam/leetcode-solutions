class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int, int>> pq;

        int j=0;
        vector<int> ans(n-k+1);
        
        for(int i=0; i<k; i++) {
            pq.push({nums[i], i});
        }

        ans[0]=pq.top().first;
       
        j=k;
        
        while(j<nums.size()) {
            while(!pq.empty() && pq.top().second <= j-k)
               pq.pop();

            pq.push({nums[j], j});

            ans[j-k+1] = pq.top().first;
            j++;
        }

        return ans;
    }
};