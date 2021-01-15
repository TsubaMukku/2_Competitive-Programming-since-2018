
// 2021/01/15
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tmp = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        int ans = 1e9+7;
        
        // tmp = nums[0] + ... + nums[left-1] + nums[right+1] + ... + nums[n-1]
        for (int right = 0; right < n; right++){
            tmp -= nums[right];
            
            while (tmp < x && left <= right){
                tmp += nums[left];
                left++;
            }
            
            if (tmp == x){
                ans = min(ans,n-(right+1)+left);
            }
        }
        
        return ans != 1e9+7 ? ans : -1;
    }
};
