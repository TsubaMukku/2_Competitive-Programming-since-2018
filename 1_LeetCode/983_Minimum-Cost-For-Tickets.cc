
/*
  solution1: using naive DP
  
  time complexity: O(365);
  space complexity: O(365);
  
  * if do not have to travel, it is better not to buy any pass.
  * if have to travel, either a 1-day, 7-day, 30-day pass must be taken.
  
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         set<int> st;
        for (int i = 0; i < days.size(); i++) st.insert(days[i]);
        
        
        // 0日目からi日目までに要するコストの最小値を保持する.
        vector<int> dp(366,0);
        
        for (int i = 1; i < 366; i++){
            
            if (st.count(i)){
                int temp1 = max(0,i-7);
                int temp2 = max(0,i-30);
                
                // カバーするために必要な費用の中で,最小値をとれば良い.
                dp[i] = min(dp[i-1]+costs[0],dp[temp1]+costs[1]);
                dp[i] = min(dp[i],dp[temp2]+costs[2]);
            }
            else{
                // travelしなくてよい日ならば, わざわざ追加出費する必要はない.
                dp[i] = dp[i-1];
            }
            
        }
        
        return dp[365];
    }
};
