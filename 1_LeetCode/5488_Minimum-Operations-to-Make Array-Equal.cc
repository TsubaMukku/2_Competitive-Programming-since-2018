class Solution {
public:
    int minOperations(int n) {
        int target;
        
        if (n % 2 == 1) target = 2 * (n / 2) + 1;
        else {
            int dividend = 2 * (n/2 - 1) + 1 + 2 * (n / 2) + 1;
            target = dividend / 2;
        }
        
        int res = 0;
        
        for (int i = 0; i < n/2; i++){
            res += abs( target - (2*i + 1) );
        }
        
        return res;
    }
};
