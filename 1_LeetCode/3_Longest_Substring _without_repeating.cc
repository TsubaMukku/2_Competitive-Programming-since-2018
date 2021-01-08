


// 2021/01/08　OK
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        int ans = 0;
        
        vector<int> idx(128,-1); // その文字が最後に現れた場所を記録する.
        for (int i = 0, j = 0; j < n; j++){
            i = max(i,idx[s[j]]+1);
            ans = max(ans,j-i+1);
            idx[s[j]] = j;
        }
        
        return ans;
    }
};



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
