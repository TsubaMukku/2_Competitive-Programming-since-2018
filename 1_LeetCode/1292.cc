

// 2021/02/24

/*
Given a m x n matrix mat and an integer threshold. Return the maximum side-length of a square with a sum less than or equal to threshold 
or return 0 if there is no such square.
https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

*/
class Solution {
private:
    int rangeSum(int x, int y, int z, int w, vector<vector<int>> &S){
        return S[z][w] - S[z][y] - S[x][w] + S[x][y];
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        // 累積和を用いる典型的な状況である
        // square内のsumを高速に求めたい + 似たようなクエリを何度も処理する
        
        const int m = (int)mat.size();
        const int n = (int)mat[0].size();
        
        
        // S[h][c]: [0,h) * [0,c)の領域のsumを表す
        vector<vector<int>> S(m+1,vector<int>(n+1));
        
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        int ans = 0; //  the maximum side-length of a square with a sum less than or equal to threshold
        
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                
                // side-lengthを広げてみる
                for (int k = ans; i + k <= m && j + k <= n; k++){
                    if (rangeSum(i,j,i+k,j+k,S) > threshold) break;
                    ans = max(ans,k+1);
                }
                
            }
        }
        return ans;
        
    }
};


/*

WA:
an input example:
[[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]]
threshold: 1

my output: 1

expected output: 0


*/

