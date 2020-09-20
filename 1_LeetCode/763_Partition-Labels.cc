// 2020-09-20
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = (int)intervals.size();
        if (n == 0) return res;
        sort(intervals.begin(),intervals.end());
        
        res.emplace_back(intervals[0]);
        
        //int first = intervals[0][0];
        //int last = intervals[0][1];
        
        for (int i = 1; i < n; i++){
            
            if (res[(int)res.size()-1][1] < intervals[i][0]) res.emplace_back(intervals[i]);
            else{
                res[(int)res.size()-1][0] = min(res[(int)res.size()-1][0], intervals[i][0]);
                res[(int)res.size()-1][1] = max(res[(int)res.size()-1][1], intervals[i][1]);
                
                
            }
            
        }
        return res;
    }
};


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
