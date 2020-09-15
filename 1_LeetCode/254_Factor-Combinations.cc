/*
  2020/09/15
*/
class Solution {
private:
    void dfs(int n, int start, vector<int> &temp, vector<vector<int>> &res){
        if (n == 1){
            if (temp.size() > 1) res.emplace_back(temp);
            return;
        }
        
        for (int i = start; i <= n; i++){
            if (n % i != 0 ) continue;
            
            temp.emplace_back(i);
            dfs(n/i,i,temp,res);
            temp.pop_back();
        }
        return;
    }
    
    
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> temp;
        
        dfs(n,2,temp,res);
        return res;
    }
};






/*
  resouce: https://translate.google.com/translate?hl=en&sl=zh-CN&u=https://www.cnblogs.com/grandyang/p/5332722.html&prev=search&pto=aue
*/

class Solution {
private:
    void dfs(int n, int start, vector<int> &temp, vector<vector<int>> &res){
        
        
        // base case
        if (n == 1){
            if (temp.size() > 1) res.emplace_back(temp);
            return;
        }
        
        for (int i = start; i <= n; i++){
            
            if (n % i != 0) continue;
            
            temp.emplace_back(i);
            dfs(n/i,i,temp,res);
            temp.pop_back();
        }
        return;
        
    }
    
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> temp;
        
        dfs(n,2,temp,res);
        return res;
    }
};
