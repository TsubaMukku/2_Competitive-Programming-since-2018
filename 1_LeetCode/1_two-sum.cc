class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        unordered_map<int,vector<int>> mp;
        
        for (int i = 0; i < n; i++){
            mp[nums[i]].emplace_back(i);
        }
        
        vector<int> res;
        
        for (int i = 0; i < n; i++){
            
            int temp = target - nums[i];
            
            if (mp.count(temp)){
                for (int p : mp[temp]){
                    if (p == i) continue;
                    res.emplace_back(i);
                    res.emplace_back(p);
                    return res;
                }
            }
        }
        return res;
    }
};
