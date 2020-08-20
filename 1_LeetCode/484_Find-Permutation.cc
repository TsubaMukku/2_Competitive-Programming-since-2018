
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.size() + 1);
        
        stack<int> st;
        
        int j = 0;
        
        for (int i = 1; i <= s.size(); i++){
            
            if (s[i-1] == 'I'){
                st.push(i);
                while (!st.empty()){
                    res[j] = st.top();
                    st.pop();
                    j++;
                }
            }
            else{
                st.push(i);
            }
            
        }
        
        st.push(s.size()+1);
        while (!st.empty()) {
            res[j] = st.top();
            st.pop();
            j++;
        }
        
        return res;
        
    } 
};

