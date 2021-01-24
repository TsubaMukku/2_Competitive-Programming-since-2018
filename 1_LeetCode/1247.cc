

// 2021/01/24
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        
        if (s1.size() != s2.size()) return -1;
        /*
        1. 具体例は解法のヒント・誘導として与えられる可能性を考慮せよ
        2. 基本的に使いやすい方を使いつくせ. 残りはうまく処理せよ
        */
        
        int case1 = 0;
        int case2 = 0;
        
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] == 'x' && s2[i] == 'y') case1++;
            else if (s1[i] == 'y' && s2[i] == 'x') case2++;
        }
        
        if ( (case1 + case2) % 2 == 1) return -1;
        
        // xy-yx, yx-xyは2回の処理が必要だから, 切り上げ処理で対応する.
        return (case1 + 2 - 1) / 2 + (case2 + 2 - 1) / 2;
    }
};
