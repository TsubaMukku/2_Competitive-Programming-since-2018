/*
    solution 1: brute-force
    x^{3} = x * x * xとして地道にn回, xをかけましょう.
    
    time complexity: O(N)
    space complexity: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        for (long long i = 0; i < N; i++)
            ans = ans * x;
        return ans;
    }
};



/*
    solution 2:squaring via bit manipulation
    x^{10} = x^{1010} = (x^{ (1010) >> 1 })^{2}
    
    time complexity: O(N)
    space complexity: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        
        long long power = n;
        
        if (n < 0){
            power = -power;
            x = 1.0 / x;
        }
        
        while (power){
            if (power & 1){
                res *= x;
            }
            x *= x;
            power >>= 1;
        }
        
        return res;
    }
};


/*
  solution3: recursive 
*/

class Solution {
private:
    double myPow(double x, long long n){
        if (n == 0) return 1.0;
        
        long long index = n;
        
        if (n < 0){
            x = 1/x;
            index = -index;
        }
        
        double res = myPow(x,index/2);
        
        if (n % 2 == 0) return res*res;
        else return res*res*x;
    }
public:
    double myPow(double x, int n) {
        long long index = n;
        
        return myPow(x,index);
        
    }
};
