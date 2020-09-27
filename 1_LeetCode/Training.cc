/*
Round A 2019 - Kick Start 2019

The competition season is starting very soon (in fact, the first match has already started!), 
so you'd like to find the minimum number of hours of coaching you need 
to give before you are able to pick a fair team.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    int case_num = 0;
    while (t--){
        case_num++;
        cout << "Case #" << case_num << ": ";
        int n, p;
        cin >> n >> p;
        vector<int> cumulative_sum(n+1,0);
        vector<int> students(n);
        for (int i = 0; i < n; i++) cin >> students[i];
        sort(students.rbegin(),students.rend());
        
        for (int i = 0; i < n; i++){
            cumulative_sum[i+1] = cumulative_sum[i] + students[i];
        }
        
        int res = INT_MAX;
        
        for (int i = 0; i + p <= n; i++){
            int temp = p*students[i] - (cumulative_sum[i+p]-cumulative_sum[i]);
            res = min(res,temp);
        }
        cout << res << endl;
    }
    
    return 0;
}
