class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = (int)A.size();
        vector<int> up(n,1);
        vector<int> down(n,1);
        int ans = 1;
        
        for (int i = 1; i < n; i++){
            if (A[i-1] < A[i]) up[i] = down[i-1]  + 1;
            if (A[i] < A[i-1]) down[i] = up[i-1] + 1;
            
            ans = max(ans,max(up[i],down[i]));
        }
        
        return ans;
    }
};
