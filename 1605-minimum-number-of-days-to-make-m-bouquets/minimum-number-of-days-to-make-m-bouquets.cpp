class Solution {
public:
    bool solve(vector<int>& arr,int day,int m, int adj){
        int n=arr.size();
        int c=0, k = 0;
        
        for (int i = 0; i  < n; i++){
           if (arr[i] <= day) {
              c++;
           } else c = 0;
           
           if(c == adj) {
               c =0;
               k++;
           };

           if(m == k) return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        int low = INT_MAX, high=INT_MIN;

        long long val = m * 1ll * k;
        if (val > n) return -1;

        for (auto it:bloomDay) {
            high = max(it, high);
            low = min(it, low);
        }
   
        while (low <= high) {
            int mid = (low + high) / 2;
          
            if (solve(bloomDay, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};