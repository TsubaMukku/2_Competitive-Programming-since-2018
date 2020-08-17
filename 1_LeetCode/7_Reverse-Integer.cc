class Solution {
public:
    int reverse(int x) {
        
        long long ans = 0;
        
        if (x == INT_MIN) return 0;
        
        while (x){
            ans = ans*10 + (x % 10);
            
            if (ans < INT_MIN || INT_MAX <= ans) return 0;
            x /= 10;
        }
        
        return ans;
    }
};
