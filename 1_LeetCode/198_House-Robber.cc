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
