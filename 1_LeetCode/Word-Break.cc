class Solution {
public:
    int solve(int start, string &s, unordered_set<string> &st, vector<int> &memo){
        int n = (int)s.size();
        
        if (start == n) return 1;
        
        if (memo[start] != -1){
            return memo[start];
        }
        
        string sub;
        for (int i = start; i < n; i++){
            if (st.count(sub+=s[i]) && solve(i+1,s,st,memo)){
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> memo(s.size()+1,-1);
        
        for (string word : wordDict){
            st.insert(word);
        }
        
        return solve(0,s,st,memo);
    }
};
