/*
  Author: Tsubasa Takamuku
  Date: 2020-08-14 11:26
*/

/*
    solution1: Generate all combinations as a preprocessing.
*/
class CombinationIterator {
public:
    // 長さlenの部分文字列を全て事前に作成して, 記録しておく.
    set<string> GenerateAllCombinations(string s, int len){
        set<string> res;
        int bit_mask = 1 << (int)s.size();
        
        for (int i = 1; i < bit_mask; i++){
            int num = i;
            int pos = 0;
            
            string temp = "";
            
            while (num > 0){
                if (num & 1) temp += s[pos];
                pos++;
                num >>= 1;
            }
            
            if ((int)temp.size() == len) res.insert(temp);
        }
        
        return res;
    }
    
    set<string> res;
    
    // set<string>型が用いるイテレータの型を
    // set<string>::iteratorとして取る.
    set<string>::iterator cur;
    
    CombinationIterator(string characters, int combinationLength) {
        res = GenerateAllCombinations(characters,combinationLength);
        cur = res.begin();
    }
    
    // setにおいて,ix 番目の要素に無理やりアクセスしたい場合は
    // begin() で取ってきたイテレータを ix 回インクリメントして
    // イテレータの指す要素へアクセスする.
    string next() {
        if (cur != res.end()){
            return *cur++;
        }
        else return "";
    }
    
    bool hasNext() {
        if (cur != res.end()) return true;
        else return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


/*

引用: http://vivi.dyndns.org/tech/cpp/set.html
set の内部構造は配列ではなく、二分木になっている.
[] 演算子（operator[](size_t)）で、指定番目の要素を取り出すことは出来ない.
-> イテレータ を使って各要素にアクセスする必要がある。

イテレータとは抽象化されたポインタである.
begin() で最初の要素への、end() で最後の要素の次へのイテレータを取得することが出来る.

ix 番目の要素に無理やりアクセスしたい場合は,begin() で取ってきたイテレータを ix 回インクリメントする.
*/
