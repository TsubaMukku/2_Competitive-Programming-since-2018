

// 2021/02/12

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = (int)s.size();
        int m = (int)p.size();
        
        vector<int> ans;
        if (n < m) return ans;
        
        // n >= m
        vector<int> substr_s(100);
        vector<int> mp(100);
        
        for (int i = 0; i < m; i++) mp[p[i]-'a']++;
        
        for (int i = 0; i < m; i++) substr_s[s[i]-'a']++;
        
        if (substr_s == mp) ans.emplace_back(0);
        
        for (int i = m; i <= n-1; i++){
            substr_s[s[i-m]-'a']--;
            substr_s[s[i]-'a']++;
            
            if (substr_s == mp) ans.emplace_back(i-m+1);
        }
        
        return ans;
    }
};
