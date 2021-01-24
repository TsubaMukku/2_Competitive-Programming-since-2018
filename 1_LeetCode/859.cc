

// https://leetcode.com/problems/buddy-strings/discuss/891469/C%2B%2BJavaPython-One-pass-Clean-and-Concise-O(N)
//　2021/01/24

/*
場合わけがポイントである　
そもそも"swapが1回しかできない"ことを読み取れないと問題が解けない.
-> 文字が異なる場所の個数を基準にして場合分けを行う.

1回しかswapできないため, 異なる場所が3箇所以上ある場合, false
異なる場所が2箇所の場合, abc cbaのようにAの文字にはAの文字, Bの文字にはBの文字が対応していることをチェックする.
異なる場所が1箇所の場合, abc adcのようにfalse
異なる場所がない場合: これがコーナーケースである
-> ab abはNG, aab, aabはOKであるから、ポイントは"文字の重複が存在するかどうか、つまりswapの遊びを許せるかどうか"である
*/


class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        
        int diff1 = -1,diff2 = -1;
        
        set<char> letters; // aab, aabのようなケースを処理するためには重複を排除する必要がある
        
        for (int i = 0; i < A.size(); i++) {
            
            if (A[i] != B[i]) {
                if (diff1 == -1) diff1 = i; // 異なる文字1箇所目
                else if (diff2 == -1) diff2 = i; // 異なる文字2箇所目
                else return false; // 異なる文字が3文字以上あるため, 1回のswapでは処理不可能である
            }
            letters.insert(A[i]);
        }
        
        if (diff1 != -1 && diff2 != -1) // There are 2 different places
            return A[diff1] == B[diff2] && A[diff2] == B[diff1]; 
        
        if (diff1 != -1) // Only have 1 different place
            return false;
        
        return letters.size() < A.size(); // ab, abのようなケースはダメ, aab,aabのようなケースはOK
    }
};

// https://leetcode.com/problems/buddy-strings/discuss/891469/C%2B%2BJavaPython-One-pass-Clean-and-Concise-O(N)
