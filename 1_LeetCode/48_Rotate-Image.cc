

// 2020-09-21

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        
        // rotate 90 degrees == (1) mirror && (2) reverse each row
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++) swap(matrix[i][j],matrix[j][i]);
        }
        
        for(int i = 0; i < n; i++) reverse(matrix[i].begin(),matrix[i].end());
    }
};
