class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int cnt = 0;
        
        for (int num : nums){
            if (num == target) cnt++;
        }
        
        if (cnt > n/2) return true;
        else return false;
    }
};
