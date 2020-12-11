#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

bool check(double x, int n, int k, vector<double> &L){
    int num = 0;
    for (int i = 0; i < n; i++){
        num += (int) (L[i] / x);
    }
    return num >= k;
}

double solve(int n, int k, vector<double> &L){
    
    double lb = 0;
    double rb = 1e5+7;
    
    for (int i = 0; i < 100; i++){
        double mid = (lb + rb) / 2;
        
        if ( check(mid,n,k,L) ) lb = mid;
        else rb = mid;
    }
    
    return rb;
}

int main(void){
    int n, k;
    cin >> n >> k;
    
    vector<double> L(n);
    for (int i = 0; i < n; i++) cin >> L[i];
    
    double ans = solve(n,k,L);
    printf("%.2f\n", floor(ans * 100) / 100);
    
}
