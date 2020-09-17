/*
    2020/09/17 
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = (int)s.size()-1;
        
        while (pos >= 0 && s[pos] == ' ') pos--;
        
        int cnt = 0;
        
        while (pos >= 0 && s[pos] != ' '){
            pos--;
            cnt++;
        }

        return cnt;
    }
};



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
