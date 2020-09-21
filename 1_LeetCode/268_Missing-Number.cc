

// 2020-09-21
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size();
        int true_sum = n * (n+1) / 2;
        
        int temp_sum = accumulate(nums.begin(), nums.end(), 0);
        
        return true_sum - temp_sum;
    }
};
