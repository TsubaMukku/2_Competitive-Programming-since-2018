class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int p = (int)s.size()-1;
        
        while (p >= 0 && s[p] == ' ')p--;
        
        int cnt = 0;
            
        while (p >= 0 && s[p] != ' '){
            p--;
            cnt++;
        }
        return cnt;
    }
};
