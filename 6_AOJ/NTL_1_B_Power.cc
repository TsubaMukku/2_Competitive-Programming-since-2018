/*
  ポイント: ダブリングを使う: 蟻本にも掲載されているModPow関数を実装すれば良い.
  -> 実際には繰り返し二乗法というアイデアを用いている. 本質はダブリングにある.
*/

#include <iostream>

using namespace std;

// int型でm, n, resを設定するとオーバーフローを起こしうるため注意せよ.
// % modでint型の範囲に収められるが, その操作を行うまでにlong longの範囲にはみ出ることがある.
// ex. m = 1e6のときを考えてみよ.
int ModPow(long long m, long long n, const int mod){
    
    long long res = 1;
    
    while (n > 0){
        if (n & 1) res = res * m % mod;
        m = (m * m) % mod;
        n >>= 1;
    }
    return (int)res; // 返り値はint型で返せ.
}

int main(){
    long long  m, n;
    cin >> m >> n;
    
    const int mod = 1e9+7;
    
    int ans = ModPow(m,n,mod);
    cout << ans << endl;
}

/*
  recursive version:
*/

#include <iostream>

using namespace std;
const int mod = 1e9+7;

int ModPow(long long m, long long n){
    long long res = 1;
    
    if (n > 0){
        res = ModPow(m,n/2);
        
        if (n % 2 ==0) res = (res * res) % mod;
        else res = ( (res * res) % mod * m ) % mod;
    }
    return (int)res;
}

int main(){
    long long m, n;
    cin >> m >> n;
    
    cout << ModPow(m,n) << endl;
    return 0;
}
