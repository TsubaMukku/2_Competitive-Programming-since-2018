/*
    2020/09/17
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        
        if (n == 0) return 0;
        
        vector<int> dp(n); // dp[i]: [0,i]個目の家までで得られるお金の最大値を記録する
        dp[0] = nums[0];
        if (n >= 2)dp[1] = max(dp[0],nums[1]);
        
        for (int i = 2; i < n; i++){
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        
        return dp[n-1];
    }
};





/*
    2020/09/15
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0],nums[1]);
        
        vector<int> dp(n); // 0~i番目の家までを見たときのmaximum amount of money that can be robbed
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for (int i = 2; i < n; i++){
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        
        return dp[n-1];
    }
};





class Solution {
public:
    int rob(vector<int>& nums) {
        
        int prev = 0;
        int cur = 0;
        
        for (int x : nums){
            int temp = cur;
            cur = max(cur,prev+x);
            prev = temp;
        }
        
        return cur;
    }
};
