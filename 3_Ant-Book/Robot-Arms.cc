/*
  区間スケジューリング問題そのままである.
  
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &s, vector<int> &t){
    vector<pair<int,int>> itv(n);
    for (int i = 0; i < n; i++){
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    
    sort(itv.begin(),itv.end());
    
    int ans = 0;
    int last = -1010101017;
    
    for (int i = 0; i < n; i++){
        if (last <= itv[i].second){
            ans++;
            last = itv[i].first;
        }
    }
    return ans;
}


int main(void){
    int n;
    cin >> n;
    
    vector<int> s(n), t(n);
    
    for (int i = 0; i < n; i++){
        int x, l;
        cin >> x >> l;
        
        s[i] = x - l;
        t[i] = x + l;
    }
    
    cout << solve(n,s,t) << endl;
    
}
