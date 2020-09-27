#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    int case_num = 0;
    
    while (t--){
        case_num++;
        cout << "Case #" << case_num << ":";
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            a[i] = (a[i] + x - 1) / x;
        }
        
        map<int,vector<int>> mp;
        for (int i = 0; i < n; i++){
            mp[a[i]].emplace_back(i+1);
        }
        
        for (auto p : mp){
            for (int x : p.second){
                cout << " " << x;
            }
        }
        cout << endl;
        
        
    }
    return 0;
    
}
