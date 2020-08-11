class Solution {
public:
    void DirectedPermutations(int i, vector<int> &nums, vector<vector<int>> &result){
        
        if (i == (int)nums.size() - 1){
            result.emplace_back(nums);
            return;
        }
        
        for (int j = i; j < (int)nums.size(); j++){
            swap(nums[i],nums[j]);
            DirectedPermutations(i+1,nums,result);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        DirectedPermutations(0, nums,result);
        return result;
    }
};

