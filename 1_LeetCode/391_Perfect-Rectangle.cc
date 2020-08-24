class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        set<pair<int,int>> corners;
        int area = 0;
        
        for (auto rectangle : rectangles){
            
            pair<int,int> p1(rectangle[0],rectangle[1]);
            pair<int,int> p2(rectangle[2],rectangle[3]);
            pair<int,int> p3(rectangle[0],rectangle[3]);
            pair<int,int> p4(rectangle[2],rectangle[1]);
            
            for ( auto &p : {p1,p2,p3,p4} ){
                const auto& ret = corners.insert(p);
                if (!ret.second) corners.erase(ret.first);
            }
            
            area += (p2.first - p1.first) * (p2.second - p1.second);
        }
        
        if (corners.size() != 4) return false;
        
        auto &point1 = *begin(corners);
        auto &point2 = *rbegin(corners);
        
        return area == (point2.first - point1.first) * (point2.second - point1.second);
        
    }
};






/*
wrong submission: lacking the consideration on numbers of edge points

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int expected_area = 0;
        int x_max = rectangles[0][2], x_min = rectangles[0][0];
        int y_max = rectangles[0][3], y_min = rectangles[0][1];
        
        int m = (int)rectangles.size();
        
        for (int i = 0; i < m; i++){
            expected_area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
            
            x_max = max(x_max, rectangles[i][2]);
            x_min = min(x_min, rectangles[i][0]);
            y_max = max(y_max, rectangles[i][3]);
            y_min = min(y_min, rectangles[i][1]);
        }
        
        int actual_area = (x_max - x_min) * (y_max - y_min);
        
        if (expected_area == actual_area) return true;
        else return false;
    }
};
*/
