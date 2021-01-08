



// 2021/01/08　NG　code -> s == "   "のような場合に対応できていない
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        if (s == "") return 0;
        if (s == " ") return 1;
        
        int n = (int)s.size();
        
        for (int i = 0; i < n; i++){
            int cnt = 1;
            vector<int> alpha(100);
            alpha[s[i]-'a']++;
            
            
            for (int j = i+1; j < n; j++){
                
                if (alpha[s[j] - 'a'] != 0){
                    break;
                }
                else{
                    cnt++;
                    alpha[s[j] - 'a']++;
                }
            }
            
            
            ans = max(ans,cnt);
        }
        
        return ans;
    }
};
