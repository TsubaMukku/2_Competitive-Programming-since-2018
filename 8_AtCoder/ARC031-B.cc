/*
    解法例:
        1. 埋め立てる候補の点を全探索する -> 実際に一つ埋め立ててみる
        2. 1つの島になっているか否かを判定する
        3. ある地点から出発してdfsで到達できる点の一覧 == gridの状態となっているか？？
        4. yes -> 答えはYES  全ての点に対して上記が成立しないならば　答えはNOである.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

// 盤面を埋める
void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visit, int x, int y){
    
    visit[x][y] = true;
    
    for (int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if (nx < 0 || 10 <= nx || ny < 0 ||10 <= ny) continue;
        if (visit[nx][ny]) continue;
        if (grid[nx][ny] == 'x') continue;
        
        dfs(grid,visit,nx,ny);
    }
    
    return;
    
}

bool check(vector<vector<char>> &grid){
    
    // まっさらな配列を用意する.
    // ある地点からのdfsで到達できる点はtrue, otherwise false;
    vector<vector<bool>> visit(10,vector<bool>(10));
    int x, y;
    
    // dfsにより探索を始めるスタート地点をとにかく一つ見つける.
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if ( grid[i][j] == 'o') {
                x = i, y = j;
                break;
            }
        }
    }
    
    // (x,y)より地続きで行ける箇所を全てtrueにする.
    dfs(grid,visit,x,y);
    
    // 現在のgridの状態 == (x,y)より地続きで行ける盤面の状態であるならば 答えはtrue
    // そうでなければ答えはfalseである.
    
    bool ok = true;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if ( grid[i][j] == 'o' && !visit[i][j] ){
                ok = false;
                break;
            }
        }
    }
    
    return ok;
}

int main(void){
    
    vector<vector<char>> grid(10,vector<char>(10));
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) cin >> grid[i][j];
    }
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            
            if (grid[i][j] == 'o') continue;
            
            grid[i][j] = 'o';
            
            if ( check(grid) ){
                cout << "YES" << endl;
                return 0;
            }
            
            grid[i][j] = 'x';
        }
    }
    
    cout << "NO" << endl;
    return 0;
    
}
