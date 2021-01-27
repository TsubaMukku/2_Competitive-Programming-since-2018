

// 2021/01/27
// sliding window
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;
        
        int sum = 0; // nums[l] + nums[l+1] + ... + nums[r]
        
        for (int l = 0, r = 0; r < n; r++){
            
            sum += nums[r];
            
            // maintain sum >= r - l
            // at most 1 zero 
            while (l < r && sum < r -l){
                sum -= nums[l];
                l++;
            }
            ans = max(ans,r-l);
            
        }
        return ans;
    }
};
