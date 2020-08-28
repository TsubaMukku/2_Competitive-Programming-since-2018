class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();
        
        vector<int> ret(n,-1);
        map<int,int> mp;
        
        for (int i = 0; i < n; i++){
            if (mp.count(intervals[i][0])) continue;
            mp[intervals[i][0]] = i + 1;
        }
        
        for (int i = 0; i < n; i++){
            
            // intervals[i][1]以上となる mp.firstの要素の上界のindexを取る.
            auto it = mp.lower_bound(intervals[i][1]);
            // if (it->second == 0) continue;
            ret[i] = it->second - 1;
        }
        
        return ret;
    }
};
