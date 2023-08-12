class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() < s.size()) return false; 
        string news = s + s;

        size_t found = news.find(goal);

        if (found != string::npos) return true;

        return false;
    }
};