

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        int m = (int)words.size();
        int n = (int)words[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < words[i].size(); j++){
                
                // 縦幅が横幅より短い場合はダメ.
                // 横幅が縦幅より短い場合はダメ.
                // アルファベットが一致しなかったらダメ.
                if (j >= words.size() || words[j].size() <= i || words[i][j] != words[j][i]) return false;
            }
        }
        
        return true;
    }
};
