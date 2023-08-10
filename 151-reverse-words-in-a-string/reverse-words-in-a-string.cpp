class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        string temp = "";
        for(int i=0; i < s.size(); i++) {
          if(s[i] == ' ' && temp.size() != 0) {
              st.push(temp);
              temp = "";
          } else if(s[i] != ' ')temp += s[i]; 
        }

        if(temp.size()>0)
          st.push(temp);
        
        temp = "";
        
        while(!st.empty()) {
            temp += st.top();
            st.pop();
            if(!st.empty()) temp += ' ';
        }

        return temp;
    }
};