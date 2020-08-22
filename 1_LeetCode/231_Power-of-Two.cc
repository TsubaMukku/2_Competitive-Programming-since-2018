/*
  xが2のべき乗であることと, (x & (-x) ) == xは同値である.
  これを利用すれば良い.
  
  2で割れるだけ割っていき, 最後の数値が1になれば, xは2のべき乗である.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        
        long long x = n;
        
        return (x & (-x)) == x;
    }
};
