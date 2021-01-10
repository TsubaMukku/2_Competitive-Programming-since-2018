

// 2021/01/10

class Solution {
private:
    void solve(string &word, string &beginWord, unordered_map<string,vector<string>> & parents, vector<string> &cur, vector<vector<string>> &ans){
        
        if (word == beginWord){
            ans.emplace_back(vector<string>(cur.rbegin(),cur.rend()));
            return;
        }
        
        for (string &p : parents.at(word)){
            cur.emplace_back(p);
            solve(p,beginWord,parents,cur,ans);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> check(wordList.begin(),wordList.end());
        
        if (!check.count(endWord)) return{};
        
        // 逆流の防止を行う
        check.erase(beginWord);
        check.erase(endWord);
        
        unordered_map<string,int> steps{{beginWord,1}};
        unordered_map<string,vector<string>> parents;
        
        queue<string> q;
        q.push(beginWord);
        
        vector<vector<string>> ans;
        
        const int l = beginWord.size();
        int step = 0;
        
        bool found = false;
        
        while(!q.empty() && !found){
            
            step++;
            
            for (int size = q.size(); size > 0; size--){
                const string p = q.front();
                q.pop();
                
                string w = p;
                
                for (int i = 0; i < l; i++){
                    const char ch = w[i];
                    
                    for (int j = 'a'; j <= 'z'; j++){
                        if (j == ch) continue;
                        
                        w[i] = j;
                        
                        if (w == endWord){
                            parents[w].emplace_back(p);
                            found = true;
                        }
                        else{
                            
                            if (steps.count(w) && step < steps.at(w)){
                                parents[w].emplace_back(p);
                            }
                        }
                        
                        if (!check.count(w)) continue;
                        check.erase(w);
                        
                        q.push(w);
                        steps[w] = steps.at(p) + 1;
                        parents[w].emplace_back(p);
                    }
                    w[i] = ch;
                }
            }
        }
        
        if (found){
            vector<string> cur{endWord};
            solve(endWord,beginWord,parents,cur,ans);
        }
        return ans;
    }
};
