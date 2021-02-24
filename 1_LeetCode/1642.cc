

// 2021/02/24
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = (int)heights.size();
        
        priority_queue<int,vector<int>, greater<int>> q;
        
        for (int i = 0; i+1 <= n-1; i++){
            
            int d = heights[i+1]-heights[i];
            
            if (d <= 0) continue;
            
            q.push(d);
            
            if (q.size() <= ladders) continue;
            
            bricks -= q.top();
            q.pop();
            
            if (bricks < 0) return i;
            
        }
        
        return n - 1;
    }
};
