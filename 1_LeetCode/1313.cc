

// 2021/01/27
// 一回で自力ACできたから, 解き直さない
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int n = (int)nums.size();
        int freq = 0, val = 1;
        
        while (val < n){
            for (int i = 0; i < nums[freq]; i++){
                ans.emplace_back(nums[val]);
            }
            freq += 2;
            val += 2;
        }
        
        return ans;
    }
};
