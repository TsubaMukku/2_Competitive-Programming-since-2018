class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = (int)intervals.size();
        
        if ( n == 0 ) {
            intervals.emplace_back(newInterval);
            return intervals;
        }
        
        if ( intervals[n-1][1] < newInterval[0] ){
            intervals.emplace_back(newInterval);
            return intervals;
        }
        
        vector<vector<int>> res;
        
        int i = 0;
        while (i < n){
            
            // the new interval is after the range of other interval
            if ( intervals[i][1] < newInterval[0] ) res.emplace_back( intervals[i] );
            else{
                
                int first = min( intervals[i][0], newInterval[0] );
                int last = newInterval[1];
                
                // // while new interval overlaps
                while ( i < n && intervals[i][0] <= last ){
                    last = max (intervals[i][1],newInterval[1]);
                    i++;
                }
                vector<int> temp = {first,last};
                res.emplace_back(temp);
                break;
            }
            i++;
        }
        
        // add the rest
        while (i < n){
            res.emplace_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};
