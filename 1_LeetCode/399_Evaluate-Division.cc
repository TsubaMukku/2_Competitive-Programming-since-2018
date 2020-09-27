
// 2020-09-28
// reference: https://translate.google.com/translate?hl=en&sl=zh-CN&u=https://zxi.mytechroad.com/blog/graph/leetcode-399-evaluate-division/&prev=search&pto=aue


class Solution {
public:
    double calc(string x, string y, unordered_map<string,unordered_map<string,double>> &g, unordered_set<string> &visited){
        if (x == y) return 1.0;
        
        visited.insert(x);
        for (auto p : g[x]){
            string c = p.first;
            if (visited.count(c)) continue;
            double d = calc(c,y,g,visited); // d = c / y;
            
            // x / y = c / y * x / c;
            if (d > 0) return d * g[x][c];
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // g[a]][b] = k => a / b = k;
        
        unordered_map<string,unordered_map<string,double>> g;
        
        for (int i = 0; i < equations.size(); i++){
            const string a = equations[i][0];
            const string b = equations[i][1];
            const double k = values[i];
            g[a][b] = k;
            g[b][a] = 1.0/k;
        }
        
        vector<double> ans;
        for (auto p : queries){
            string x = p[0];
            string y = p[1];
            
            if (!g.count(x) || !g.count(y)){
                ans.emplace_back(-1.0);
                continue;
            }
            
            unordered_set<string> visited;
            ans.emplace_back(calc(x,y,g,visited));
        }
         return ans;   
        
    }
};
