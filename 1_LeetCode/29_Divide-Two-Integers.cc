

/*
  solution1: brute-force
  
  TLE:
  time complexity: O(N) like dividend = INT_MAX divisor = 1
  space complexity: O(1)

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // corner case:
        // (INT_MIN  / (-1) ) :overflow in the int type
        // function returns 2^{31} − 1 when the division result overflows.
        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        // 1. convert both numbers to negative ones
        //    also, count the number of negative signs
        
        int negatives = 2;
        
        if (dividend > 0){
            negatives--;
            dividend = -dividend;
        }
        if(divisor > 0){
            negatives--;
            divisor = -divisor;
        }

        
        // 2. count how many times the divisor has to be added
        // this is the quotient
        int q = 0;
        
        while (dividend - divisor <= 0){
            dividend -= divisor;
            q--;
        }
        
        //3. if negatives == 1 -> the sign must be negative
        if (negatives != 1) return -q;
        else return q;
    }
};


/*

    solution2: repeated exponential searches
    
    time complexity: O((log N) * (log N)
    space complexity: O(1)

    
*/

class Solution {
private:
    int HALF_INT_MIN = -1073741824; // subtractionの過程でこの値より小さい値を考えると, overflowを起こす.
public:
    
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int neg = 2;
        
        if (dividend > 0){
            neg--;
            dividend = -dividend;
        }
        
        if (divisor > 0){
            neg--;
            divisor = -divisor;
        }
        
        int quotient = 0;
        
        while (divisor >= dividend){
            int power_of_two = -1;
            int value = divisor;
            
            while (value >= HALF_INT_MIN && value + value >= dividend){
                value += value;
                power_of_two += power_of_two;
            }
            
            quotient += power_of_two;
            dividend -= value;
        }
        
        if (neg != 1) return -quotient;
        else return quotient;
    }
};


/*
    solution3: Adding Powers of Two
*/

class Solution {
private: 
    int HALF_INT_MIN = -1073741824;
public:
    int divide(int dividend, int divisor) {
        
        // corner case:
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int neg = 2;
        if (dividend > 0){
            neg--;
            dividend = -dividend;
        }
        
        if (divisor > 0){
            neg--;
            divisor = -divisor;
        }
        
        vector<int> doubles;
        vector<int> powers_of_two;
        
        int index = -1;
        
        while (divisor >= dividend){
            
            doubles.emplace_back(divisor);
            powers_of_two.emplace_back(index);
            
            if (divisor < HALF_INT_MIN) break;
            
            divisor += divisor;
            index += index;
        }
        
        int q = 0;
        
        for (int i = (int)doubles.size()-1; i >= 0; i--){
            if (doubles[i] >= dividend){
                q += powers_of_two[i];
                dividend -= doubles[i];
            }
        }
        
        if (neg != 1) return -q;
        else return q;
    }
};
