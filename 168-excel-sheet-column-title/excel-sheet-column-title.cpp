class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;

        while(columnNumber > 0) {
            if (columnNumber % 26 == 0)
              {ans += ('A' + 25);
              columnNumber-=1;}
            else 
              ans += ('A' - 1 + (columnNumber%26));
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};