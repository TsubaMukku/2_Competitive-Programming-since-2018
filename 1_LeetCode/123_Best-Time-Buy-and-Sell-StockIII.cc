class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        
        if (n <= 1) return 0;
        
        int left_min = prices[0];
        int right_max = prices[n-1];
        
        vector<int> left_profits(n,0);
        vector<int> right_profits(n+1,0);
        
        for (int i = 1; i < n; i++){
            left_profits[i] = max(left_profits[i-1],prices[i] - left_min);
            left_min = min(left_min,prices[i]);
            
            int r = (n-1)-i;
            
            right_profits[r] = max(right_profits[r+1],right_max-prices[r]);
            right_max = max(right_max,prices[r]);
        }
        
        int res = 0;
        
        for (int i = 0; i < n; i++){
            res = max(res,left_profits[i] + right_profits[i+1]);
        }
        
        return res;
    }
};
