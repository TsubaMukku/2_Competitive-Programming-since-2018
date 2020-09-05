class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        
        for (int i = 0; i < nums.size(); i++){
            
            
            // i - k >= 1
            if (i > k) st.erase( nums[i-k-1] );
            
            if (st.count(nums[i])) return true;
            
            st.insert( nums[i] );
        }
        
        return false;
    }
};




/*

TLE

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n = (int)nums.size();
        
        for (int i = 0; i <= n-1; i++){
            for (int j = i + 1; j <= n-1 && j <= i+k; j++){
                if ( nums[i] == nums[j] ) return true;
            }
        }
        
        return false;
    }
};
