/*
  key point:
  https://leetcode.com/problems/maximum-product-subarray/solution/
  
  cited from tofurocks:
  
  I came to the optimal solution myself, this is how I did it:
-Write down the example test case (2, 3, -2, 4) on paper, and write down every possible branch for each step
Looked something like:
2___3__-2_____4
(2) (6) (-12) (-48)
____(3) (-6) (-24)
________(-2) (-8)
_____________(-4)
-Looked at the numbers - is there any data that we don't need here? 
(This is a step recommended by Cracking The Coding Interview. This book has a good write-up on the thought process behind trying to find solutions, I recommend it).
-Noticed that the number that leads to the overall biggest number will either be the smallest negative number, 
or the biggest positive number, at any step. This is the most important realization. After you know this, 
you can discard all of the numbers that are not the min or the max at each step.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        
        int res = max_so_far;
        
        for (int i = 1; i < n; i++){
            
            int cur = nums[i];
            int temp = max(cur,max(max_so_far*cur, min_so_far*cur));
            
            min_so_far = min(cur,min(max_so_far*cur, min_so_far*cur));
            
            max_so_far = temp;
            res = max(res,max_so_far);
        }
        
        return res;
    }
};




// brute-force : TLE  time complexity: O(N*N) space complexity: O(1) 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        
        int n = (int)nums.size();
        
        for (int i = 0; i <= n-1; i++){
            int temp = nums[i];
            res = max(res,temp);
            for (int j = i+1; j <= n - 1; j++){
                temp *= nums[j];
                res = max(res,temp);
            }
        }
        
        return res;
    }
};
