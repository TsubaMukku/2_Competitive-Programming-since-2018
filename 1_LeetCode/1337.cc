

// 2021/02/17
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        
        map<int,vector<int>> mp;
        
        for (int i = 0; i < m; i++){
            int j = 0;
            int cnt = 0;
            
            while (j < n && mat[i][j] == 1){
                cnt++;
                j++;
            }
            
            mp[cnt].emplace_back(i);
        }
        
        vector<int> ans;
        
        for (auto p : mp){
            for (auto q : p.second){
                ans.emplace_back(q);
                k--;
                if (k <= 0) return ans;
            }
        }
        
        return ans;
    }
};
