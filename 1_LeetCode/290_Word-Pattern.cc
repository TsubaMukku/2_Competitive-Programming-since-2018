/*
    実装のお気持ち: 最後に登場した場所は, お互い同じ場所でしたか？？
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,int> patternPosition;
        map<string,int> strPosition;
        
        istringstream in(str);
        
        int i = 0, n = (int)pattern.size();
        
        for (string word; in >> word; i++){
            
            // 最後に登場した場所がお互いに異なるならばアウトである.
            if ( patternPosition[pattern[i]] != strPosition[word] ) return false;
            
            // pattern[i]とwordが最後に登場した場所はi+1番目である.
            patternPosition[pattern[i]] = strPosition[word] = i + 1;
        }
        
        return i == n; // strが一文字だけの場合, return trueとしてはダメかもしれないから
    }
};
