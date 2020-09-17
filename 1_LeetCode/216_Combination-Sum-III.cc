/*
  2020/09/17
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        
        for (int i = 0; i < (1<<9); i++){
            
            vector<int> temp;
            int temp_sum = 0;
            
            for (int j = 0; j < 9; j++){
                if ( i & (1 << j) ){
                    temp_sum += (j+1);
                    temp.emplace_back(j+1);
                }
            }
            
            if (temp_sum == n && (int)temp.size() == k) res.emplace_back(temp);
        }
        
        return res;
    }
};


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


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        
        // generate all combinations 
        for (int i = 0; i < (1<<9); i++){
            vector<int> cur;
            int sum = 0;
            
            // use j if (j-1)th bit is 1
            for (int j = 1; j <= 9; j++){
                if ( i & (1<<(j-1)) ) {
                    sum += j;
                    cur.emplace_back(j);
                }
            }
            if (sum == n && cur.size() == k) res.emplace_back(cur);
        }
        
        return res;
    }
};
