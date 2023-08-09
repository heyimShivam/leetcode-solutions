class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> temp;
        
        for(auto num:nums1)
            temp.push_back(num);
        
        for(auto num:nums2)
            temp.push_back(num);
        
        sort(temp.begin(),temp.end());
        
        int n=temp.size();
        
        return n%2?temp[n/2]:(temp[n/2-1]+temp[n/2])/2.0;
    }
};