




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
