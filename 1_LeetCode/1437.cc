

// 2021/01/27
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0;
        int n = (int)nums.size();
        
        while (i < n && nums[i] == 0) i++;
        i++;
        
        int cnt = 0;
        while (i < n){
            if (nums[i] == 1){
                if (cnt >= k){
                    cnt = 0;
                    i++;
                }
                else{
                    return false;
                }
            }
            else{
                cnt++;
                i++;
            }
        }
        
        return true;
    }
};

// 2021/01/26
// ref: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/solution/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        // initialize the counter of zeros to k
        // to pass the first 1 in nums
        int count = k;
        
        for (int num : nums){
            
            // if the current integer is 1
            if (num == 1){
                
                // check that number of zeros in-between 1s
                // is greater than or equal to k
                if (count < k) return false;
                else count = 0;
                
            }
            else{
                // the current number is 0
                count++;
            }
        }
        
        return true;
    }
};
