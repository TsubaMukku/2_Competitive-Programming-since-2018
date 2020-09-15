/*
    2020/09/15
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        int n = (int)intervals.size();
        if ( n == 0 ) return res;
        
        //sort(intervals.begin(),intervals.end(), [](vector<int> a, vector<int> b){ return a[0] < b[0];});
        
        sort(intervals.begin(),intervals.end());
        
        res.emplace_back(intervals[0]);
        
        for (int i = 1; i < n; i++){
            
            if (res[res.size()-1][1] < intervals[i][0]) res.emplace_back(intervals[i]);
            else{
                res[res.size()-1][1] = max(res[res.size()-1][1],intervals[i][1]);
            }
        }
        
        return res;
    }
};




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        int n = (int)intervals.size();
        if (n == 0) return res;
        
        sort(intervals.begin(),intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
            
        res.emplace_back(intervals[0]);
        
        for (int i = 1; i < n; i++){
            
            if (res[res.size()-1][1] >= intervals[i][0]){
                res[res.size()-1][1] = max(res[res.size()-1][1], intervals[i][1]);
            }
            else{
                res.emplace_back(intervals[i]);
            }
        }
        
        return res;
    }
};
