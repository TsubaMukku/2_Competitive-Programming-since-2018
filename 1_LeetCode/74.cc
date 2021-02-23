

// 2021/02/24
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        
        int i = 0;
        for (int j = 0; j < m; j++){
            if (matrix[i][0] <= target) i++;
            else break;
        }
        
        for (int start = 0; start < i; start++){
            
            int index = lower_bound(matrix[start].begin(),matrix[start].end(),target) - matrix[start].begin();
            
            if (index < n && matrix[start][index] == target) return true;
        }
        
        return false;
    }
};
