

/*
  solution1: bit列とsubsetには1対1対応付けがある (全単射が存在する)
  -> 2ベキの値を全て列挙する.
  -> ビットが立っている場合, subsetの要素として含むことにして, ビットが立っていない場合, 
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // subsetを保持する配列power_setを用意する.
        vector<vector<int>> power_set;
        
        for (int int_for_subset = 0; int_for_subset < (1<<(nums.size())); int_for_subset++ ){
            int bit_array = int_for_subset;
            
            vector<int> subset;
            
            while (bit_array){
                subset.emplace_back(nums[log2(bit_array & ~(bit_array-1))]);
                bit_array &= bit_array-1; // 次のbitへ移動する.
            }
            
            power_set.emplace_back(subset); // 1つのsubsetが完成したから, power_setへ結果を記録する.
            
        } 
        
        return power_set;
        
    }
};
