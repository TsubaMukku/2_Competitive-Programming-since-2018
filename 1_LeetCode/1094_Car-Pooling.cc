/*
    imos法っぽいことをやる
    <- なんで思いつく？？？
    <- 慣れ(区間に対するクエリを高速処理したい+ある区間に一定の数値を足し引きしたい -> imosの出番と思う.要するに慣れ)
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passenger(1010);
        int min_pos = 1010,max_pos = 0;
        int n = (int)trips.size();
        
        // calculate the number of passengers in each pos
        for (int i = 0; i < n; i++){
            min_pos = min(min_pos, trips[i][1]);
            max_pos = max(max_pos,trips[i][2]);
            
            passenger[trips[i][1]] += trips[i][0];
            passenger[trips[i][2]] -= trips[i][0];
        }
        
        for (int i = 1; i <= max_pos; i++) passenger[i] += passenger[i-1];
        
        for (int i = min_pos; i <= max_pos; i++){
            if (passenger[i] > capacity) return false;
        }
        
        return true;  
    }
};
