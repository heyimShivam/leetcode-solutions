class Solution {
public:
    vector<int> countBits(int n) {
      vector<int> arr;
      int i=0;
      while(i <= n) {
        int outer = i, count =0;

        while(outer>0) {
          if(outer%2 == 1 ) count++;
          outer = outer/2;
        }

        arr.emplace_back(count);
        i++;
      }

      return arr;
    }
};