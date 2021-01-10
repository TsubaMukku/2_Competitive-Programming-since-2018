
// 2021/01/10
// reference: https://zxi.mytechroad.com/blog/searching/127-word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> check(wordList.begin(),wordList.end());
        
        if (!check.count(endWord)) return 0; // 最終的な到達目標がwordlistに入っていない
        
        
        queue<string> q;
        q.push(beginWord);
        
        int l = beginWord.size();
        int step = 0;
        
        while (q.size()){
            
            step++;
            int size = q.size();
            while(size--){
                
                string w = q.front();
                q.pop();
                for (int i = 0; i < l; i++){
                    char c = w[i];
                    for (int j = 'a'; j <= 'z'; j++){
                        w[i] = j;
                        
                        if (w == endWord) return step+1;
                        
                        if (!check.count(w)) continue; // not in check
                        
                        check.erase(w); // delete new word from the list
                        
                        q.push(w); // add new word into queue
                    }
                    
                    w[i] = c;
                }
                
            }
            
        }
        
        return 0;
    }
};
