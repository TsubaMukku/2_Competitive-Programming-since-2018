#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(int n, vector<char> &s){
    int a = 0;
    int b = n-1;
    string ans = "";
    while (a <= b){
        
        bool left = false;
        
        for (int i = 0;  a + i <= b; i++){
            if (s[a+i] < s[b-i]){
                left = true;
                break;
            }
            else if (s[a+i] > s[b-i]){
                left = false;
                break;
            }
        }
        
        if (left){
            ans += s[a];
            a++;
        }
        else{
            ans += s[b];
            b--;
        }
    }
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    
    vector<char> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    
    string ans = solve(n,s);
    
    int m = ans.size();
    
    for (int i = 0; i < m; i+=80){
        for (int j = 0; j < 80 && i + j < m; j++){
            cout << ans[i+j];
        }
        cout << endl;
    }
    
}
