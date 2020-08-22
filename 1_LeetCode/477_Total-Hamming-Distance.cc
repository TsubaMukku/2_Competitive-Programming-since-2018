/*
  ある特定のbitが, hamming distanceに対して, k * (n-k)だけ寄与する.
  kは, そのbitの位置における, 1が立っている数である.
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int ans = 0, n = (int)nums.size();
        
        vector<int> cnt(32);
        
        for (int num : nums){
            int i = 0;
            
            while (num > 0){
                cnt[i] += (num & 0x1);
                num >>=1;
                i++;
            }
        }
        
        for (auto k : cnt){
            ans += k * (n-k);
        }
        
        return ans;
    }
};




/*
  frute-force : TLEを起こす.
  
*/

class Solution {
public:
    int solve(int m, int n){
        int x = m ^ n;
        int res = 0;
        
        while (x > 0){
            res++;
            x = x & (x-1);
        }
        
        return res;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        
        int n = (int)nums.size();
        int ans = 0;
        
        for (int i = 0; i <= n-2; i++){
            for (int j = i + 1; j <= n-1; j++){
                ans += solve(nums[i],nums[j]);
            }
        }
        
        return ans;
    }
};

