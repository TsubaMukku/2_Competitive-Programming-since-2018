/*
  xが3のべき乗であることと, 3で割れるだけ割ったときに残る数が1であることは, 同値である.
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        
        while (n % 3 == 0) n /= 3;
        
        if (n == 1) return true;
        else return false;
    }
};

