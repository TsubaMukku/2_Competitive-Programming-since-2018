
// 2020-09-25
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = (int)s.size();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for (int i = 0; i < n; i++){
            if (s[i] != t[i]) return t[i];
        }
        
        return t[t.size()-1];
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alpha_for_s(26);
        vector<int> alpha_for_t(26);
        
        for (int i = 0; i < s.size(); i++){
            alpha_for_s[ s[i] - 'a' ]++;
        }
        
        for (int i = 0; i < t.size(); i++){
            alpha_for_t[ t[i] - 'a' ]++;
        }
        
        char ans;
        
        for (int i = 0; i < 26; i++){
            if (alpha_for_s[i] != alpha_for_t[i]){
                ans = i + 'a';
                break;
            }
        }
        
        return ans;
    }
};
