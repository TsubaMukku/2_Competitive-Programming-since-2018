/*
    2020-09-11
*/


class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26);
        
        for (int i = 0; i < S.size(); i++){
            last[S[i] - 'a'] = i;
        }
        
        int j = 0, anchor = 0;
        vector<int> ans;
        
        for (int i = 0; i < S.size(); i++){
            j = max(j,last[S[i] - 'a']);
            
            if (i == j){
                ans.emplace_back(j - anchor+1);
                anchor = i + 1;
            }
        }
        
        return ans;
        
    }
};


class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector<int> last(26);
        
        for (int i = 0; i < S.size(); i++){
            last[S[i] - 'a'] = i;
        }
        
        int j = 0;
        int anchor = 0;
        
        vector<int> ans;
        
        for (int i = 0; i < S.size(); i++){
            j = max(j,last[S[i] - 'a']);
            
            if (i == j){
                ans.emplace_back(i-anchor+1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};
