

// 2021/02/24
class Solution {
private:
    bool binarySearch(vector<vector<int>> &matrix, int target, int start, bool horizontal){
        
        int lo = start-1;
        int hi = horizontal ? (int)matrix[0].size() : (int)matrix.size();
        
        while(abs(hi - lo) > 1){
            
            int mid = (lo + hi) / 2;
            
            // search a column: the row is fixed
            if (horizontal){
                
                if (matrix[start][mid] < target) lo = mid;
                else if (matrix[start][mid] > target) hi = mid;
                else return true;
            }
            else{
                // search a row
                if (matrix[mid][start] < target) lo = mid;
                else if (matrix[mid][start] > target) hi = mid;
                else return true;
                
            }
            
        }
        
        return false;
    }
    
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        
        for (int i = 0; i < min(m,n); i++){
            bool checkVertical = binarySearch(matrix,target,i,false);
            bool checkHorizontal = binarySearch(matrix,target,i,true);
            
            if (checkVertical || checkHorizontal) return true;
        }
        
        
        return false;
    }
};



/*
なぜその解法が思い付かなかったのか
・単調列に対する操作であるから、にぶたんを使うことまでは想起できた
・しかし、「行」「列」それぞれに分割して調査すれば良い、という発想ができなかった

どういう思考が足りなかったのか
・行と列を一度に調べるのではなく、行は行だけ、列は列だけ、と分割して調べることで
時間計算量を削減する、という思考が足りなかった



もし必要とされる思考法が足りていたとしたら解法を思い付けたのか





*/
