class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSUM=0;
        int n = cardPoints.size();
        for(auto it:cardPoints){
           totalSUM +=it;
        }
        if(k == n) return totalSUM;

        int i=0, j=0;
        int ans=INT_MAX;
        int wsum =0;

        while(j < n) {
            wsum += cardPoints[j];

            if(j-i+1 == n - k) {
                ans = min(ans, wsum);
                wsum -= cardPoints[i];
                i++;
            }

            j++;
        }

        return (totalSUM - ans);
    }
};