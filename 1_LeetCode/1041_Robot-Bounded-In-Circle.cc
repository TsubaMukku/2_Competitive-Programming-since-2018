/*
  2020-09-18
  First time
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        int x = 0;
        int y = 0;
        
        int dir = 0;
        
        
        string s = instructions;
        s+= s;
        s+= s;
        int n = (int)s.size();
        
        for (int i = 0; i < n; i++){
            if (s[i] == 'G'){
                if (dir == 0) y++;
                else if (dir == 1) x++;
                else if (dir == 2)y--;
                else x--;
                
            }
            else if (s[i] == 'L'){
                dir += 3;
                dir %= 4;
            }
            else{
                // 'R'
                dir++;
                dir %= 4;
            }
                
        }
        
        if (x == 0 && y == 0) return true;
        else return false;
    }
};


/*
    cited from https://translate.google.com/translate?hl=en&sl=zh-CN&u=https://zxi.mytechroad.com/blog/simulation/leetcode-1041-robot-bounded-in-circle/&prev=search&pto=aue
    for just my personal studying
    
    idea:
    when instructions end, if the robot is back to (0,0) or is not facing north(which guarantees it will come back to the origin for another 1 or 3 round).
    
    // time complexity: O(N)
    // space complexity: O(1)
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        int x = 0;
        int y = 0;
        int d = 0;
        
        vector<int> dx{0,1,0,-1};
        vector<int> dy{-1,0,1,0};
        
        for (char c : instructions){
            if (c == 'G'){
                x += dx[d];
                y += dy[d];
                
            }
            else{
                d = (d + (c == 'L' ? 3 : 1)) % 4;
            }
        }
        
        return x == 0 && y == 0 || d;
    }
};
