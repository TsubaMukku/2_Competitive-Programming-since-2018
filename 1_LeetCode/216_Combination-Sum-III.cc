/*
  resource: https://translate.google.com/translate?hl=en&sl=zh-CN&u=https://zxi.mytechroad.com/blog/searching/leetcode-216-combination-sum-iii/&prev=search&pto=aue
*/ 

class Solution {
private:
    
    // use k numbers to sum up to n
    // from i = s, s+1, ... , 9
    void dfs(int k, int n, int s, vector<int> &cur, vector<vector<int>> &res){
        
        if (k == 0) {
            if (n == 0) res.emplace_back(cur);
            return;
        }
        
        for (int i = s; i <= 9; i++){
            if (i > n) return;
            cur.emplace_back(i);
            dfs(k-1,n-i,i+1,cur,res);
            cur.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        
        vector<int> cur;
        
        dfs(k,n,1,cur,res);
        
        return res;
    }
};
