

// 2021/01/22
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int,vector<int>> m;
        queue<int> q;
        q.push(kill);
        
        for (int i = 0; i < pid.size(); i++){
            m[ppid[i]].emplace_back(pid[i]);
        }
        
        while(q.size()){
            int x = q.front();
            q.pop();
            res.emplace_back(x);
            for (int num : m[x]){
                q.push(num);
            }
        }
        return res;
    }
};
