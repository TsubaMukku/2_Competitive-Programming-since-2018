

// 2021/02/17
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = (int)height.size()-1;
        
        while (l < r){
            int area = (r-l)* min(height[l],height[r]);
            ans = max(ans,area);
            
            if (height[l] < height[r]) l++;
            else r--;
        }
        
        return ans;
    }
};
