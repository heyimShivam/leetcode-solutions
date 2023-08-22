class Solution {
public:
    string getPermutation(int n, int k) {
      vector<int> numbers;
      int fact = 1;
        
      for(int i=1; i<n; i++) {
        fact *=i;
        numbers.emplace_back(i);
      }

      numbers.emplace_back(n);
      
      string ans = "";
      --k;

      while(true) {
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + (k/fact));
        
        if(numbers.size() == 0) break;

        k %= fact;
        fact = fact / numbers.size(); 
      }

      return ans;
    }
};