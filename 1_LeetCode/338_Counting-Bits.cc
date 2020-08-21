/*
  以前の結果を再利用すれば良い.
  
  ex. 1011の, 1の数を数えるためには, 1 + (011 の1の数)と考えれば良い.
  
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans( num + 1);
        
        for (int i = 1; i <= num; i++){
            ans[i] = ans[i & (i-1)] + 1;
        }
        
        return ans;
    }
};



/*
  brute-forceの考え方でも解ける. 効率が良くないけど.

*/

class Solution {
public:
    int solve(int n){
        int res = 0;
        
        while (n > 0){
            res++;
            n = n & (n-1);
        }
        return res;
    }
    
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        
        for (int i = 1; i <= num; i++){
            ans[i] = solve(i);
        }
        return ans;
    }
};
