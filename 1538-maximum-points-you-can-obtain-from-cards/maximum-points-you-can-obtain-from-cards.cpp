class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSUM=0;
        for(auto it:cardPoints){
           totalSUM +=it;
        }
        if(k == cardPoints.size()) return totalSUM;

        int i=0, j=0;
        int ans=INT_MAX;
        int wsum =0;

        while(j < cardPoints.size()) {
            wsum += cardPoints[j];
            cout<<wsum<<endl;

            while(j-i+1 == cardPoints.size() - k) {
                cout<<ans<<endl;
                ans = min(ans, wsum);
                wsum -= cardPoints[i];
                i++;
            }
            j++;
        }

        return (totalSUM - ans);
    }
};