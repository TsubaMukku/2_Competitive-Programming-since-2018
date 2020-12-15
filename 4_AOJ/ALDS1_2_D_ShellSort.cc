#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G;
int cnt = 0;

// 間隔gapでinsertion Sortを行う
void insertionSort(vector<int> &a, int n, int gap){
    for (int i = gap; i < n; i++){
        int j = i - gap;
        int v = a[i];
        while (j >= 0 && a[j] > v){
            a[j+gap] = a[j];
            j -= gap;
            cnt++;
        }
        
        a[j+gap] = v;
    }
}

void shellSort(vector<int> &a, int n){
    int h = 1;
    
    // 数列Gを作る
    while (true){
        if (h > n) break;
        G.emplace_back(h);
        h = 3 * h + 1;
    }
    
    // Gの値について降順にinsertion sortを行う
    for (int i = G.size()-1; i >= 0; i--){
        insertionSort(a,n,G[i]);
    }
    
    return;
}

int main(void){
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    shellSort(a,n);
    
    cout << (int)G.size() << endl; // m
    
    // print G[i] 
    for (int i = G.size()-1; i >= 0; i--){
        cout << G[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
    
    cout << cnt << endl;
    
    // print a[i];
    for (int x : a){
        cout << x << endl;
    }
    return 0;

    
}
