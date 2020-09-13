class Solution {
private:
    void dfs(vector<int> &candidates, int target, int s, vector<int> &cur, vector<vector<int>> &res){
        if (target == 0){
            res.emplace_back(cur);
            return;
        }
        
        for (int i = s; i < candidates.size(); i++){
            if (candidates[i] > target) break;
            
            cur.emplace_back(candidates[i]);
            dfs(candidates,target-candidates[i],i,cur,res);
            cur.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        
        vector<int> cur;
        
        sort(candidates.begin(),candidates.end());
        
        dfs(candidates,target,0,cur,res);
        return res;
    }
};
