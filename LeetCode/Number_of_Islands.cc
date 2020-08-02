/**
 *    author:  Tsubasa Takamuku
 *    created: 2020-08-02　10:43   
 *    ref: (1) Arihon pp35 Lake Counting(POJ 2386)
**/



class Solution {
private:
    int cnt = 0;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    
public:
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n){
        
        using P = pair<int,int>;
        grid[x][y] = '0';
        
        stack<P> st;
        st.push(make_pair(x,y));
        
        while (st.size()){
            P p = st.top();
            st.pop();
            
            for (int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx < 0 || m <= nx || ny < 0 || n <= ny) continue;
                if (grid[nx][ny] == '1') dfs(grid,nx,ny,m,n);
            }
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1') {
                    dfs(grid,i,j,m,n);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
