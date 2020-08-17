/*
  解法:
  最小距離を最大化しなさい -> greedy + binary_searchの利用を考えよ(典型アプローチに帰着させる)
  
  1. minimum distance dを決め打つ 0 <= d <= 1e9;
  
  2. xを昇順ソートする(binary searchで探索できるようにするため)
  
  3. solve関数を実行する
  
  4. solve関数の中で用いる, midが有効かどうか判定するチェック関数を実装する
  
  time complexity: O(N log N)
  space complexity: O(N)


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Check (int mid, int n, int m, vector<int> &x){
    
    int last = 0;
    
    for (int i = 1; i < m; i++){
        
        int crt = last + 1;
        
        while  (crt < n && x[crt] - x[last] < mid) crt++;
        
        if (crt == n) return false;
        last = crt;
    }
    
    return true;
}


int Solve(int n, int m, vector<int> &x){
    
    int ok = 0;
    int ng = 1e9 + 7;
    
    while ( abs(ng - ok) > 1){
        int mid = ok + (ng - ok) / 2;
        
        if ( Check(mid,n,m,x) ) ok = mid;
        else ng = mid;
    }
    
    return ok;
}

int main(void){
    int n, m;
    cin >> n >> m;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(),x.end());
    cout << Solve(n,m,x) << endl;
    
}


