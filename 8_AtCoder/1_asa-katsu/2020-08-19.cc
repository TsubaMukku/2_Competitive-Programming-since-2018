
/*
A - Ice Tea Store 

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    long long q, h, s, d;
    cin >> q >> h >> s >> d;
    
    long long n;
    cin >> n;
    
    long long ans = 0;
    
    if (n % 2 == 0){
        
        ans += min( 4*q*n, min( 2*h*n, min( n*s,d*n/2 ) ) );
    }
    else{
        long long temp = n - 1;
        
        ans += min( 4*q*temp, min( 2*h*temp, min( temp*s, d*temp/2 ) ) );
        ans += min(4*q, min( 2*h, s ) );
    }
    cout << ans << endl;
}



/*
B - K個のケーキ

隣り合う同じ数のペアを最小化する問題である.
->最大となるaの値を見つけて, 他の残りをその間に挟み込んでいく.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int k, t;
    cin >> k >> t;
    
    vector<int> a(t);
    for (int i = 0; i < t; i++) cin >> a[i];
    
    sort(a.rbegin(),a.rend());
    
    int max_a = a[0];
    
    int temp = (max_a - 1 - (k - max_a ) );
    int ans = max(0,temp);
    
    cout << ans << endl;
}
