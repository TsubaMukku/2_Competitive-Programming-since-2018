/*
固定長の幅の要素だけを対象に最大値と最小値を持っておきたい,
というのが本来の目的ですが,
sliding windowで値を1つ追加して1つ削除する,
という操作を繰り返す必要があるため,
ordered setがあると楽に実装できます

今回は
・random accessが必要ない
・データの追加と削除が, 動的に何度も行われる
・sort列に対するbinary searchを何度も行いたい
という状況下であるため, vectorよりもsetを用いるべきである.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        set<long long> st;
        
        for (int i = 0; i < nums.size(); i++){
            
            if (i > k) st.erase( nums[i-k-1] );
            
            
            // -t <= x - nums[i]
            auto pos = st.lower_bound( (long long)nums[i] - (long long)t );
            
            // x - nums[i] <= t ???
            if (pos != st.end() && (long long)*pos - (long long) nums[i] <= (long long)t ) return true;
            
            st.insert( nums[i] );
        }
        
        // すべての検索に引っかからないということは, 条件を満たさないことを意味する.
        return false;
    }
};
