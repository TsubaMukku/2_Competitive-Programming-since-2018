

// 2021/02/22

lass Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0;
        
        int n = (int)A.size();
        
        for (int i = 0; i <= n-3; i++){
            int d = A[i+1] - A[i];
            
            for (int j = i + 2; j <= n - 1; j++){
                if (A[j]-A[j-1] == d) cnt++;
                else break;
            }
        }
        
        return cnt;
    }
};
