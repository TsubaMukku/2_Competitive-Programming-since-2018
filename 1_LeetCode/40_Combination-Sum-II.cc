



















// TLE

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n = (int)candidates.size();
        
        sort(candidates.begin(),candidates.end());
        
        // generate all combinations 
        for (long long i = 0; i < (1LL<<n); i++){
            vector<int> cur;
            int sum = 0;
            
            // use candidates[j] if jth bit is 1
            for (long long j = 0; j <= n-1; j++){
                if ( i & (1LL<<j) ) {
                    sum += candidates[j];
                    cur.emplace_back(candidates[j]);
                }
            }
            if (sum == target && find(res.begin(),res.end(),cur) == res.end()) res.emplace_back(cur);
        }
        
        return res;
    }
};
