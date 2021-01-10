

// 2021/01/10
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> check(bank.begin(),bank.end());
        vector<char> word = {'A','T','G','C'};
        if (!check.count(end)) return -1;
        
        queue<string> q;
        q.push(start);
        
        int l = start.size();
        
        int step = 0;
        
        while (q.size()){
            
            step++;
            int size = q.size();
            
            while(size--){
                
                string w = q.front();
                q.pop();
                
                for (int i = 0; i < l; i++){
                    char c = w[i];
                    
                    for (int j = 0; j < 4; j++){
                        w[i] = word[j];
                        
                        if (w == end) return step;
                        if(!check.count(w)) continue;
                        check.erase(w);
                        q.push(w);
                    }
                    w[i] = c;
                }
            }
            
        }
        
        return -1;
    }
};
