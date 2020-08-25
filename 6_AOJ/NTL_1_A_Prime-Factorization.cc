/*
    original sourceは, けんちょんさんのコードです:
    https://qiita.com/drken/items/a14e9af0ca2d857dad23
    
    残った数は 1 か素数にしかならない, という点を忘れない!!
*/

#include <iostream>
#include <vector>


using namespace std;

vector<pair<long long, long long> > prime_factorize(long long n){
    
    vector<pair<long long, long long> > res;
    
    for (long long i = 2; i * i <= n; i++){
        if (n % i == 0){
            
            long long cnt = 0;
            
            while (n % i == 0){
                cnt++;
                n /= i;
            }
            
            res.emplace_back(i,cnt);
        }
    }
    
    // 最後に残るのは, 1 or 素数のみである.
    // ex. 2 * 3 * 59のようなときに59を拾っておかないとダメである.
    if (n != 1) res.emplace_back(n,1);
    
    return res;
}


int main(){
    long long n;
    cin >> n;
    
    const auto &res = prime_factorize(n);
    
    cout << n << ":";
    
    for (auto p : res){
        for (int i = 0; i < p.second; i++) cout << " " << p.first;
    }
    
    cout << endl;
}
