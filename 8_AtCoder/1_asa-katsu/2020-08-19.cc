
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


