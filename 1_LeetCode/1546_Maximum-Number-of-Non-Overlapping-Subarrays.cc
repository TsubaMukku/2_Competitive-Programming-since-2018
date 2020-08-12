/*
    1. prefix_sumのアイデアを利用する.
    2. ただし non-overlappingの処理が必要である.
    3. cumulative_sumを記録していく.
    4. 現在までにcumulative_sum - targetと等しい値が記録されているならば
        cnt++;
        記録されたsumたちを全て消去する <- non-overlappingの処理に対応する
        cumulative_sumとして0を記録する <- 数値一つがtargetに対応する場合への処理である.
        current_sum=0に戻す.
    5. cntを返す
*/

class Solution {
public:
    
    /*
        引数: nums, target
        目的: Return the maximum number of non-empty non-overlapping subarrays satifsying the condition.
        返り値: the maximum number of non-empty non-overlapping subarrays satifsying the condition
    */
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        int n = (int)nums.size();
        
        /*
            現在までに記録されたcumulative_sumの値に定数時間でアクセスしたい(存在の有無を定数時間で調べたい) -> hashmapを利用しよう
        */
        unordered_set<int> ust;
        ust.insert(0);
        int current_sum = 0;
        int number_of_nonoverlapping_subarrays = 0;
        
        for (int i = 0; i < n; i++){
            current_sum += nums[i];
            
            if (ust.count(current_sum - target)){
                number_of_nonoverlapping_subarrays++;
                ust.clear();
                ust.insert(0);
                current_sum = 0;
            }
            else{
                ust.insert(current_sum);
            }
        }
        
        return number_of_nonoverlapping_subarrays;
        
    }
};
