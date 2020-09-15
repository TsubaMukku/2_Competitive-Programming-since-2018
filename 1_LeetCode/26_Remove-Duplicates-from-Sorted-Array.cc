class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int slower = 0;
        
        for (int faster = 1; faster < n; faster++){
            if (nums[faster] != nums[slower]){
                slower++;
                nums[slower] = nums[faster];
            }
            
        }
        return slower + 1;
    }
};
