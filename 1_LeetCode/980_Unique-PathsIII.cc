class Solution {
private:
    int dfs(vector<vector<int>> &grid, int x, int y, int n){
        int numberOfPaths = 0;
        
        if (x < 0 || (int)grid.size() <= x || y < 0 || (int)grid[0].size() <= y) return 0;
        else if (grid[x][y] == -1) return 0;
        else if (grid[x][y] == 2) return n == 0; // n = 1からスタートするのは, スタート地点からの移動を考慮するためである.
        
        grid[x][y] = -1; // visited
        
        numberOfPaths = dfs(grid,x,y+1,n-1) + dfs(grid,x-1,y,n-1) + dfs(grid,x,y-1,n-1) + dfs(grid,x+1,y,n-1);
        
        grid[x][y] = 0; // return its original state 
        return numberOfPaths;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx = -1;
        int sy = -1;
        
        int n = 1;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 0) n++;
                else if (grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
                else continue;
            }
        }
        
        return dfs(grid,sx,sy,n);
    }
};
