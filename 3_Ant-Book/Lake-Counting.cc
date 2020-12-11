/*
  caution on the POJ judgement: https://stackoverflow.com/questions/36346292/compiler-error-non-aggregates-cannot-be-initialized-with-initializer-list
*/

#include <iostream>
#include <vector>

using namespace std;

static const int dx[] = {1,1,0,-1,-1,-1,0,1};
static const int dy[] = {0,1,1,1,0,-1,-1,-1};

//vector<int> dx = {1,1,0,-1,-1,-1,0,1}; この書き方では, POJ上ではうまくコンパイルできなかった
//vector<int> dy = {0,1,1,1,0,-1,-1,-1}; この書き方では, POJ上ではうまくコンパイルできなかった

void dfs(vector<vector<char>> &grid, int n, int m,int x, int y){
    
    grid[x][y] = '.';
    
    for (int k = 0; k < 8; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
        if (grid[nx][ny] == '.') continue;
        
        dfs(grid,n,m,nx,ny);
    }
    
    return;
}

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > grid(n,vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'W'){
                cnt++;
                dfs(grid,n,m,i,j);
            }
        }
    }
    
    cout << cnt << endl;
    
}
