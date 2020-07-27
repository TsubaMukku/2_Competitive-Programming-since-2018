#include <iostream>
#include <vector>

using namespace std;
const long long INF = 1LL<<60;
void chmin(long long &a, long long b) { if (a > b) a = b; }

int main(void){
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    //  区間 [ l, r )の合計値を累積和として事前に保持する
    vector<long long> cumulativeSum(n+1);
    for (int i = 0; i + 1<= n; i++) cumulativeSum[i+1] = cumulativeSum[i] + a[i];
    
    // dpの設定：
    // dp[l][r] : 区間[l,r)において, スライムをすべて合体させるときに支払うcostの最小値を保持する
    //求めるものはdp[0][n]である. n = 配列のサイズ
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,INF));
    
    // dpの初期化をする
    // [l,l]からスライムを合体させるためのコストは0である
    for (int i = 0; i +1 <= n; i++) dp[i][i+1] = 0;
    
    
    for (int offset = 1; offset <= n; offset++){
        for (int left = 0; (left < n && left + offset <= n); left++){
            int right = left + offset;
            
            long long cost = cumulativeSum[right] - cumulativeSum[left];
            
            for (int k = left + 1; k <= right-1; k++){
                chmin(dp[left][right], dp[left][k]+dp[k][right] + cost);
            }
        }
    }
    cout << dp[0][n] << endl;
    
}


/*
問題文が「区間の合体」を求めている
-> 区間のスライムを1つにする一手前の状態を考える
-> 区間は2つに別れていたことに気づく
-> 「区間の除去・圧縮・合体」などがあるときは、区間DP を用いる!!!

dpの設定：
dp[l][r] : 区間[l,r)において, スライムをすべて合体させるときに支払うcostの最小値を保持する
求めるものはdp[0][n]である. n = 配列のサイズ

dpの更新：
dp[ l ][ r ] = min( dp[ l ][ i ] + dp[ i ][ r ] +「 区間 [ l, r )の合計値」 )
支払うコストは, 区間の分割法によらず, 区間 [ l, r )の合計値」に等しい
-> 累積和として事前に保持しておくとよい


*/
