/*
    solution1: make x string and check from the left part and from the last part
    
    solution2: Revert half of the number time 
        time complexity: O(N)
        space complexity: O(1)

*/

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        
        int r = 0;
        
        while (x > r){
            r = r * 10 + x % 10;
            x /= 10;
        }
        
        return x == r || x == r/10;
    }
};
