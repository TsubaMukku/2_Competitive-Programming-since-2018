
// 2020-11-09
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;

int gcd(int m, int n){
    if (n == 0) return m;
    else{
        return gcd(n,m%n);
    }
}

int lcm(int m, int n){
    return m / gcd(m,n) * n;
}

int main(){
    int n;
    cin >> n;
    
    int res = 1;
    
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        
        res = lcm(res,a);
    }
    
    cout << res << endl;
    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
  
    return gcd(b,a % b);
}


int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = a[0];
    for (int i = 1; i < n; i++) ans = ans * a[i] / gcd(ans,a[i]);
    
    cout << ans << endl;
}
