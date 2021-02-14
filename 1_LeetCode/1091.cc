

// 2021/02/14
class Solution {
private:
    int INF = 1e9;
    vector<int> dx = {1,1,0,-1,-1,-1,0,1};
    vector<int> dy = {0,1,1,1,0,-1,-1,-1};
    
    int bfs(vector<vector<int>> &grid, vector<vector<int>> &d, int n, int sx, int sy, int gx, int gy){
        using P = pair<int,int>;
        queue<P> q;
        q.push(P(sx,sy));
        
        while(q.size()){
            P p = q.front();
            q.pop();
            
            if (p.first == gx && p.second == gy) break;
            
            for(int i = 0; i < 8; i++){
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                
                if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
                if (d[nx][ny] != INF || grid[nx][ny] == 1) continue;
                
                q.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
                
            }
        }
        return d[gx][gy];
    }
    
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; // corner cases
        
        vector<vector<int>> d(n,vector<int>(n,INF));
        d[0][0] = 1;
        int ans = bfs(grid,d,n,0,0,n-1,n-1);
        
        if (ans == INF) return -1;
        else return ans;
    }
};
