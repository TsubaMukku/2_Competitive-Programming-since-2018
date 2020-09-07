class Solution {
private:
    int solve(int x, int y, vector<vector<int>>& A, vector<vector<int>>& B){
        int res = 0;
        
        for (int i = x, row = 0; i < A.size(); i++,row++){
            for (int j = y,col = 0; j < A.size(); j++,col++){
                if ( A[i][j] == 1 && B[row][col] == 1) res++;
            }
        }
        
        return res;
    }
              
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0;
        
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < A.size(); j++){
                res = max( res, solve(i,j,A,B) );
                res = max( res, solve(i,j,B,A) );
            }
        }
        
        return res;
    }
};
