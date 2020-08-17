/*
  solution1: focus on conditions under which rectangles do intersect
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        bool check_width = min(rec1[2],rec2[2]) > max(rec1[0],rec2[0]);
        bool check_height = min(rec1[3],rec2[3]) > max(rec1[1],rec2[1]);
        
        return check_width && check_height;
    }
};
