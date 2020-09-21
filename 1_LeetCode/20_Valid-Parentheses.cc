
// 2020-09-21
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = (int)s.size();
        
        for (int i = 0; i < n; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else if (st.empty()) return false;
            else if (s[i] == ')'){
                char temp = st.top();
                st.pop();
                if (temp != '(') return false;
                else continue;
            }
            else if (s[i] == '}'){
                char temp = st.top();
                st.pop();
                if (temp != '{') return false;
                else continue;
            }
            else{
                char temp = st.top();
                st.pop();
                if (temp != '[') return false;
                else continue;
            }
        }
        
        if (st.empty()) return true;
        else return false;
    }
};
