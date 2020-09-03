class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        set<long long> window; 
        
        for (int i = 0; i < nums.size(); i++){
            
            // keep the set containing nums i & j at most distance k
            if (i > k) window.erase( nums[i-k-1] );
            
            // -t <= x - nums[i]  <= t;
            // nums[i] - t <= x -> -t <= x - nums[i] 
            auto pos = window.lower_bound( (long long)nums[i] - (long long)t);
            
            // x - nums[i] <= tか否かをチェックすれば良い
            if (pos != window.end() && (long long)*pos - (long long)nums[i] <= (long long)t) return true;
            
            window.insert( nums[i] );
        }
        
        return false;
    }
};
