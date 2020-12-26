
// 2020-12-26
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int m = matrix.size();
        if (m == 0) return ans;
        
        int n = matrix[0].size();
        
        for (int i = 0; i < m + n -1; i++){
            int row = i < n ? 0 : i - n + 1;
            int col = i < n ? i : n - 1;
            
            vector<int> temp;
            
            while (row < m && col >= 0){
                temp.emplace_back(matrix[row][col]);
                row++;
                col--;
            }
            
            if (i % 2 == 0) reverse(temp.begin(),temp.end());
            
            for (auto x : temp) ans.emplace_back(x);
        }
        return ans;
        
    }
};

// 2020-12-25
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        
        int m = (int)matrix.size(); // たて
        int n = (int)matrix[0].size(); // よこ
        
        for (int i = 0; i <= m + n -2; i++){
            
            int row = i < n ? 0 : i - n + 1;
            int col = i < n ? i : n - 1;
            
            vector<int> temp;
            
            while (row <= m-1 && col >= 0){
                temp.emplace_back(matrix[row][col]);
                row++;
                col--;
            }
            
            if (i % 2 == 0) reverse(temp.begin(),temp.end());
            
            for (auto x : temp) ans.emplace_back(x);
        }
        
        return ans;
        
    }
};
