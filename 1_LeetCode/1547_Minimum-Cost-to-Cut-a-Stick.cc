class Solution {
public:
    
    /*
        dp[left][right]: [left,right]をカットするときの最小コストを保持する 
        dp[left][right] == 0 が, 未訪問であることを示す.
        cut.size() <= 100より, 10^{6} * 100がcostの上限である. -> int型に答えが収まる.
    */
    
    /*
        [left,right]をカットするときの最小コストを求めて返す.
    */
    int dfs(vector<int> &cuts, int left, int right, vector<vector<int>> &dp){
        
        // base case: [left,left+1]の場合: これ以上カットできないから処理を修了する. costは0である.
        
        if (left + 1 == right) return 0;
        
        if (!dp[left][right]){
            dp[left][right] = 1e9 + 7;
            
            for (int mid = left + 1; mid <= right-1; mid++){
                dp[left][right] = min (dp[left][right], cuts[right] - cuts[left] + dfs(cuts,left,mid,dp) + dfs(cuts,mid,right,dp));
            }
        }
        
        return dp[left][right];
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(110,vector<int>(110,0));
        
        return dfs(cuts,0,(int)cuts.size()-1,dp);
    }
};
