#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n-1; i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
    
    for (int i = 1; i < n; i++){
        int key = a[i];
        
        int j = i-1;
        while (j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        
        for (int i = 0; i < n-1; i++) cout << a[i] << " ";
        cout << a[n-1] << endl;
    }
    return 0;
}
