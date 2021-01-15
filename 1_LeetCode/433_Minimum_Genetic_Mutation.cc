

// 2021/01/15
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        if(st.count(end) == false) return -1;
        int step = 0;
        queue<string> q;
        
        q.push(start);
        st.erase(start);
        vector<char> word = {'A','T','C','G'};
        
        while (q.size()){
            step++;
            int n = q.size();
            
            while (n--){
                
                string w = q.front();
                q.pop();
                
                for (int i = 0; i < 8; i++){
                    char tmp = w[i];
                    for (int j = 0; j < 4; j++){
                        w[i] = word[j];
                        
                        if (w == end) return step;
                        
                        if (!st.count(w)) continue;
                        
                        st.erase(w);
                        q.push(w);
                    }
                    w[i] = tmp;
                }
            }
            
            
        }
        return -1;
    }
};
// 2021/01/14
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> check(bank.begin(),bank.end());
        vector<char> word = {'A','T','G','C'};
        if (!check.count(end)) return -1;
        
        queue<string> q;
        q.push(start);
        
        int step = 0;
        
        while (q.size()){
            step++;
            int size = q.size();
            
            while (size--){
                string w = q.front();
                q.pop();
                
                for (int i = 0; i < w.size(); i++){
                    char tmp = w[i];
                    
                    for (int j = 0; j < 4; j++){
                        w[i] = word[j];
                        
                        if (w == end) return step;
                        
                        if (!check.count(w)) continue;
                        check.erase(w);
                        q.push(w);
                    }
                    w[i] = tmp;
                }
            }
            
        }
        
        return -1;
    }
};

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
