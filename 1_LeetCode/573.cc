
// 2021/02/02
class Solution {
private:
    int calc(vector<int> &s, vector<int> &t){
        return abs(s[0] - t[0]) + abs(s[1]-t[1]);
    }
    
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int total_dist = 0;
        int saved_dist = -1e9;
        
        for (auto nut : nuts){
            total_dist += calc(nut,tree) * 2;
            saved_dist = max(saved_dist, calc(nut,tree) - calc(nut,squirrel));
        }
        
        return total_dist - saved_dist;
    }
};

/*
なぜその解法が思い付かなかったのか
・そもそもbrute forceの解法が思いつけない

どういう思考が足りなかったのか
・最初に選ぶnutの選び方以外は重要ではないことに気づけた.
・しかし, "最初に選ぶべきnutの選び方"がわからなかった
・加えて、そのあとの実装が全く思いつかなかった

もし必要とされる思考法が足りていたとしたら解法を思い付けたのか
・解法は思い付けたかもしれないが、結局, 実装ができなかっただろう
*/
