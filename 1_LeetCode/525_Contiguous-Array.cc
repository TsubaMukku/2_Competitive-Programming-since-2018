class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int> mp; // mp[i]: i- iが最後に登場した場所のindex, を保持する
        
        int sum = 0, res = 0;
        int n = (int)nums.size();
        
        for (int i = 0; i < n; i++){
            
            if (nums[i] == 1) sum++;
            else sum--;
            
            if (sum == 0) res = i + 1; // 先頭からスタートして, 0と1の数が等しい -> 間違いなく, 現段階では, これが最長である.
            else if ( mp.count(sum) ){
                // すでにどこか以前に, 同じ部分和の値が得られている
                // 現在地点　- 直前に同じsumの値が出た場所 の距離を計算する
                // これまでのresと比較する
                
                res = max( res, i - mp[sum] );
            }
            else mp[sum] = i;
        }
        
        return res;
    }
};
