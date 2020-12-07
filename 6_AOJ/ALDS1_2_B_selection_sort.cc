// 2020/12/07
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int number_of_swap = 0;
    
    for (int i = 0; i < n; i++){
        int mini = i;
        
        for (int j = i; j < n; j++){
            if (a[j] < a[mini]) mini = j;
        }
        if (mini != i){
            swap(a[i],a[mini]);
            number_of_swap++;
        }
    }
    for (int i = 0; i < n; i++){
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << number_of_swap << endl;
    
    
}
