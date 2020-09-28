
// 2020-09-28
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> in(n);
        
        for (auto edge : edges){
            int x = edge[0];
            int y = edge[1];
            in[y]++;
        }
        
        for (int i = 0; i < n; i++){
            if (in[i] > 0) continue;
            res.emplace_back(i);
        }
        return res;
    }
};
