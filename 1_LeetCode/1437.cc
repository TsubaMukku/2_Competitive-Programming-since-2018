

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
