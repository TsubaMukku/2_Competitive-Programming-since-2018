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
