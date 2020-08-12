/*
  Author: Tsubasa Takamuku
  Date: 2020-08-12 8:56
*/


/* 
  Solution1: Implement the LIFO movement of the procedure
  
  time complexity: O(N) ... for loop
  space complexity: O(N) ... stack
  
  int N = (int) s.size()
  
 */
 
class Solution {
public:
    string makeGood(string s) {
        int n = (int)s.size();
        stack<char> st;
        st.push(s[0]);
        
        for (int i = 1; i < n; i++){
            
            if (st.empty()){
                st.push(s[i]);
                continue;
            }
            
            char temp = st.top();
            
            if (temp != s[i] && tolower(temp) == tolower(s[i])){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        
        while (!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
            
        return ans;
    }
};


/* 
  Solution2: Just do what the problem asks us to do until you can't
  
  time complexity: O(N) ... for loop
  space complexity: O(1)
  
  int N = (int) s.size()
  
 */

class Solution {
public:
    string makeGood(string s) {
        int sz = 0;
        
        while (sz != (int) s.size()){
            sz = (int)s.size();
            
            for (int i = 0; i + 1 < s.size(); i++){
                if (s[i] != s[i+1] && tolower(s[i]) == tolower(s[i+1])){
                    s = s.substr(0,i) + s.substr(i+2);
                }
            }
        }
        
        return s;
    }
};

