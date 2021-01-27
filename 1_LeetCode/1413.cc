

// 2021/01/27
// first try
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = (int)nums.size();
        int tmp = 0, min_num = 0;
        
        for (int i = 0; i < n; i++){
            tmp += nums[i];
            min_num = min(min_num,tmp);
        }
        
        return 1 - min_num;
    }
};
