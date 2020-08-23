

class Solution {
public:
    int getSum(int a, int b) {
        
        long long x = abs(a);
        long long y = abs(b);
        
        if (x < y) return getSum(b,a);
        
        int sign = a > 0 ? 1 : -1;
        
        if ((long long)a * b >= 0){
            
            while (y != 0){
                int ans = x ^ y;
                int carry = (x&y) << 1;
                
                x = ans;
                y = carry;
            }
        }
        else{
            
            while (y != 0){
                int ans = x ^ y;
                long long borrow = ((~x) & y) << 1;
                
                x = ans;
                y = borrow;
            }
        }
        return x * sign;
    }
};
