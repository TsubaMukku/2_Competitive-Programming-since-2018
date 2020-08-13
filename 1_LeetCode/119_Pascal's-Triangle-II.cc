/*
  Author: Tsubasa Takamuku
  Date: 2020-08-13
  
  EPI: Chapter5: Arrays: 5.20

*/

/*
  solution1: using math
  -> あるrowにおける, i番目の要素の値と(i+1)番目の要素の値の間に成立する関係式を発見して
  -> i番目の要素の値から, (i+1)番目の要素の値を順次計算してemplace_backすればよい.
  
  time complexity: O(rowIndex)
  space complexity: O(rowIndex)
  
  cf. https://qiita.com/brackss1/items/e92da6458172397f7225
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> nth_pascal_triangle;
        
        nth_pascal_triangle.emplace_back(1);
        
        for (int i = 1; i <= rowIndex; i++){
            
            int n = (int)nth_pascal_triangle.size();
            
            int i_th_element = (long long)(nth_pascal_triangle[n-1]) * (rowIndex - i + 1)
                / i;
            nth_pascal_triangle.emplace_back(i_th_element);
            
        }
        
        return nth_pascal_triangle;
    }
};



/*
  solution2: DP
  
  パスカスの三角形の特定のrowを作り出すために, パスカスの三角形全体を記録する必要はない.
  -> pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]である.
  
  pascal[i][j]: パスカルの三角形において,i番目の行の, j列目の要素を表す (0-index)
  
  1
  1 1
  1 2 1
  1 3 3 1
  1 4 6 4 1
  
  例えば, pascal[4][3] = 4を見ると,
  pascal[4][3] = pascal[3][2] + pascal[3][3]
  となっている.
  つまり, 一つ前の列の, i-1番目までの要素を全て足し合わせたものが, pascal[4][3]の値となっている.
  これを一般化すれば良い.
  
  time complexity: O(rowIndex^{2})
  space complexity: O(rowIndex)
  
  
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans(rowIndex+1, 1);
        
        for (int i = 1; i < rowIndex; i++){
            for (int j = i; j > 0; j--){
                ans[j] += ans[j-1];
            }
        }
        
        return ans;
    }
};

