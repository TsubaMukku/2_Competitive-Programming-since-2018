


// 2020-09-21

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int row = 0; row < numRows; row++){
            vector<int> temp(row+1);
            temp[0] = 1;
            
            if (row >= 1) temp[row] = 1;
            
            for (int j = 1; j <= row-1; j++) temp[j] = res[row-1][j-1] + res[row-1][j];
            
            res.emplace_back(temp);
        }
        
        return res;
    }
};
