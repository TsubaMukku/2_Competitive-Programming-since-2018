class Solution {
private:
    int solve(vector<int> &nums, int l, int r){
        int prev = 0;
        int cur = 0;
        
        for (int i = l; i <= r; i++){
            int temp = max(prev+nums[i], cur);
            prev = cur;
            cur = temp;
        }
        
        return cur;
    }
    
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 2) return n ? nums[0] : 0;
        
        return max(solve(nums,0,n-2), solve(nums,1,n-1));
    }
};
