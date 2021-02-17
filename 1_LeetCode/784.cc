

// 2021/02/17
class Solution {
private:
    vector<string> ans;
    void solve(string &s, int i,int n){
        int index = i;
        if(index == n){
            ans.emplace_back(s);
            return;
        }
        
        if(isalpha(s[index])){
            s[index] = tolower(s[index]);
            solve(s,index+1,n);
        
            s[index] = toupper(s[index]);
            solve(s,index+1,n);
        }
        else{
            solve(s,index+1,n);
        }
        
        
        return;
    }
    
public:
    vector<string> letterCasePermutation(string S) {
        int n = (int)S.size();
        int i = 0;
        solve(S,i,n);
        
        return ans;
    }
};
