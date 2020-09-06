#include <iostream>
#include <algorithm>

using namespace std;

void solve(int a, int b){
    
    bool check = true;
    while (true){
        
        if (a > b) swap(a,b);
        
        if (b % a == 0) break;
        
        if (b - a > a) break;
        
        b -=a;
        check = !check;
    }
    
    if (check) cout << "Stan wins" << endl;
    else cout << "Ollie wins" << endl;
}

int main(void){
    
    int a, b;
    while (cin >> a >> b){
        if (a == 0 && b == 0) break;
        solve(a, b);
    }
    
    
    
    return 0;
    
}
