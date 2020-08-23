#include <iostream>

using namespace std;

int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans = 0;
    
    while (b > 0 && c > 0){
        c--;
        ans++;
        b--;
        ans++;
    }
    
    if (b > 0){
        ans += b;
        b = 0;
    }
    
    while (a > 0 && c > 0){
        c--;
        ans++;
        a--;
    }
    
    if (c > 0) ans++;
    
    cout << ans << endl;
    
}
