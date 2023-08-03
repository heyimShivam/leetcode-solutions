class Solution {
public:
    void choice(int place, string digits, string temp, vector<string> &result, string mp[]){
       if(place == digits.size()) {
           result.emplace_back(temp);
           return;
       }
       string check= mp[ digits[place]-'0' ];
       for(auto value : check) {
          choice(place+1, digits, temp+value, result, mp);
       }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()==0) return result;

        string mp[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        choice(0, digits, "", result, mp);
        return result;
        
    }
};