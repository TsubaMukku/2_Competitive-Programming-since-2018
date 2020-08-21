

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = (int)A.size();
        
        if (n == 1)　return A;
        
        int index_odd = 0;
        int index_even = n-1;
        
        while (index_odd < n && 0 <= index_even ){
            
            while (index_odd < n && A[index_odd] % 2 == 0) index_odd++;
            while (index_even >= 0 && A[index_even] % 2 == 1) index_even--;
            
            if (index_odd > index_even) break;
            
            swap(A[index_odd],A[index_even]);
        }
        
        return A;
    }
};
