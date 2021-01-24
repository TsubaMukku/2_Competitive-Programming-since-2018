

// 2021/01/24
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if (word1.size() != word2.size()) return false;
        
        vector<int> check1(26,0);
        vector<int> check2(26,0);
        
        for (char c : word1) check1[c-'a']++;
        for (char c : word2) check2[c-'a']++;
        
        for (int i = 0; i < 26; i++){
            if (check1[i] == 0 && check2[i] != 0) return false;
            if (check1[i] != 0 && check2[i] == 0) return false;
        }
        
        sort(check1.begin(),check1.end());
        sort(check2.begin(),check2.end());
        
        return check1 == check2;
    }
};
