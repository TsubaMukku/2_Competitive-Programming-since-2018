/*
  Author: Tsubasa Takamuku
  Date: 2020-08-16
  
  solution 1: greedy + binary_search (writtern in Ant-book p131: Aggressive cows POJ No. 2456)
  最小値を最大化しろ, と言われているから典型中の典型問題である.
  
  C(d): 最も近い2つのballsの間の間隔をd以上とすることができる, か否かを判定する関数とする.
  
  C(d)でtrueとなるようなdの最大値を求めれば良い.
  
  最も近いdistanceがd以上ということは, すべての間隔がd以上である, と言い換えられる.
  -> C(d): 任意の2つのボールの間の間隔をd以上とすることができるか否かを判定する
  となる.
  
  greedyに
  1. positionを昇順ソートする: binary searchを利用するための準備である.
  2. 最初のボールをposition[0]に入れる: 左端はかならず使う. これが最適である.
  3. i番目の牛をpos[j]に入れたら, i+1番目のボールは, pos[j] + d <= pos[k]となる最小のpos[k]にいれる.
  
  time complexity: O( max(m, n) ) = O(n): m <= nより
  space complexity: O(N): vector<int> xを用意したため. inputのpositionを使い回せばspace complexityはO(1)とできる.
  
*/

class Solution {
private:
    const int MAX_N = 1e5;
    int n, m;
    vector<int> x;
    
    // 条件を満たすか否かを判定する
    bool C (int d){
        int last = 0;
        
        for (int i = 1; i < m; i++){
            int crt = last + 1;
            
            while (crt < n && x[crt] - x[last] < d) crt++;
            
            if (crt == n) return false;
            last = crt;
            
        }
        return true;
    }
    
    int solve (){
        
        // positionをソートしておく
        sort(x.begin(),x.begin() + n);
        
        // 解の存在範囲を初期化する
        // lb: 絶対にOK ub:絶対にダメ
        
        int lb = 0, ub = 1e9+7;
        
        while ( ub - lb > 1){
            
            int mid = lb + (ub - lb) / 2;
            
            if ( C(mid) ) lb = mid;
            else ub = mid;
        }
        return lb;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        this->x = position;
        this-> n = (int)position.size();
        this-> m = m;
        return solve();
    }
};
