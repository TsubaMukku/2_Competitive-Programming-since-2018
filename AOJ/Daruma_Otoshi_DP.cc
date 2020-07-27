#include <bits/stdc++.h>

using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int N;
vector<int> w;

int solve() {
    
    // 区間[l,r)における取り除くことができる数の最大値を保持する
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    
    for (int i = 0; i <= N; ++i) {
        dp[i][i] = 0; // 区間が存在しないため0個しか取り出せない
        if (i < N) dp[i][i+1] = 0; // 区間[l,l]には隣り合うペアがいない. 0個しか取り出せない.
    }
    
    for (int offset = 2; offset <= N; offset++) {
        for (int i = 0; i + offset <= N; i++) {
            int j = i + offset;
 
            // 1. 全部取り除けるかもしれないとき
            // この場合は２パターンが有る:
            // (1) {1,1,2,1,2,1}のように区間をすべて除去できる場合
            // (2) {1,2,3,10000,20,445,1}のような, 偽物 -> 2. otherwiseでの処理となる
            if ( abs(w[i]- w[j-1]) <= 1){
                if ( dp[i+1][j-1] == j-i-2) chmax(dp[i][j],j-i);
            }
            
            // 2. otherwise
            // ex: {1,2,3,4,5,77,33,19}
            // -> {1,2,3,4,5}という分割と, {77,33,19}という分割を見つけ出す
            // 結果を記録する
            for (int k = i+1; k <= j-1; ++k) {
                chmax(dp[i][j], dp[i][k] + dp[k][j]);
            }
            
        }
    }
    return dp[0][N];
}

int main() {
    while (cin >> N, N) {
        w.resize(N);
        for (int i = 0; i < N; ++i) cin >> w[i];
        cout << solve() << endl;
    }
}


/*
解法の考え方

区間を取り除く場合
(1) 区間[l,r-1]がすべて取り除かれる場合 (区間をごっそり全部取り出せる)
// ex: {1,2,1,1,1,1}

(2) それ以外の場合
// ex: {1,4,5,3,3,7}
に分けることができる


(1)の場合の条件判定のみ行えばよい.
(2)では
どこかで区切って2つ区間に分けても答えが同じになる切り方が存在する
// ex: {1,4,5,3,3}, {7}

(1)の場合は
区間 [l+1, r-1) は全て取り除くことができ, かつ, 両端の値の差の絶対値が1以下の場合である

(2)の場合は
[l,r)の中での区間の分割をすべて試して, その中で取り除くことができる数の
最大値を求めれば良い.

あとは, 上記の考え方を
実装すれば良い
（ループ処理でも良いし, 再帰処理でも良い）
*/







