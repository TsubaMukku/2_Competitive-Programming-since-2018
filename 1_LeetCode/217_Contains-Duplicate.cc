/*
unordered_map: ハッシュテーブル で実装されている

unordered_map はその名前の通り,要素を順序付けできない
-> 順序付けが必須の場合は map を使う.

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        
        int n = (int)nums.size();
        
        for (int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        
        return (int)st.size() != n;
    }
};
