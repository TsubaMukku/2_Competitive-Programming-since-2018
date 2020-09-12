// reference: https://translate.google.com/translate?hl=en&sl=zh-CN&u=https://zxi.mytechroad.com/blog/algorithms/array/leetcode-697-degree-of-an-array/&prev=search&pto=aue

class Solution {
public:
  int findShortestSubArray(vector<int>& nums) {
      
    unordered_map<int, vector<int>> indices;
      
    for (int i = 0; i < nums.size(); ++i) indices[nums[i]].push_back(i);
    size_t degree = 0;
      
    for (const auto& p : indices) degree = max(degree, p.second.size());
    int ans = nums.size();
      
    for (const auto& p : indices) {
      if (p.second.size() != degree) continue;
        
      int m = (int)p.second.size();
      ans = min(ans,p.second[m-1] - p.second[0] + 1);
        
    }
    return ans;
      
  }
};
