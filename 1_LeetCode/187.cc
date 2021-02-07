

// 2021/02/07
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l = 10;
        int n = (int)s.size();
        
        unordered_map<string,int> st;
        vector<string> ans;
        
        for (int i = 0; i  <= n - l; i++){
            string tmp = s.substr(i,l);
            if (st[tmp] == 1) ans.emplace_back(tmp);
            st[tmp]++;
        }
        
        return ans;
    }
};


/*
なぜその解法が思い付かなかったのか
・substringが"2回以上"含まれていることを, どのようにすれば効率的にチェックできるのか
そのアイデアを思いつけなかった

どういう思考が足りなかったのか
・hashを用いた文字列検索
・ローリングハッシュの実装が何も見ずにできていない（ローリングハッシュを理解できていない）

もし必要とされる思考法が足りていたとしたら解法を思い付けたのか
・それでも難しいと思う（実装をバグらずにできる自信がない）


*/
