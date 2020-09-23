class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = 0;
        
        for (int num : nums){
            if (candidate == num) cnt++;
            else if (cnt == 0) candidate = num;
            else cnt--;
        }
        
        cnt = 0;
        for (int num : nums){
            if (num == candidate) cnt++;
        }
        
        int n = (int)nums.size();
        if (cnt > n/2) return candidate;
        else return 0;
    }
};
