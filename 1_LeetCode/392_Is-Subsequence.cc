/*
  しゃくとり法を使うだけ.
  sの方のindex == s.size()となる場合は, sはtの部分列である.
  そうでなければ, falseを返す.
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        
        int pos1 = 0;
        
        for (int i = 0; i < m; i++){
            if (s[pos1] == t[i])pos1++;
            
            if (pos1 == n) return true;
        }
        
        return false;
        
    }
};
