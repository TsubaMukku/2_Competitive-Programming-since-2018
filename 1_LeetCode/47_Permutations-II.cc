/*
  Author: Tsubasa Takamuku
  Date: 2020-08-11 11:38
*/

// soution 1: use nextpermutation (with some modifications)
// 順列を小さい方から順番に作る.
// ただし, swapの際に, 同じ値のduplicated numbers同士をswapしないような工夫を付け加える

class Solution {
public:
    // nums = {1,2,3,...n}の順列全てを生成終了したらfalseを返す
    // 順列を生成している途中(すべての順列を作り終えていない)ならばtrueを返す
    bool NextPermutation(vector<int> &nums){
        
        int n = (int)nums.size(), start, next;
        
        // numsの順列のうち, 次に大きいものを作りたい.
        // できる限り末端側の要素を大きくすればよい.
        for (start = n - 2; start >= 0; start--){
            if (nums[start] < nums[start+1]) break;
        }
        
        if (start < 0){
            // {1,2,3....n}のように一番最初の状態に帰ってきた.
            // 全ての順列を作り終えた.
            // 順列生成処理を終了させる.
            reverse(nums.begin(),nums.end());
            return false;
        }
        else{
            // まだ作り終えていない順列が存在する.
            
            // find the smallest nums[next] s.t. 
            // nums[start] < nums[next]
            // nums[start] と　nums[next]を入れ替えた後,
            // start+1の配列の部分をreverseすれば次の順列を得る.
            for (next = n - 1; start < next; next--){
                if (nums[next] > nums[start]) break;
            }
            
            // duplicated numbersが存在しない場合は, 上記のnextの場所を調べる操作が不要である.
            swap(nums[start],nums[next]);
            reverse(nums.begin()+start+1,nums.end());
            return true;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        // 小さい順に1, 2, 3, ...n番目の位置を割り当てる.
        sort(nums.begin(),nums.end());
        
        // 順列を保持する変数resultを用意する.
        vector<vector<int>> result;
        
        // 一番最初の{1,2,3,...n}に対して処理をするために
        // 少なくとも1回は処理が行われるdo while文でループを回す.
        do {
           result.emplace_back(nums);
        } while (NextPermutation(nums));
        
        return result;
    }
};


// solution2: recursion
// 順列を小さい方から順番に作る.
// 0番目の位置に置く要素を一つ決めたら, 1番目~n-1番目までの順列を付け足せば良い -> 再帰的な処理が可能である.


class Solution {
public:
    void permute(vector<int> nums, int start, vector<vector<int>>& res) {
        
        // start == num.size()ならば順列を一つ作り終えている.
        if (start == (int)nums.size()) {
            res.push_back(nums);
        } 
        else {
            
            for (int next = start; next < (int)nums.size(); next++) {
                
                //start == nextでstart番目の数値をいじらない場合を処理する
                //  nums[start] != nums[next]で重複を排除する
                if ( start == next || nums[next] != nums[start]) {
                    
                    swap(nums[start], nums[next]);
                    
                    // start番目に置く要素を決めたら
                    // start+1番目 ~ 末尾の位置までの順列を全て列挙する.
                    permute(nums, start + 1, res);
                }
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        // 順列を小さい方から生成するために 昇順でソートする.
        sort(nums.begin(), nums.end());
        
        // 生成された順列を記録する配列resultを用意する.
        vector<vector<int>> result;
        
        // nums[0]に配置されうるすべての要素(数字の重複を許さない)に対して
        // n-1番目までの残りの数字の配置を全て生成する.
        permute(nums, 0, result);
        
        return result;
    }      
};


