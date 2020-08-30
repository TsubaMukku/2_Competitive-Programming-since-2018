#include <iostream>

using namespace std;

long long extend_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        long long s;
        long long d = extend_gcd(b, a % b, s, x);
        y =s -  a / b * x;
        return d;
    }
}

int main(){
    long long a, b;
    cin >> a >> b;
    
    long long x, y;
    
    long long d = extend_gcd(a,b,x,y);
    cout << x << " " << y << endl;
}
