

// 2020-09-25
class Solution {
public:
    int reverse(int x) {
        bool is_negative = false;
        if (x < 0){
            is_negative = true;
            x = abs(x);
        }
        
        long long res = 0;
        
        while (x > 0){
            res = res*10 + (x % 10);
            if (res < INT_MIN || INT_MAX < res) return 0;
            x /= 10;
        }
        
        if (is_negative) return (-1)*res;
        else return res;
    }
};



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
